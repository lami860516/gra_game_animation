#include <windows.h>
#include <gl/gl.h>
#include <cmath>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include "all.hpp"
#include <windows.h>
#define MAX_CHAR        128
bool isMenu,isFight,isWalk,isSleep,isHole,isMirror,isRain,isNoFace,isHouse,isLast,isLetter,isThank;
bool isWantToForest=false,isRained=false,isFighted=false,isFaced=false,isPopoSay=false;
int p3OffsetX;
dragonCat DC;
p3 P3;
fight Fight;
LookMirror Mirror;
noFace NoFace;
void drawString(const char* str) {
    static int isFirstCall = 1;
    static GLuint lists;
    if( isFirstCall ) { 
         isFirstCall = 0;
         lists = glGenLists(MAX_CHAR);
         wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
     }
    for(; *str!='\0'; ++str)
         glCallList(lists + *str);
}
void drawCNString(const char* str) {
    int len, i;
    wchar_t* wstring;
    HDC hDC = wglGetCurrentDC();
    GLuint list = glGenLists(1);
    len = 0;
    for(i=0; str[i]!='\0'; ++i)
    {
        if( IsDBCSLeadByte(str[i]) )
            ++i;
        ++len;
    }
    wstring = (wchar_t*)malloc((len+1) * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
    wstring[len] = L'\0';
    for(i=0; i<len; ++i)
    {
        wglUseFontBitmapsW(hDC, wstring[i], 1, list);
        glCallList(list);
    }
    free(wstring);
    glDeleteLists(list, 1);
}
void selectFont(int size, int charset, const char* face) {
    HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
        charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
    HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
    DeleteObject(hOldFont);
}
void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);  
	gluOrtho2D (0, 1600, 0, 900);
}
void gameStart(void){
	glClear (GL_COLOR_BUFFER_BIT);
	DC.init();
	menuQAQ Menu;
	isMenu=true;
	isFight=false;
	isWalk=false;
	isSleep=false;
	isHole=false;
	isMirror=false;
	isRain=false;
	isNoFace=false;
	isHouse=false;
	isLast=false;
	isLetter=false;
	Menu.draw();
	PlaySound("menu.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	glColor3f(0.75, 0.4, 0.02);
	selectFont(50, DEFAULT_CHARSET, "YouYuan");
    glRasterPos2f(120, 635);
    drawCNString(" 龍貓 跑跑跑");
	glFlush ( );
	/* 
	selectFont(48, DEFAULT_CHARSET, "YouYuan");
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2f(710, 505);
    drawCNString("傳統的中國漢字");
	glFlush ( );*/
}
void myKey(unsigned char key, int x, int y){ 
	if(isFight){
		if(Fight.isFighting){
			switch(key){
			   	case ' ':
				   	if(Fight.isFighting&&Fight.talkIndex==4){
				   		isFighted=true;isFight=false;DC.isUmbrella=false;DC.isFish=true;
				   		P3.draw(p3OffsetX);
				   		DC.print();	
						glColor4f (0.764,0.764,0.764,0.8);
						glRectf(1300,10,1595,40);
						glColor3f(0,0,0);
						selectFont(15, DEFAULT_CHARSET, "YouYuan");
					    glRasterPos2f(1350, 15);
					    drawCNString("  .....好吃 ");
					    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
						glFlush ( );
				   	}
			   		if(Fight.isFighting&&Fight.talkIndex<4){
						Fight.drawBackGround();
				    	Fight.drawCarpKing();
				    	DC.isOne=!DC.isOne;
				    	DC.isLastRight=true;
				    	glPushMatrix ();
				    	glTranslatef(-300,100,0);
						DC.print();	
						glPopMatrix(); 
						glPushMatrix ();
						Fight.drawDialog();
						Fight.selectFont(30, DEFAULT_CHARSET, "YouYuan");
					    glColor3f(1,1,1);
					    glRasterPos2f(100,160);
					    Fight.drawCNString(Fight.talk[Fight.talkIndex]);
						if(Fight.talkIndex>=2)
							Fight.drawRightDialog();
						glFlush ( );
						Fight.talkIndex++;
					}		
	   				break;
		   
	   		}
		}
	}else if(isWalk){
		switch(key){
	   	case 'u':
	   		DC.isUmbrella=true;
	   		P3.draw(p3OffsetX);
	   		DC.print();
	   		break;
	   	case ' ':
	   		if(p3OffsetX==-1200)
	   			PlaySound("40_1.wav", NULL, SND_ASYNC|SND_FILENAME);
	   		if(p3OffsetX<=-5130&&p3OffsetX>=-5400){
	   			if(!isHouse&&!isFaced){
	   				isHouse=true;
		   			P3.drawHouse();
		   			glColor4f (0.764,0.764,0.764,0.8);
					glRectf(1300,10,1595,40);
					glColor3f(0,0,0);
					selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(1350, 15);
				    drawCNString("  好大的房子 ");
				    glFlush ( );
	   			}else if(isHouse&&!isNoFace&&!isFaced){
	   				PlaySound("door.wav", NULL, SND_ASYNC|SND_FILENAME);
					glColor4f (0.764,0.764,0.764,0.8);
					glRectf(1330,10,1595,40);
					glColor3f(0,0,0);
					selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(1330, 15);
				    drawCNString("  開門看看好了 ");
				    glFlush ( );
				    isNoFace=true;
	   			}else if(NoFace.isShow&&isNoFace&&!isPopoSay){
	   				isPopoSay=true;
	   			}else if(NoFace.isShow&&isNoFace&&isPopoSay){
					isNoFace=false;isFaced=true;
					P3.draw(p3OffsetX);
					DC.print();
					glColor4f (0.764,0.764,0.764,0.8);
					glRectf(820,10,1595,40);
					glColor3f(0,0,0);
					selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(840, 15);
				    drawCNString(" 那個婆婆說會幫我把時間往前移兩個小時，是真的嗎 ");
			    	glFlush ( );
				} else if(isNoFace||isFaced){
					NoFace.draw();
					isNoFace=true;
					NoFace.noFaceNum++;
				}
	   		}
	   		
	   		
	   		break;
   		}
	}else if(isSleep){
		switch(key){
	   	case ' ':
	   		PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	   		P3.isWake=true;
			P3.sleepTime=5000;
	   		break;
   		}
	}else if(isHole){
		switch(key){
	   	case ' ':
			if(p3OffsetX>=-600&&p3OffsetX<=-400){
				isLetter=true;
				P3.card();
				PlaySound("letter.wav", NULL, SND_ASYNC|SND_FILENAME);
				glColor3f (1, 0.41, 0.591);//字 
				selectFont(35, DEFAULT_CHARSET, "Comic Sans MS");
			    glRasterPos2f(753, 900-549);
			    drawCNString(" LET'S");
			    selectFont(35, DEFAULT_CHARSET, "Comic Sans MS");
			    glRasterPos2f(739, 900-608);
			    drawCNString(" PARTY!");
			    glColor3f (1, 0.61, 0.191);
			    selectFont(18, DEFAULT_CHARSET, "YouYuan");
			    glRasterPos2f(690, 900-700);
			    drawCNString(" 小梅的生日宴會");
			    selectFont(18, DEFAULT_CHARSET, "YouYuan");
			    glRasterPos2f(485, 900-757);
			    drawCNString(" 一月十五號晚上九點 在森林裡的小棕屋舉辦");
			    glColor4f (0.764,0.764,0.764,0.8);
				glRectf(1300,10,1595,40);
				glColor3f(0,0,0);
				selectFont(15, DEFAULT_CHARSET, "YouYuan");
			    glRasterPos2f(1320, 15);
			    drawCNString("  已經十一點了!!! ");
			    
			    glFlush ( );
			    isLetter=false;
			}
			if(p3OffsetX>=480&&p3OffsetX<=660){
				isMirror=true;
				Mirror.draw();
			}
			if(isMirror&&Mirror.smileNum>=3){
				isMirror=false;
				Mirror.smileNum=1;
				Mirror.smileTime=0;
				P3.drawHole();
				glPushMatrix ();
				glTranslatef(p3OffsetX,0,0);
				DC.print();
				glPopMatrix(); 
				glPushMatrix ();
			} 
			if(isWantToForest){
				isHole=false;
				isWalk=true;
				p3OffsetX=0;
	    		P3.draw(p3OffsetX);
	    		glPopMatrix(); 
				glPushMatrix ();
				DC.print();
			}	
				
			
	   	break;
   		}
	}
   
}
void SpecialKey(GLint key,GLint x,GLint y){  
	if(!isLast){
		if(isFight){
			if(Fight.isFighting&&Fight.talkIndex==3){
				switch(key){
					case GLUT_KEY_UP:
					Fight.curY=Fight.curYU;
					break;	
					case GLUT_KEY_DOWN:
					Fight.curY=Fight.curYD;
					break;
					case GLUT_KEY_LEFT:
					Fight.curX=Fight.curXL;
					break;
					case GLUT_KEY_RIGHT:
					Fight.curX=Fight.curXR;
					break;
				}
				Fight.talkIndex=3;
				Fight.drawRightDialog();
				glFlush ( );
			}
		}else if(isWalk){
			if(isRain){
				P3.raining(p3OffsetX);
			}
			switch(key){
				case GLUT_KEY_UP:
					P3.draw(p3OffsetX);
					DC.eye[1][1]+=5;
					DC.print();
				break;	
				case GLUT_KEY_DOWN:
					P3.draw(p3OffsetX);
					DC.eye[1][1]-=5;
					DC.print();
				break;
				case GLUT_KEY_LEFT:
					if(p3OffsetX==0){
						P3.draw(p3OffsetX);
						DC.pushLeft();
						glColor4f (0.764,0.764,0.764,0.8);
						glRectf(1230,10,1595,40);
						glColor3f(0,0,0);
						selectFont(15, DEFAULT_CHARSET, "YouYuan");
					    glRasterPos2f(1250, 15);
					    drawCNString("  去看看他們還在不在吧 ");
						glFlush ( );
					}else{
						p3OffsetX+=30;
						P3.draw(p3OffsetX);
						DC.pushLeft();
					}
					
				break;
				case GLUT_KEY_RIGHT:
						if(p3OffsetX<=-4700&&!isFighted&&!isFight&&isRained){
							glColor4f (0.764,0.764,0.764,0.8);
							glRectf(1300,10,1595,40);
							glColor3f(0,0,0);
							selectFont(15, DEFAULT_CHARSET, "YouYuan");
						    glRasterPos2f(1350, 15);
						    drawCNString("  !!!!!!!! ");
							glFlush ( );
							Fight.isFightStartFinish=false;
							isFight=true;
							Fight.isFighting=false;
							Fight.MyTime=0;
							PlaySound("fight.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
						}
						if(DC.isUmbrella&&p3OffsetX<=-4000&&!isRained&&isRain){
							isRain=false;isRained=true;
							PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
						}
						if(p3OffsetX<=-2500&&!isRained&&!isRain){
							PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
							isRain=true;
							P3.draw(p3OffsetX);
							DC.eye[1][1]+=5;
							DC.print();
						}else if(p3OffsetX<=-6370&&!isFaced){
							P3.draw(p3OffsetX);
							DC.pushRight();
							glColor4f (0.764,0.764,0.764,0.8);
							glRectf(1100,10,1595,40);
							glColor3f(0,0,0);
							selectFont(15, DEFAULT_CHARSET, "YouYuan");
						    glRasterPos2f(1110, 15);
						    drawCNString(" 果然，晚了兩個小時大家都不在了 ");
							glFlush ( );
						}/*else if(p3OffsetX<=-5430&&!isFaced){
							
							P3.draw(p3OffsetX);
							DC.pushRight();
							glColor4f (0.764,0.764,0.764,0.8);
							glRectf(1300,10,1595,40);
							glColor3f(0,0,0);
							selectFont(15, DEFAULT_CHARSET, "YouYuan");
						    glRasterPos2f(1310, 15);
						    drawCNString(" 作者拜託你先走岔路 ");
							glFlush ( );
						}*/else{
							p3OffsetX-=30;
							P3.draw(p3OffsetX);
							DC.pushRight();
						}
					
					if(p3OffsetX<=-5800&&isFaced){
						PlaySound("birthday.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
						isLast=true;
						P3.isEnd=true;
						isWalk=false;
					}
				break;
				
			}
			
		}else if(isHole){
			switch(key){
				case GLUT_KEY_UP:
					P3.drawHole();
					DC.eye[1][1]+=5;
					glPushMatrix ();
					glTranslatef(p3OffsetX,0,0);
					DC.print();
					glPopMatrix(); 
					glPushMatrix ();
					isWantToForest=false;
				break;	
				case GLUT_KEY_DOWN:
					P3.drawHole();
					DC.eye[1][1]-=5;
					glPushMatrix ();
					glTranslatef(p3OffsetX,0,0);
					DC.print();
					glPopMatrix(); 
					glPushMatrix ();
					isWantToForest=false;
				break;
				case GLUT_KEY_LEFT:
					p3OffsetX-=30;
					P3.drawHole();
					glPushMatrix ();
					glTranslatef(p3OffsetX,0,0);
					DC.pushLeft();
					glPopMatrix(); 
					glPushMatrix ();
					isWantToForest=false;
				break;
				case GLUT_KEY_RIGHT:
					p3OffsetX+=30;
					P3.drawHole();
					glPushMatrix ();
					glTranslatef(p3OffsetX,0,0);
					DC.pushRight();
					glPopMatrix(); 
					glPushMatrix ();
					isWantToForest=false;
					if(p3OffsetX/30>=24){
						glColor4f (0.764,0.764,0.764,0.5);
						glRectf(1300,10,1595,40);
						glColor3f(0,0,0);
						selectFont(15, DEFAULT_CHARSET, "YouYuan");
					    glRasterPos2f(1350, 15);
					    drawCNString("  確定要出去? ");
						glFlush ( );
						isWantToForest=true;
					}
				break;
			}
		}
	}
}  
void myMouse (int touch, int state, int x, int y){
	float nowX=x*2;
	float nowY=900-y*2;
	if(isMenu){
		if(touch == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    	{
	    	glClear (GL_COLOR_BUFFER_BIT);
	    	//click START
	    	if(190<nowX && nowX<700 && 900-490<nowY && nowY<900-370)
	    	{
	    		isMenu=false;
	    		isSleep=true;
				P3.sleepTime=0;
	    		P3.drawSleep();
	    		PlaySound("sleep.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	    		/*
	    		p3OffsetX=0;
	    		P3.draw(p3OffsetX);
	    		glPopMatrix(); 
				glPushMatrix ();
				DC.print();*/
	    	}
			
			//click EXIT
	    	if(190<nowX && nowX<700 && 900-678<nowY && nowY<900-558)
	    	{
	    		exit(0);
	    	}
   	 	}
	}
}
void myidle()  {  
	if(isFight){
		Fight.MyTime+=3;  
		//測試用 
		//Fight.MyTime=2250;
	    if(Fight.MyTime>=2100&&Fight.isFightStartFinish==false){
	    	Fight.isFightStartFinish=true;
	    	Fight.isFighting=true;
	    	Fight.drawBackGround();
	    	Fight.drawCarpKing();
	    	DC.isLastRight=true;
			Fight.drawDialog();
			Fight.selectFont(30, DEFAULT_CHARSET, "YouYuan");
		    glColor3f(1,1,1);
		    glRasterPos2f(100,160);
		    Fight.drawCNString(Fight.talk[Fight.talkIndex]);
			glFlush ( );
			Fight.talkIndex++;
	    }else if(!Fight.isFightStartFinish)
	    	Fight.start();
	}else if(isSleep){
		P3.sleepTime++;
		P3.drawSleep();
		if(P3.eyeTime==4){
			isSleep=false;
			isHole=true;
			p3OffsetX=0;
			P3.drawHole();
			glPushMatrix ();
			glTranslatef(p3OffsetX,0,0);
			DC.print();
			glPopMatrix(); 
			glPushMatrix ();
		}
			
	}else if(isMirror){
		Mirror.smileTime+=2;
		if(Mirror.smileTime/100>500000){
			Mirror.smileTime=0;
			Mirror.smileNum++;
			Mirror.draw();
		}
			
	}else if(isRain){
		if(!DC.isUmbrella){
			if(p3OffsetX>=-3200){
				p3OffsetX-=60;
				P3.draw(p3OffsetX);
				DC.pushRight();
				P3.raining(p3OffsetX);
				glColor4f (0.764,0.764,0.764,0.5);
				glRectf(1300,10,1595,40);
				glColor3f(0,0,0);
				selectFont(15, DEFAULT_CHARSET, "YouYuan");
			    glRasterPos2f(1350, 15);
			    drawCNString("  在下雨啊! ");
				glFlush ( );
			}else if(p3OffsetX<=-3800){
				p3OffsetX+=60;
				P3.draw(p3OffsetX);
				DC.pushLeft();
				P3.raining(p3OffsetX);
				glColor4f (0.764,0.764,0.764,0.5);
				glRectf(1300,10,1595,40);
				glColor3f(0,0,0);
				selectFont(15, DEFAULT_CHARSET, "YouYuan");
			    glRasterPos2f(1350, 15);
			    drawCNString("  在下雨啊! ");
				glFlush ( );
			}
		}
		
			
		
	}else if(isNoFace){
		if(NoFace.noFaceNum!=0){
			NoFace.noFaceTime+=2;
			if(NoFace.noFaceTime/100>500000){
				NoFace.noFaceTime=0;
				NoFace.noFaceNum=NoFace.noFaceNum%2+1;
				NoFace.draw();
				if(isPopoSay){
					glColor4f (0.764,0.764,0.764,0.5);
					glRectf(1300,10,1595,40);
					glColor3f(0,0,0);
					selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(1350, 15);
				    drawCNString("  請問你是?");
				    
				    glColor3f(0.4706, 0.4, 0.3725);
				    glBegin(GL_POLYGON);
						glVertex2f(880,900-380);glVertex2f(880,900-420);glVertex2f(945,900-400);
				    glEnd();
					glRectf(511,900-250	,891,900-495);
					glColor3f(1,1,1);
					selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(515, 900-316);
				    drawCNString("  我是錢婆婆 ");
				    selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(515, 900-384);
				    drawCNString("  我知道你錯過生日會了 ");
				    selectFont(15, DEFAULT_CHARSET, "YouYuan");
				    glRasterPos2f(515, 900-453);
				    drawCNString("  幫你調了時間，去吧。 ");
					glFlush ( );
					glFlush ( );
				}
				glColor4f (0.764,0.764,0.764,0.5);
				
			}
		}
	}else if(isLast){
		if(P3.lastNum<=6){
			P3.lastTime+=3;
			if(P3.lastTime/100>500000){
				P3.draw(-5800-100*P3.lastNum);
				glPushMatrix ();
				glTranslatef(-100*P3.lastNum,0,0);
				DC.isOne=false;
				DC.print();
				glPopMatrix(); 
				glPushMatrix ();
				P3.lastTime=0;
				P3.lastNum++;
			}
		}else{
			isLast=false;
			isThank=true;
			
		}
	}else if(isThank){
		if(P3.thankNum<=(1000+80*P3.thankSize)){
			P3.thankTime+=3;
			if(P3.thankTime/100>500000){
				P3.draw(-6400);
				glPushMatrix ();
				glTranslatef(-600,0,0);
				DC.isOne=false;
				DC.print();
				glPopMatrix(); 
				glPushMatrix ();
				P3.drawThank(); 
				P3.thankNum+=30;
				P3.thankTime=0;
			}
		}else{
			exit(0);
		}
	}
	
} 
int main (int argc, char** argv){
	glutInit (&argc, argv);                        
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowPosition (50, 100);  
	glutInitWindowSize (800, 450);      
	glutCreateWindow ("B0429017");    
	glutKeyboardFunc(myKey);
	glutSpecialFunc(&SpecialKey); 
	init ( );         
	glutDisplayFunc (gameStart); 
	glutMouseFunc(myMouse);
	glutIdleFunc(myidle);
	glutMainLoop ( );              

}
