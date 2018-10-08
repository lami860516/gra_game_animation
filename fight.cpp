#include <windows.h>
#include <gl/gl.h>
#include <cmath>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include <windows.h>
#define MAX_CHAR        128
#include "all.hpp"
void fight::circle(int x,int y,float r,int style,int N,int angle){
	glBegin(style);
	float R=r;
	int n=N;
	for (int i = 0; i < n; i++)
		glVertex2f(x+R*cos( M_PI*i / 180+(angle*M_PI/180)), y+R*sin(M_PI*i / 180+(angle*M_PI/180)));//­pºâ§¤¼Ð
    glEnd ( );
}
void fight::drawString(const char* str) {
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
void fight::drawCNString(const char* str) {
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
void fight::selectFont(int size, int charset, const char* face) {
    HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
        charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
    HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
    DeleteObject(hOldFont);
}
void fight::ctcircle(int x,int y ,float R,float c,int style){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(style);
     for(int i=0; i<n; ++i)
     {	//glVertex2f(x+R*cos( M_PI*i / 180+(angle*M_PI/180)), y+R*sin(M_PI*i / 180+(angle*M_PI/180)));
         glVertex2f(x+c*R*cos(2*Pi/n*i), y+R*sin(2*Pi/n*i));
     }
	glEnd();}
void fight::start(){
	
		glClear (GL_COLOR_BUFFER_BIT);
		glColor3f (0.10, 0.04, 0.31);
		glBegin(GL_POLYGON);
			glVertex2f(0,0);glVertex2f(0,900);glVertex2f(1600,900);glVertex2f(1600,0);
		glEnd ( );
		selectFont(48, DEFAULT_CHARSET, "YouYuan");
	    glColor3f(1,1,0);
	    glRasterPos2f(300,400);
	    drawCNString("!!!!!!!!!!!!!!!!!!!!!!");
		glColor3f (0,0,0);
		glPushMatrix ();
		glTranslatef(0,MyTime/2,0);
		glBegin(GL_POLYGON);
			glVertex2f(0,450);glVertex2f(0,900);glVertex2f(1600,900);glVertex2f(1600,450);
		glEnd ( );
		glPopMatrix(); 
		glPushMatrix ();
		glTranslatef(0,-MyTime/2,0);
		glBegin(GL_POLYGON);
			glVertex2f(0,0);glVertex2f(0,450);glVertex2f(1600,450);glVertex2f(1600,0);
		glEnd ( );
		glPopMatrix(); 
		glFlush ( );
	
}
void fight::drawBackGround(){
	glClear (GL_COLOR_BUFFER_BIT);
	glLineWidth(0.001f); 
	glColor3f (0.255,0.625,0.847);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);glVertex2f(0,900);glVertex2f(1600,900);glVertex2f(1600,0);
	glEnd ( );
	glColor3f (0.10, 0.04, 0.31);
	glBegin(GL_POLYGON);
		glVertex2f(0,900-187);glVertex2f(0,900);glVertex2f(1600,900);glVertex2f(1600,900-209);
	glEnd ( );
	glColor3f (0.25,0.686,0.851);
	glBegin(GL_POLYGON);
		glVertex2f(-20,900-268);glVertex2f(1600,900-280);glVertex2f(1600,900-245);glVertex2f(1400,900-270);glVertex2f(1100,900-320);glVertex2f(900,900-350);
		glVertex2f(700,900-350);glVertex2f(500,900-330);glVertex2f(200,900-330);glVertex2f(-100,900-270);
	glEnd ( );
	glBegin(GL_POLYGON);
		glVertex2f(-20,900-668);glVertex2f(300,900-690);glVertex2f(700,900-600);glVertex2f(1000,900-680);glVertex2f(1300,900-620);glVertex2f(1600,900-580);glVertex2f(1600,900-445);glVertex2f(1300,900-470);glVertex2f(1100,900-420);glVertex2f(900,900-450);
		glVertex2f(700,900-450);glVertex2f(500,900-430);glVertex2f(200,900-430);glVertex2f(0,900-470);
	glEnd ( );
	glBegin(GL_POLYGON);
		glVertex2f(-20,900-668);glVertex2f(300,900-690);glVertex2f(700,900-600);glVertex2f(1000,900-680);glVertex2f(1300,900-620);glVertex2f(1600,900-580);glVertex2f(1600,900-445);glVertex2f(1300,900-470);glVertex2f(1100,900-420);glVertex2f(900,900-450);
		glVertex2f(700,900-450);glVertex2f(500,900-430);glVertex2f(200,900-430);glVertex2f(0,900-470);
	glEnd ( );
	glColor3f (0.098,0.56,0.729);
	glBegin(GL_POLYGON);
		glVertex2f(80+100,900-450+150);glVertex2f(50+100,900-468+150);glVertex2f(70+100,900-478+150);glVertex2f(100+100,900-488+150);glVertex2f(140+100,900-484+150);glVertex2f(180+100,900-488+150);glVertex2f(200+100,900-480+150);glVertex2f(250+100,900-496+150);glVertex2f(300+100,900-490+150);glVertex2f(700+100,900-517+150);glVertex2f(8700+100,900-520+150);glVertex2f(900+100,900-468+150);glVertex2f(800+100,900-490+150);glVertex2f(700+100,900-480+150);glVertex2f(650+100,900-460+150);glVertex2f(620+100,900-480+150);glVertex2f(550+100,900-460+150);glVertex2f(500+100,900-420+150);glVertex2f(400+100,900-430+150);glVertex2f(250+100,900-470+150);glVertex2f(200+100,900-480+150);glVertex2f(130+100,900-490+150);glVertex2f(110+100,900-470+150);
	glEnd ( );
	glBegin(GL_POLYGON);
		glVertex2f(900-820,900-550);glVertex2f(950-820,900-538);glVertex2f(1000-820,900-528);glVertex2f(1010-820,900-518);glVertex2f(1040-820,900-514);glVertex2f(1100-820,900-538);glVertex2f(1200-820,900-540);glVertex2f(1250-820,900-556);glVertex2f(1300-820,900-560);glVertex2f(1350-820,900-567);glVertex2f(1500-820,900-540);glVertex2f(1600-820,900-518);
		glVertex2f(1500-820,900-490);glVertex2f(1550-820,900-530);glVertex2f(1420-820,900-540);glVertex2f(1400-820,900-560);glVertex2f(1380-820,900-580);glVertex2f(1350-820,900-540);glVertex2f(1300-820,900-530);glVertex2f(1250-820,900-520);glVertex2f(1200-820,900-499);glVertex2f(1100-820,900-490);glVertex2f(1050-820,900-485);glVertex2f(950-820,900-515);glVertex2f(880-820,900-535);
	glEnd ( );
	glColor3f (0.514,0.796,0.906);
	ctcircle(1182,900-408,95,5,GL_POLYGON  );
	glLineWidth(20.f); 
	glColor3f (0,0.506,0.576);
	ctcircle(1182,900-408,93,5,GL_LINE_LOOP  );
	glLineWidth(2.5f); 
	glColor3f (0,0,0);
	ctcircle(1182,900-408,95,5,GL_LINE_LOOP  );
	//
	glLineWidth(0.001f); 
	glColor3f (0.514,0.796,0.906);
	ctcircle(419,900-660,130,5,GL_POLYGON  );
	glLineWidth(20.f); 
	glColor3f (0,0.506,0.576);
	ctcircle(419,900-660,128,5,GL_LINE_LOOP  );
	glLineWidth(2.5f); 
	glColor3f (0,0,0);
	ctcircle(419,900-660,130,5,GL_LINE_LOOP  );
	//
	glLineWidth(0.001f); 
	glColor3f (0.973,0.973,0.851);
	glBegin(GL_POLYGON);
	for(int i=0;i<8;i++)
		glVertex2fv(upDialog[i]);
	glEnd ( );
	glLineWidth(5.f); 
	glColor3f (0.322,0.404,0.38);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<8;i++)
		glVertex2fv(upDialog[i]);
	glEnd ( );
	glLineWidth(10.f); 
	glColor3f (0.204,0.937,0.494);
	glBegin(GL_LINES);
		glVertex2f(343,900-196);glVertex2f(675,900-196);
	glEnd ( );
	
	//
	glLineWidth(0.001f); 
	glColor3f(0.247,0.247,0.247);
    glRasterPos2f(133, 900-157);
    selectFont(30, DEFAULT_CHARSET, "YouYuan");
    drawCNString("ÃU³½¤ý");
    glColor3f(0.247,0.247,0.247);
    glRasterPos2f(555, 900-156);
    selectFont(30, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString("Lv87");
    glColor3f(0.941,0.573,0.439);
    glRasterPos2f(280, 900-205);
    selectFont(27, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString("HP");
    glLineWidth(2.001f); 
    glColor3f (0.29,0.788,0.96);
	glBegin(GL_LINE_STRIP);
		glVertex2f(336,900-137);glVertex2f(352,900-127);glVertex2f(365,900-139);glVertex2f(352,900-127);glVertex2f(351,900-143);glVertex2f(341,900-145);glVertex2f(337,900-153);glVertex2f(345,900-160);glVertex2f(356,900-157);glVertex2f(359,900-148);glVertex2f(351,900-143);
	glEnd ( );
	glLineWidth(0.001f); 
}
void fight::drawCarpKing(){
	//tailW
	glLineWidth(2.f); 
	glColor3f (0.862,0.862,0.862);
	glBegin(GL_POLYGON);
	for(int i=0;i<5;i++)
		glVertex2fv(carpKingTailWhite[i]);
	glVertex2fv(carpKingTailRed[18]);
	glVertex2fv(carpKingTailRed[0]);
	glEnd ( );
	glBegin(GL_POLYGON);
	for(int i=5;i<10;i++)
		glVertex2fv(carpKingTailWhite[i]);
	glVertex2fv(carpKingTailRed[18]);
	glVertex2fv(carpKingTailRed[0]);
	glEnd ( );
	
	//tailWLine
	glColor3f (0,0,0);
	glBegin(GL_LINE_STRIP );
	for(int i=0;i<10;i++)
		glVertex2fv(carpKingTailWhite[i]);
	glEnd ( );
	glColor3f (0.686,0.686,0.686);
	glBegin(GL_LINE_STRIP );
	for(int i=10;i<13;i++)
		glVertex2fv(carpKingTailWhite[i]);
	glEnd ( );
	glBegin(GL_LINE_STRIP );
	for(int i=13;i<16;i++)
		glVertex2fv(carpKingTailWhite[i]);
	glEnd ( );
	//tailR
	glColor3f (0.957,0.416,0.137);
	glBegin(GL_POLYGON);
	for(int i=0;i<12;i++)
		glVertex2fv(carpKingTailRed[i]);
	glEnd ( );
	glColor3f (0.831,0.09,0);
	glBegin(GL_POLYGON);
	for(int i=10;i<19;i++)
		glVertex2fv(carpKingTailRed[i]);
	glEnd ( );
	//tailRLine
	glColor3f (0.749,0.141,0.074);
	glBegin(GL_LINE_STRIP );
	for(int i=0;i<19;i++)
		glVertex2fv(carpKingTailRed[i]);
	glEnd ( );
	//body
	glColor3f (0.831,0.09,0);
	glColor3f (0.957,0.416,0.137);
	glColor3f (0.976,0.655,0.439);
	glBegin(GL_POLYGON);
	for(int i=0;i<19;i++){
		//glColor3f(0.976-0.0076*i,0.655-0.02973*i,0.439-0.02311*i);
		glColor3f(0.976-0.00152*i,0.655-0.031*i,0.439-0.04622*i);
		glVertex2fv(carpBody[i]);
	}
		
	glEnd ( );
	//bodyLine
	glColor3f (0.749,0.141,0.074);
	glBegin(GL_LINE_STRIP );
	for(int i=1;i<18;i++)
		glVertex2fv(carpBody[i]);
	glEnd ( );
	//chi
	glColor3f (0.862,0.862,0.862);
	glBegin(GL_POLYGON);
	for(int i=0;i<7;i++)
		glVertex2fv(carpChi[i]);
	glEnd ( );
	//chiLine
	glColor3f (0.686,0.686,0.686);
	glBegin(GL_LINES );
	for(int i=7;i<11;i++)
		glVertex2fv(carpChi[i]);
	glEnd ( );
	//eye
	glColor3f (1,1,1);
	circle(eye[0],eye[1],18,GL_POLYGON,360,0);
	glColor3f (0,0,0);
	circle(eye[0],eye[1],3,GL_POLYGON,360,0);
	//eteLine
	glColor3f (0.749,0.141,0.074);
	circle(eye[0],eye[1],18,GL_LINE_LOOP ,360,0);
	//line
	glColor3f (0.749,0.141,0.074);
	for(int i=0;i<28;i++){//4 10 12 15 23 28
		if(i==15)
			glColor3f (0,0,0);
		if(i==23)
		glColor3f (0.749,0.141,0.074);
		if(i==0||i==4||i==10||i==12||i==15||i==23)
			glBegin(GL_LINE_STRIP );
		glVertex2fv(carpLine[i]);
		if(i==3||i==9||i==11||i==14||i==22||i==27)
			glEnd ( );
	}
	//mouth
	glColor3f (1,0.682,0.561);
	glBegin(GL_POLYGON);
	for(int i=0;i<11;i++)
		glVertex2fv(carpMouth[i]);
	glEnd ( );
	glColor3f (0.749,0.141,0.074);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<11;i++)
		glVertex2fv(carpMouth[i]);
	glEnd ( );
	glColor3f (0,0,0);
	glBegin(GL_POLYGON);
	for(int i=11;i<17;i++)
		glVertex2fv(carpMouth[i]);
	glEnd ( );
	glColor3f (1,0,0);
	glBegin(GL_POLYGON);
	for(int i=12;i<16;i++)
		glVertex2fv(carpMouth[i]);
	glEnd ( );
	glColor3f (0.749,0.141,0.074);
	glBegin(GL_LINE_LOOP);
	for(int i=11;i<17;i++)
		glVertex2fv(carpMouth[i]);
	glEnd ( );
	//carpLastChi
	glColor3f (0.855,0.769,0.412);
	glBegin(GL_POLYGON);
	for(int i=0;i<9;i++)
		glVertex2fv(carpLastChi[i]);
	glEnd ( );
	glColor3f (0.686,0.58,0.153);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<9;i++)
		glVertex2fv(carpLastChi[i]);
	glEnd ( );
	//CarpUpChi
	glColor3f (0.914,0.973,0.510);
	glBegin(GL_POLYGON);
	for(int i=0;i<9;i++)
		glVertex2fv(CarpUpChi[i]);
	glEnd ( );
	glColor3f (0.855,0.769,0.412);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<9;i++)
		glVertex2fv(CarpUpChi[i]);
	glEnd ( );
	//carpTwoChi
	glColor3f (0.914,0.973,0.510);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<10;i++)
		glVertex2fv(carpTwoChi[i]);
	glEnd ( );
	glBegin(GL_LINE_STRIP);
	for(int i=10;i<19;i++)
		glVertex2fv(carpTwoChi[i]);
	glEnd ( );
	
	
	glFlush ( );
}
void fight::drawDialog(){
	glColor3f (0.275,0.275,0.275);
	glBegin(GL_POLYGON );
		glVertex2f(0,0);glVertex2f(0,900-635);glVertex2f(1600,900-635);glVertex2f(1600,0);
	glEnd ( );
	glColor3f (0.82,0.282,0.224);
	glBegin(GL_POLYGON );
		glVertex2f(50,900-650);glVertex2f(10,900-695);glVertex2f(10,900-840);glVertex2f(50,900-885);glVertex2f(1550,900-885);glVertex2f(1590,900-840);glVertex2f(1590,900-695);glVertex2f(1550,900-650);
	glEnd ( );
	glColor3f (0.404,0.620,0.627);
	glBegin(GL_POLYGON );
		glVertex2f(90,900-658);glVertex2f(50,900-703);glVertex2f(50,900-832);glVertex2f(90,900-877);glVertex2f(1510,900-877);glVertex2f(1540,900-832);glVertex2f(1540,900-703);glVertex2f(1510,900-658);
	glEnd ( );
	
}
void fight::drawRightDialog(){
	glColor3f (0.255,0.255,0.255);
	glBegin(GL_POLYGON );
	for(int i=1;i<7;i++)
		glVertex2fv(RightDialog[i]);
		glVertex2f(900,900-620);
	glEnd ( );
	glBegin(GL_POLYGON );
		glVertex2fv(RightDialog[0]);glVertex2fv(RightDialog[1]);glVertex2f(900,900-620);
	glEnd ( );
	glColor3f (0.973,0.973,0.851);
	glBegin(GL_POLYGON );
		glVertex2f(915,900-433);glVertex2f(1485,900-433);glVertex2f(1485,900-580);glVertex2f(915,900-580);
	glEnd ( );
	selectFont(30, DEFAULT_CHARSET, "YouYuan");
    glColor3f(0.247,0.247,0.247);
    glRasterPos2f(930, 900-490);
    drawCNString("Às¿ß");
    glPushMatrix ();
	glTranslatef(745,-330,0);
	glLineWidth(2.001f); 
    glColor3f (0.29,0.788,0.96);
	glBegin(GL_LINE_STRIP);
		glVertex2f(336,900-137);glVertex2f(352,900-127);glVertex2f(365,900-139);glVertex2f(352,900-127);glVertex2f(351,900-143);glVertex2f(341,900-145);glVertex2f(337,900-153);glVertex2f(345,900-160);glVertex2f(356,900-157);glVertex2f(359,900-148);glVertex2f(351,900-143);
	glEnd ( );
	glPopMatrix(); 
	glPushMatrix ();
	glLineWidth(0.001f); 
	glColor3f(0.247,0.247,0.247);
    glRasterPos2f(1320, 900-490);
    selectFont(30, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString(" Lv9999");
    glColor3f(0.941,0.573,0.439);
    glRasterPos2f(1073, 900-532);
    selectFont(27, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString("HP");
    glLineWidth(10.f); 
	glColor3f (0.204,0.937,0.494);
	glBegin(GL_LINES);
		glVertex2f(1135,900-520);glVertex2f(1467,900-520);
	glEnd ( );
	glLineWidth(0.001f); 
	glColor3f(0.247,0.247,0.247);
    glRasterPos2f(1250, 900-572);
    selectFont(30, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString("9999999/1");
    glLineWidth(10.f); 
	glColor3f (0.914,0.973,0.510);
    glRasterPos2f(940, 900-612);
    selectFont(24, DEFAULT_CHARSET, "Comic Sans MS");
    drawCNString("EXP");
    glLineWidth(8.f);
    glBegin(GL_LINES);
		glVertex2f(1030,900-600);glVertex2f(1467,900-600);
	glEnd ( );
	glColor3f (0.29,0.788,0.96);
	glBegin(GL_LINES);
		glVertex2f(1030,900-600);glVertex2f(1200,900-600);
	glEnd ( );
    glLineWidth(0.001f); 
    glColor3f (1,1,1);
	glBegin(GL_POLYGON );
		glVertex2f(800,0);glVertex2f(800,900-635);glVertex2f(1600,900-635);glVertex2f(1600,0);
	glEnd ( );
	glColor3f (0,0,0);
	glLineWidth(2.f); 
	glBegin(GL_LINE_LOOP);
		glVertex2f(820,20);glVertex2f(820,900-655);glVertex2f(1580,900-655);glVertex2f(1580,20);
	glEnd ( );
	glLineWidth(4.f); 
	glBegin(GL_LINE_LOOP);
		glVertex2f(835,35);glVertex2f(835,900-670);glVertex2f(1565,900-670);glVertex2f(1565,35);
	glEnd ( );
	selectFont(30, DEFAULT_CHARSET, "YouYuan");
    glColor3f(0.247,0.247,0.247);
    glRasterPos2f(920, 900-740);
    drawCNString(wayToEat[0]);
	glRasterPos2f(1294, 900-740);
    drawCNString(wayToEat[1]);
    glRasterPos2f(920, 900-829);
    drawCNString(wayToEat[2]);
	glRasterPos2f(1294, 900-829);
    drawCNString(wayToEat[3]);
    glLineWidth(0.001f); 
    glBegin(GL_POLYGON );
    	glVertex2f(curX,curY);glVertex2f(curX,curY+55);glVertex2f(curX+33,curY+27.5);
	glEnd ( );
    
    
	glFlush ( );
}

