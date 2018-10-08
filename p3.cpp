#include<stdlib.h> 
#include<stdio.h> 
#include<time.h> 
#include<cmath> 
#include<GL/glut.h>  
#include "all.hpp"
void p3::drawCNString(const char* str) {
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
void p3::selectFont(int size, int charset, const char* face) {
    HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
        charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
    HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
    DeleteObject(hOldFont);
}
void p3::circle(int x,int y ,int R){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_POLYGON);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+R*cos(2*Pi/n*i), y+R*sin(2*Pi/n*i));
     }
	glEnd();}
void p3::circleline(int x,int y ,int R){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_LINE_LOOP);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+1.5*R*cos(2*Pi/n*i), y+R*sin(2*Pi/n*i));
     }
	glEnd();}
void p3::ctcircle(int x,int y ,int R,float c){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_POLYGON);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+c*R*cos(2*Pi/n*i), y+R*sin(2*Pi/n*i));
     }
	glEnd();}
void p3::circleline(int x,int y ,int R,float w,float e){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_LINE_LOOP);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+w*R*cos(2*Pi/n*i), y+e*R*sin(2*Pi/n*i));
     }
	glEnd();}
void p3::t1circle(int x,int y ,int R){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_POLYGON);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+R*cos(2*Pi/n*i), y+1.45*R*sin(2*Pi/n*i));
     }
	glEnd();}
void p3::country(){	
	glColor3f (0.10, 0.04, 0.31);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 00); 
	glVertex2i (0, 900);
 	glVertex2i (1600, 900); 
	glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.313, 0.341, 0.360);
	circle(1300,700,150);
	
	glColor3f (0.20, 0.24, 0.45);//雲
	 ctcircle(205,595,40,2.5);ctcircle(320,615,50,2.5);ctcircle(450,600,40,2.5);
	 ctcircle(300,585,60,2.5);ctcircle(135,565,30,2.5);
	
	
	glColor3f (0.1, 0.32, 0.45);//樹，後排 
	circle(180,325,40);circle(380,330,40);ctcircle(460,340,45,1.5);
	circle(525,336,25);circle(570,330,50);ctcircle(640,340,25,1.5);
	circle(710,330,45);circle(760,350,45);ctcircle(820,345,40,1.5);
	ctcircle(1370,315,50,1.5);circle(1450,310,45);
	
	glColor3f (0.109, 0.603, 0.478);//地4
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 330);glVertex2i (380, 330);
	glVertex2i (430, 335);glVertex2i (470, 330);glVertex2i (520, 328);
	glVertex2i (1420, 310);glVertex2i (1480, 310);glVertex2i (1560, 320);
	glVertex2i (1580, 328);glVertex2i (1600, 330);glVertex2i (1600, 0); 
	glEnd ( );
	
	glColor3f (0.05, 0.41, 0.278);//樹5
	t1circle(95,350,80);t1circle(250,350,60);t1circle(1520,340,70);
	
	glColor3f (0.113, 0.49, 0.427);//樹2 
	circle(225,300,20);circle(340,310,40);circle(300,325,50);
	ctcircle(250,310,20,1.5);
	glColor3f (0.062, 0.329, 0.376);//樹1 
	circle(40,305,30);circle(130,330,40);circle(167,300,40);
	ctcircle(82,322,30,1.5);
	
	glColor3f (0.13, 0.56, 0.54);//地3
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 290);glVertex2i (80, 295);
	glVertex2i (160, 300);glVertex2i (280, 295);glVertex2i (320, 293);
	glVertex2i (380, 290);glVertex2i (440, 300);glVertex2i (500, 300);
	glVertex2i (560, 300);glVertex2i (690, 305);glVertex2i (1030, 265);
	glVertex2i (1170, 260);glVertex2i (1250, 260);glVertex2i (1320, 260);
	glVertex2i (1420, 270);glVertex2i (1480, 280);glVertex2i (1560, 285);
	glVertex2i (1600, 290);glVertex2i (1600, 0); 
	glEnd ( );
	
	glColor3f (0.039, 0.274, 0.313);//樹4 
	circle(1030,470,35);circle(990,468,20);circle(965,440,30);
	circle(935,380,50);ctcircle(920,310,60,1.5);circle(1175,400,40);
	circle(1070,430,35);ctcircle(1130,410,35,1.5);
	glBegin (GL_POLYGON); 
	glVertex2i (990, 470);glVertex2i (1180,375); glVertex2i (1110, 240);
	glVertex2i (910, 255); 
	glEnd ( );
	glColor3f (0.05, 0.396, 0.423);//地2 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 250);glVertex2i (80, 260);
	glVertex2i (160, 256);glVertex2i (280, 260);glVertex2i (320, 240);
	glVertex2i (380, 230);glVertex2i (440, 225);glVertex2i (500, 220);
	glVertex2i (560, 220);glVertex2i (620, 230);glVertex2i (690, 240);
	glVertex2i (750, 250);glVertex2i (830, 255);glVertex2i (900, 260);
	glVertex2i (950, 270);glVertex2i (1030, 265);glVertex2i (1090, 260);
	glVertex2i (1170, 250);glVertex2i (1250, 250);glVertex2i (1320, 255);
	glVertex2i (1400, 255);glVertex2i (1480, 253);glVertex2i (1560, 250);
	glVertex2i (1600, 250);glVertex2i (1600, 0); 
	glEnd ( );
	
	
	glColor3f (0.113, 0.49, 0.427);//樹3 
	circle(1220,365,40);circle(1270,330,45);circle(1180,332,50);
	ctcircle(1135,285,35,1.5);circle(1320,310,20);ctcircle(1355,280,35,1.5);
	glBegin (GL_POLYGON); 
	glVertex2i (1355, 255);glVertex2i (1320, 250);glVertex2i (1260, 250);
	glVertex2i (1210, 245);glVertex2i (1170, 250);glVertex2i (1125, 260);
	glVertex2i (1110, 270);glVertex2i (1220, 360);glVertex2i (1355, 280);
	glEnd ( );
	
	
	glColor3f (0.06, 0.298, 0.368);//地1 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 120);glVertex2i (80, 110);
	glVertex2i (160, 115);glVertex2i (240, 120);glVertex2i (320, 125);
	glVertex2i (400, 120);glVertex2i (480, 115);glVertex2i (540, 105);
	glVertex2i (560, 108);glVertex2i (640, 115);glVertex2i (660, 125);
	glVertex2i (740, 120);glVertex2i (830, 115);glVertex2i (900, 105);
	glVertex2i (980, 110);glVertex2i (1070, 115);glVertex2i (1120, 110);
	glVertex2i (1180, 120);glVertex2i (1260, 110);glVertex2i (1320, 100);
	glVertex2i (1400, 95);glVertex2i (1480, 95);glVertex2i (1560, 110);
	glVertex2i (1600, 120);glVertex2i (1600, 0); 
	glEnd ( );
		glColor3f (0.15, 0.406, 0.453);
	ctcircle(100,60,10,2.5);ctcircle(150,70,10,2.5);ctcircle(200,50,15,2.5);
	ctcircle(250,60,10,2.5);ctcircle(300,40,10,2.5);ctcircle(450,75,13,2.5);
	ctcircle(500,65,10,2.5);ctcircle(650,50,10,2.5);ctcircle(700,40,8,2.5);
	ctcircle(670,30,5,2.5);ctcircle(760,60,10,2.5);ctcircle(800,50,7,2.5);
	
	ctcircle(900,60,10,2.5);ctcircle(950,70,10,2.5);ctcircle(1000,50,15,2.5);
	ctcircle(1050,60,10,2.5);ctcircle(1100,40,10,2.5);ctcircle(1250,75,13,2.5);
	ctcircle(1300,65,10,2.5);ctcircle(1450,50,10,2.5);ctcircle(1500,40,8,2.5);
	ctcircle(1470,30,5,2.5);ctcircle(1560,60,10,2.5);ctcircle(1570,40,7,2.5);
}
void p3::forest(){
	glColor3f (0.20, 0.24, 0.45);//雲
	
	
	glColor3f (0.13, 0.36, 0.5);//樹，後排
	circle(0,325,40);circle(60,335,50);circle(110,325,40);
	circle(280,325,70);circle(180,325,40);circle(380,330,40);
	ctcircle(460,340,45,1.5);circle(525,336,25);circle(570,330,50);
	ctcircle(640,340,25,1.5);circle(710,330,45);circle(760,350,45);
	ctcircle(820,345,40,1.5);circle(880,325,40);ctcircle(1020,325,40,1.5);
	ctcircle(1160,325,40,1.5);circle(1220,325,50);circle(1280,325,35);
	ctcircle(1370,315,50,1.5);circle(1450,310,45);circle(1530,320,40);circle(1570,325,35); 
	 
	glColor3f (0.109, 0.603, 0.478);//地4
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 330);glVertex2i (380, 330);
	glVertex2i (430, 335);glVertex2i (470, 330);glVertex2i (520, 328);
	glVertex2i (1420, 310);glVertex2i (1480, 310);glVertex2i (1560, 320);
	glVertex2i (1580, 328);glVertex2i (1600, 330);glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.05, 0.41, 0.278);//樹5
	
	glColor3f (0.18, 0.42, 0.18);//樹3
	glBegin (GL_POLYGON); 
	glVertex2f (400,220);glVertex2f (410,450);glVertex2f (430,900);
	glVertex2f (470,900);glVertex2f (490,450);glVertex2f (500,220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (600,220);glVertex2f (595,450);glVertex2f (585,900);
	glVertex2f (630,900);glVertex2f (660,500);glVertex2f (700,220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (1050,220);glVertex2f (1080,450);glVertex2f (1100,900);
	glVertex2f (1120,900);glVertex2f (1150,450);glVertex2f (1170,220);
	glEnd ( );
	
	glColor3f (0.13, 0.56, 0.54);//地3
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 290);glVertex2i (80, 295);
	glVertex2i (160, 300);glVertex2i (280, 295);glVertex2i (320, 293);
	glVertex2i (380, 290);glVertex2i (440, 300);glVertex2i (500, 300);
	glVertex2i (560, 300);glVertex2i (690, 305);glVertex2i (1030, 285);
	glVertex2i (1170, 275);glVertex2i (1250, 270);glVertex2i (1320, 270);
	glVertex2i (1420, 270);glVertex2i (1480, 280);glVertex2i (1560, 285);
	glVertex2i (1600, 290);glVertex2i (1600, 0); 
	glEnd ( );
	
	
	
	glColor3f (0.16, 0.367, 0.190);//樹2 
	glBegin (GL_POLYGON); 
	glVertex2f (300,220);glVertex2f (320,450);glVertex2f (350,900);
	glVertex2f (380,900);glVertex2f (410,450);glVertex2f (430,220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (650,220);glVertex2f (670,450);glVertex2f (700,900);
	glVertex2f (730,900);glVertex2f (760,450);glVertex2f (780,220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (1350,220);glVertex2f (1330,450);glVertex2f (1310,900);
	glVertex2f (1340,900);glVertex2f (1420,450);glVertex2f (1460,220);
	glEnd ( );
	glColor3f (0.05, 0.396, 0.423);//地2 
	glBegin (GL_POLYGON); 
	glVertex2f (0,0); glVertex2f (0, 250);glVertex2f (80, 260);
	glVertex2f (160, 256);glVertex2f (280, 260);glVertex2f (320, 245);
	glVertex2f (380, 230);glVertex2f (440, 225);glVertex2f (500, 220);
	glVertex2f (560, 220);glVertex2f (620, 230);glVertex2f (690, 240);
	glVertex2f (750, 250);glVertex2f (830, 255);glVertex2f (900, 260);
	glVertex2f (950, 270);glVertex2f (1030, 265);glVertex2f (1090, 260);
	glVertex2f (1170, 250);glVertex2f (1250, 250);glVertex2f (1320, 255);
	glVertex2f (1400, 255);glVertex2f (1480, 253);glVertex2f (1560, 250);
	glVertex2f (1600, 250);glVertex2f (1600, 0); 
	glEnd ( );

	glColor3f (0.141, 0.301, 0.2);//樹1 
	glBegin (GL_POLYGON); 
	glVertex2f (100,110);glVertex2f (130,400);glVertex2f (150,900);
	glVertex2f (200,900);glVertex2f (230,400);glVertex2f (250,110);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (900,100);glVertex2f (930,400);glVertex2f (950,900);
	glVertex2f (1000,900);glVertex2f (1030,400);glVertex2f (1050,110);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (1360,100);glVertex2f (1390,400);glVertex2f (1410,900);
	glVertex2f (1460,900);glVertex2f (1490,400);glVertex2f (1510,110);
	glEnd ( );
	
	glColor3f (0.04, 0.4, 0.35);//葉子
	ctcircle(100,740,40,1.5);ctcircle(140,750,50,1.5);ctcircle(255,770,40,1.5);
	ctcircle(480,750,50,1.5);ctcircle(650,770,40,1.5);ctcircle(920,725,50,1.5);
	ctcircle(1150,750,50,1.5);ctcircle(1360,765,50,1.5);ctcircle(1480,740,50,1.5);
	glColor3f (0.03, 0.32, 0.30);//葉子 
	circle(30,720,50);ctcircle(75,790,50,1.5);ctcircle(220,830,60,1.5);
	circle(340,810,50);ctcircle(370,750,30,2.5);ctcircle(455,790,60,1.5);
	ctcircle(560,750,45,1.5);ctcircle(590,842,60,1.5);ctcircle(740,830,70,1.5);
	ctcircle(820,735,50,1.5);ctcircle(940,775,80,1.5);ctcircle(1060,720,50,1.5);
	ctcircle(1110,810,65,1.5);circle(1230,800,60);ctcircle(1350,820,60,1.5);
	ctcircle(1480,800,65,1.5);ctcircle(1485,865,65,1.5);ctcircle(1540,750,40,1.5);
	ctcircle(20,775,60,1.5);
	
	glBegin (GL_POLYGON); 
	glVertex2f (0,820);glVertex2f (0,900);glVertex2f (1570,900);
	glVertex2f (1570,820);
	glEnd ( );
	
	glColor3f (0.06, 0.298, 0.368);//地1 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 120);glVertex2i (80, 110);
	glVertex2i (160, 115);glVertex2i (240, 120);glVertex2i (320, 125);
	glVertex2i (400, 120);glVertex2i (480, 115);glVertex2i (540, 105);
	glVertex2i (560, 108);glVertex2i (640, 115);glVertex2i (660, 125);
	glVertex2i (740, 120);glVertex2i (830, 115);glVertex2i (900, 105);
	glVertex2i (980, 110);glVertex2i (1070, 115);glVertex2i (1120, 110);
	glVertex2i (1180, 120);glVertex2i (1260, 110);glVertex2i (1320, 100);
	glVertex2i (1400, 95);glVertex2i (1480, 95);glVertex2i (1560, 110);
	glVertex2i (1600, 120);glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.15, 0.406, 0.453);
	ctcircle(100,60,10,2.5);ctcircle(150,70,10,2.5);ctcircle(200,50,15,2.5);
	ctcircle(250,60,10,2.5);ctcircle(300,40,10,2.5);ctcircle(450,75,13,2.5);
	ctcircle(500,65,10,2.5);ctcircle(650,50,10,2.5);ctcircle(700,40,8,2.5);
	ctcircle(670,30,5,2.5);ctcircle(760,60,10,2.5);ctcircle(800,50,7,2.5);
	
	ctcircle(900,60,10,2.5);ctcircle(950,70,10,2.5);ctcircle(1000,50,15,2.5);
	ctcircle(1050,60,10,2.5);ctcircle(1100,40,10,2.5);ctcircle(1250,75,13,2.5);
	ctcircle(1300,65,10,2.5);ctcircle(1450,50,10,2.5);ctcircle(1500,40,8,2.5);
	ctcircle(1470,30,5,2.5);ctcircle(1560,60,10,2.5);ctcircle(1570,40,7,2.5);
}
void p3::tree(){
		glColor3f (0.30, 0.53, 0.56);
	ctcircle(1130,40,75,4.2);
	
	glColor3f (0.141, 0.301, 0.2);
	ctcircle(1100,510,90,4.3);
	glColor3f (0.0, 0.0, 0.0);
	circleline(1100,510,90,4.3,1);
	glLineWidth(4);
	glBegin (GL_LINE_STRIP); 
	glVertex2f(1080,50);glVertex2f(1080,550);glVertex2f(1260,550);
	glVertex2f(1270,200);glVertex2f(1290,110);glVertex2f(1320,50);
	glEnd();
	glBegin (GL_LINE_STRIP); 
	glVertex2f(1080,200);glVertex2f(1070,150);glVertex2f(1060,110);
	glVertex2f(1050,40);
	glEnd();
	
	glColor3f (0.33, 0.168, 0);//樹幹 
	glBegin (GL_POLYGON); 
	glVertex2f(1080,200);glVertex2f(1070,150);glVertex2f(1060,110);
	glVertex2f(1050,40);glVertex2f(1130,70);
	glEnd();
	glBegin (GL_POLYGON); 
	glVertex2f(1080,50);glVertex2f(1080,550);glVertex2f(1260,550);
	glVertex2f(1270,200);glVertex2f(1290,110);glVertex2f(1320,50);
	glEnd();
	glLineWidth(4);
	glColor3f (0.0, 0.0, 0.0);
	circleline(1100,560,100,4.5,0.95);circleline(950,600,80,3,0.955);
	circleline(900,640,100,1,1);circleline(1150,750,120,2.5,1);
	circleline(990,830,80,1,1.5);circleline(1190,850,80,2,1);
	circleline(1360,640,90,1,1.5);circleline(1300,640,100,1,1);
	circleline(1440,620,50,1,1);
	glBegin(GL_LINES);
	glVertex2f(1230,400);glVertex2f(1230,270);
	glVertex2f(1250,350);glVertex2f(1250,220);	
	glEnd();
	
	glColor3f (0.141, 0.301, 0.2);
	ctcircle(1100,560,100,4.5);ctcircle(950,600,80,3);circle(900,640,100);
	ctcircle(1150,750,120,2.5);t1circle(990,830,80);ctcircle(1190,850,80,2);
	t1circle(1360,640,90);circle(1300,640,100);circle(1440,620,50);
	
	glColor3f (0.041, 0.201, 0.1);
	glLineWidth(4);
	circleline(1230,770,90,1,1);circleline(1330,670,50,1.5,1);circleline(880,580,60,1.5,1);
	
	glColor3f (0.141, 0.301, 0.2);
	glBegin (GL_POLYGON); 
	glVertex2f(1100,850);glVertex2f(1200,880);glVertex2f(1390,750);
	glVertex2f(1340,550);glVertex2f(1200,550);glVertex2f(890,500);
	glVertex2f(850,640);
	glEnd();
}
void p3::house(){
	glColor3f (0.13, 0.46, 0.3);
	ctcircle(40,270,200,1.5);circle(310,270,180);ctcircle(1550,270,100,1.5);
	glColor3f (0.18, 0.42, 0.18);//樹3
	ctcircle(50,150,80,1.5);ctcircle(210,170,100,1.5);circle(380,200,120);
	circle(1450,190,90);circle(1530,150,85);
	glColor3f (0.05, 0.396, 0.423);//地2 
	glBegin (GL_POLYGON); 
	glVertex2f (0, 0);glVertex2f (0, 140);glVertex2f (100, 160);
	glVertex2f (200, 180);glVertex2f (300, 190);glVertex2f (400, 200);
	glVertex2f (1400, 180);glVertex2f (1500, 160);glVertex2f (1600, 140);
	glVertex2f (1600, 0);
	glEnd ( );
	glColor3f (0.02, 0.3, 0.39);
	ctcircle(900,140,100,5.5);
	glLineWidth(2);
	
	glColor3f (0.2, 0.17, 0.15);//屋頂 

	glBegin (GL_POLYGON); 
	glVertex2f (670, 800);glVertex2f (320, 450);
	glVertex2f (1050, 450);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (800, 600);glVertex2f (1440, 570);
	glVertex2f (1500, 360);glVertex2f (700, 360);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (670, 740);glVertex2f (490, 590);
	glVertex2f (870, 590);
	glEnd ( );
	glColor3f (0.56, 0.301, 0.25);	
	glColor3f (0.513, 0.286, 0.23);
	glBegin (GL_POLYGON); //房子底 
	glVertex2f (670, 690);glVertex2f (590, 620);glVertex2f (545, 580); 
	glVertex2f (495, 530);glVertex2f (455, 495);glVertex2f (410, 450);
	glVertex2f (410, 450);glVertex2f (410, 415);glVertex2f (410, 380);
	glVertex2f (410, 330);glVertex2f (410, 305);glVertex2f (410, 260);
	glVertex2f (410, 220);glVertex2f (410, 190);glVertex2f (410, 155);
	glVertex2f (410, 120);glVertex2f (950, 120);glVertex2f (950, 155);
	glVertex2f (950, 190);glVertex2f (950, 220);glVertex2f (950, 260);
	glVertex2f (950, 305);glVertex2f (950, 330);glVertex2f (950, 380);
	glVertex2f (950, 415);glVertex2f (950, 450);glVertex2f (895, 495);
	glVertex2f (850, 530);glVertex2f (795, 580);glVertex2f (760, 620);
	glEnd ( );	
	glBegin (GL_POLYGON); 
	glVertex2f (950, 360);glVertex2f (950, 140);glVertex2f (1400, 140);
	glVertex2f (1450, 360);
	glEnd ( );	
	
	glColor3f (0.483, 0.246, 0.2);
	glBegin (GL_POLYGON); 
	glVertex2f (410, 120);glVertex2f (950, 120);
	glVertex2f (950, 155);glVertex2f (410, 155);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (410, 305);glVertex2f (950, 305);
	glVertex2f (950, 220);glVertex2f (410, 220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (410, 415);glVertex2f (410, 380);
	glVertex2f (950, 380);glVertex2f (950, 415);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (495, 530);glVertex2f (455, 495);
	glVertex2f (895, 495);glVertex2f (850, 530);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (950, 190);glVertex2f (1410, 190);
	glVertex2f (1405, 170);glVertex2f (950, 170);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (950, 315);glVertex2f (1440, 315);
	glVertex2f (1430, 275);glVertex2f (950, 275);
	glEnd ( );
	
	glColor3f (0.43, 0.176, 0.13);
	glBegin (GL_POLYGON); 
	glVertex2f (950, 360);glVertex2f (950, 140);
	glVertex2f (1090, 140);glVertex2f (1120, 360);
	glEnd ( );	
	
	
	glColor3f (0.29, 0.129, 0.13);
	glBegin (GL_LINES); 
	glVertex2f (590, 620); glVertex2f (765, 620);
 	glVertex2f (545, 580);glVertex2f (800, 580);
	glVertex2f (495, 530); glVertex2f (860, 530);
	glVertex2f (455, 495);glVertex2f (900, 495);
	glVertex2f (410, 450);glVertex2f (950, 450);
	glVertex2f (410, 415);glVertex2f (950, 415);
	glVertex2f (410, 380);glVertex2f (950, 380);	
	glVertex2f (410, 330);glVertex2f (950, 330);
	glVertex2f (410, 305);glVertex2f (950, 305);
	glVertex2f (410, 260);glVertex2f (950, 260);
	glVertex2f (410, 220);glVertex2f (950, 220);
	glVertex2f (410, 190);glVertex2f (950, 190);
	glVertex2f (410, 155);glVertex2f (950, 155);	
	glEnd ( );	
	glBegin (GL_LINES); 
	glVertex2f (950, 345);glVertex2f (1450, 345);
	glVertex2f (950, 315);glVertex2f (1440, 315);
	glVertex2f (950, 275);glVertex2f (1430, 275);
	glVertex2f (950, 230);glVertex2f (1420, 230);
	glVertex2f (950, 190);glVertex2f (1410, 190);
	glVertex2f (950, 170);glVertex2f (1408, 170);
	glEnd ( );
	
	glBegin (GL_POLYGON); 
	glVertex2f (370, 445);glVertex2f (410, 450);
	glVertex2f (670, 690);glVertex2f (670, 715);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (670, 715);glVertex2f (670, 690);
	glVertex2f (950, 450);glVertex2f (990, 445);
	glEnd ( );
	glColor3f (0.60, 0.382, 0.237);//屋簷 
	glBegin (GL_POLYGON); 
	glVertex2f (370, 445);glVertex2f (355, 450);
	glVertex2f (670, 715);glVertex2f (670, 740);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (990, 445);glVertex2f (1005, 450);
	glVertex2f (670, 715);glVertex2f (670, 740);
	glEnd ( );
	glBegin (GL_LINES); 
	glVertex2f (950, 360);glVertex2f (1500, 360);
	glEnd ( );

	glColor3f (0.453, 0.236, 0.20);
	glBegin (GL_POLYGON); //1煙囪 
	glVertex2f (1270, 620);glVertex2f (1325, 620);
	glVertex2f (1325, 590);glVertex2f (1270, 590);
	glEnd ( );
	glColor3f (0.513, 0.286, 0.23);
	glBegin (GL_POLYGON); //2
	glVertex2f (1325, 620);glVertex2f (1400, 620);
	glVertex2f (1400, 590);glVertex2f (1325, 590);
	glEnd ( );
	glBegin (GL_POLYGON); //3
	glVertex2f (1270, 590);glVertex2f (1290, 590);
	glVertex2f (1280, 555);glVertex2f (1265, 557);
	glEnd ( );
	glColor3f (0.453, 0.236, 0.20);
	glBegin (GL_POLYGON); //4
	glVertex2f (1290, 590);glVertex2f (1380, 590);
	glVertex2f (1385, 557);glVertex2f (1280, 557);
	glEnd ( );
	glBegin (GL_POLYGON); //5
	glVertex2f (1380, 590);glVertex2f (1400, 590);
	glVertex2f (1405, 555);glVertex2f (1385, 553);
	glEnd ( );
	glBegin (GL_POLYGON); //6
	glVertex2f (1265, 557);glVertex2f (1320, 555);glVertex2f (1315, 510);
	glVertex2f (1280, 510);glVertex2f (1265, 530);
	glEnd ( );	
	glColor3f (0.513, 0.286, 0.23);
	glBegin (GL_POLYGON); //7
	glVertex2f (1320, 555);glVertex2f (1405, 553);
	glVertex2f (1405, 510);glVertex2f (1315, 510);
	glEnd ( );
	glColor3f (0.453, 0.236, 0.20);	
	glBegin (GL_POLYGON); //8
	glVertex2f (1280, 510);glVertex2f (1360, 510);
	glVertex2f (1360, 483);
	glEnd ( );
	glBegin (GL_POLYGON); //9
	glVertex2f (1360, 510);glVertex2f (1405, 510);
	glVertex2f (1400, 483);glVertex2f (1360, 483);
	glEnd ( );
	glColor3f (0.29, 0.129, 0.13);//煙囪
	glBegin (GL_POLYGON); 
	glVertex2f (1295, 620);glVertex2f (1300, 650);
	glVertex2f (1330, 650);glVertex2f (1335, 620);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (1350, 620);glVertex2f (1355, 650);
	glVertex2f (1380, 650);glVertex2f (1385, 620);
	glEnd ( );
	
	glBegin (GL_LINE_LOOP); //1
	glVertex2f (1270, 620);glVertex2f (1325, 620);
	glVertex2f (1325, 590);glVertex2f (1270, 590);
	glEnd ( );
	glBegin (GL_LINE_LOOP); //2
	glVertex2f (1325, 620);glVertex2f (1400, 620);
	glVertex2f (1400, 590);glVertex2f (1325, 590);
	glEnd ( );
	glBegin (GL_LINE_LOOP); //3
	glVertex2f (1270, 590);glVertex2f (1290, 590);
	glVertex2f (1280, 555);glVertex2f (1265, 557);
	glEnd ( );
	glBegin (GL_LINE_LOOP); //4
	glVertex2f (1290, 590);glVertex2f (1380, 590);
	glVertex2f (1385, 557);glVertex2f (1280, 557);
	glEnd ( );
	glBegin (GL_LINE_LOOP); //5
	glVertex2f (1380, 590);glVertex2f (1400, 590);
	glVertex2f (1405, 555);glVertex2f (1385, 553);
	glEnd ( );
	glBegin (GL_LINE_LOOP); //6
	glVertex2f (1265, 557);glVertex2f (1320, 555);glVertex2f (1315, 510);
	glVertex2f (1280, 510);glVertex2f (1265, 530);
	glEnd ( );	
	glBegin (GL_LINE_LOOP); //7
	glVertex2f (1320, 555);glVertex2f (1405, 553);
	glVertex2f (1405, 510);glVertex2f (1315, 510);
	glEnd ( );
		glBegin (GL_LINE_LOOP); //8
	glVertex2f (1280, 510);glVertex2f (1360, 510);
	glVertex2f (1360, 483);
	glEnd ( );
		glBegin (GL_LINE_LOOP); //9
	glVertex2f (1360, 510);glVertex2f (1405, 510);
	glVertex2f (1400, 483);glVertex2f (1360, 483);
	glEnd ( );
	
	glColor3f (0.717, 0.615, 0.545);//門 
	glBegin (GL_POLYGON); 
	glVertex2f (600, 120);glVertex2f (590, 315);
	glVertex2f (770, 315);glVertex2f (760, 120);
	glEnd ( );
	glColor3f (0.6, 0.4, 0.3);
	glBegin (GL_LINE_STRIP); 
	glVertex2f (620, 120);glVertex2f (610, 295);
	glVertex2f (755, 295);glVertex2f (745, 120);
	glEnd ( );
	glBegin (GL_LINES); 
	glVertex2f (655, 295);glVertex2f (660, 120);
	glVertex2f (705, 295);glVertex2f (700, 120);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2f (605, 565);glVertex2f (740, 565);
	glVertex2f (740, 465);glVertex2f (605, 465);
	glEnd ( );

	glColor3f (0.49, 0.725, 0.764);
	glBegin (GL_POLYGON); 
	glVertex2f (620, 560);glVertex2f (725, 560);
	glVertex2f (725, 470);glVertex2f (620, 470);
	glEnd ( );
	glColor3f (0.6, 0.4, 0.3);
	glBegin (GL_LINES); 
	glVertex2f (620, 515);glVertex2f (725, 515);
	glVertex2f (672, 560);glVertex2f (672, 470);
	glEnd ( );	
	glBegin (GL_LINES); 
	glVertex2f (590, 465);glVertex2f (760, 465);
	glEnd ( );
	circle(637,200,10);
}
void p3::pond(){
	glColor3f (0.313, 0.341, 0.360);
	circle(1300,700,150);
	
	glColor3f (0.20, 0.24, 0.45);//雲
	 ctcircle(205,595,40,2.5);ctcircle(320,615,50,2.5);ctcircle(450,600,40,2.5);
	 ctcircle(300,585,60,2.5);ctcircle(135,565,30,2.5);
		glLineWidth(2);
	glColor3f (0.1, 0.32, 0.45);//樹，後排 
	circle(180,325,40);circle(380,330,40);ctcircle(460,340,45,1.5);
	circle(525,336,25);circle(570,330,50);ctcircle(640,340,25,1.5);
	circle(710,330,45);circle(760,350,45);ctcircle(820,340,40,1.5);
	circle(900,330,45);circle(950,350,45);ctcircle(1000,340,40,1.5);
	circle(1100,330,50);circle(1160,330,30);ctcircle(1270,325,40,2.5);
	ctcircle(1370,300,50,1.5);circle(1450,310,45);
	glColor3f (0.05, 0.41, 0.278);//樹5
	t1circle(95,350,80);t1circle(250,350,60);t1circle(820,340,70);
	t1circle(1500,340,70);
	glColor3f (0.109, 0.603, 0.478);//地4
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 330);glVertex2i (380, 330);
	glVertex2i (430, 335);glVertex2i (470, 330);glVertex2i (520, 328);
	glVertex2i (1420, 310);glVertex2i (1480, 310);glVertex2i (1560, 320);
	glVertex2i (1580, 328);glVertex2i (1600, 330);glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.113, 0.49, 0.427);//樹2 
	circle(225,300,20);circle(340,310,40);circle(300,325,50);
	ctcircle(250,310,20,1.5);
	glColor3f (0.062, 0.329, 0.376);//樹1 
	circle(40,305,30);circle(130,330,40);circle(167,300,40);
	ctcircle(82,322,30,1.5);
	
	glColor3f (0.13, 0.56, 0.54);//地3
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 290);glVertex2i (80, 295);
	glVertex2i (160, 300);glVertex2i (280, 295);glVertex2i (320, 293);
	glVertex2i (380, 290);glVertex2i (440, 300);glVertex2i (500, 300);
	glVertex2i (560, 300);glVertex2i (690, 305);glVertex2i (1030, 265);
	glVertex2i (1170, 260);glVertex2i (1250, 260);glVertex2i (1320, 260);
	glVertex2i (1420, 270);glVertex2i (1480, 280);glVertex2i (1560, 285);
	glVertex2i (1600, 290);glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.02, 0.46, 0.34);
	glBegin (GL_POLYGON); 
	glVertex2i (1190, 270); glVertex2i (1230,285);glVertex2i (1260,300);
	glVertex2i (1280,300);  glVertex2i (1265,285); glVertex2i (1255,270); 
	glEnd ( );
	
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_POLYGON); 
	glVertex2i(1240,350);glVertex2i(1275,370);glVertex2i(1310,350);
	glVertex2i(1310,340);glVertex2i(1360,340);glVertex2i(1360,320);
	glVertex2i(1310,320);glVertex2i(1300,350);
	glEnd ( );
	glColor3f (0.513, 0.286, 0.23);
	glBegin (GL_POLYGON); 
	glVertex2i(1300,300);glVertex2i(1250,300);glVertex2i(1250,350);
	glVertex2i(1275,360);glVertex2i(1300,350);glVertex2i(1300,330);
	glVertex2i(1360,330);glVertex2i(1360,300);
	glEnd ( );
		glColor3f (0.613, 0.386, 0.33);
	glBegin (GL_POLYGON);
	glVertex2i(1285,300);glVertex2i(1265,300);glVertex2i(1265,310);
	glVertex2i(1285,310);
	glEnd ( );
	
	glColor3f (0.05, 0.396, 0.423);//地2 
	glBegin (GL_POLYGON); 
	glVertex2f (0,0); glVertex2f (0, 250);glVertex2f (80, 260);
	glVertex2f (160, 270);glVertex2f (280, 270);glVertex2f (320, 280);
	glVertex2f (380, 285);glVertex2f (440, 285);glVertex2f (500, 290);
	glVertex2f (560, 295);glVertex2f (620, 295);glVertex2f (690, 300);
	glVertex2f (750, 295);glVertex2f (830, 290);glVertex2f (900, 285);
	glVertex2f (950, 280);glVertex2f (1030, 275);glVertex2f (1090, 280);
	glVertex2f (1170, 275);glVertex2f (1250, 270);glVertex2f (1320, 265);
	glVertex2f (1400, 260);glVertex2f (1480, 255);glVertex2f (1560, 255);
	glVertex2f (1600, 250);glVertex2f (1600, 0); 
	glEnd ( );
	glColor3f (0.06, 0.298, 0.368);//地1 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 120);glVertex2i (80, 110);
	glVertex2i (160, 115);glVertex2i (240, 120);glVertex2i (320, 125);
	glVertex2i (400, 120);glVertex2i (480, 115);glVertex2i (540, 105);
	glVertex2i (560, 108);glVertex2i (640, 115);glVertex2i (660, 125);
	glVertex2i (740, 120);glVertex2i (830, 115);glVertex2i (900, 105);
	glVertex2i (980, 110);glVertex2i (1070, 115);glVertex2i (1120, 110);
	glVertex2i (1180, 120);glVertex2i (1260, 110);glVertex2i (1320, 100);
	glVertex2i (1400, 95);glVertex2i (1480, 95);glVertex2i (1560, 110);
	glVertex2i (1600, 120);glVertex2i (1600, 0); 
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2i (1200, 90);glVertex2i (1150,200);
	glVertex2i (1290,200);glVertex2i (1400, 90);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2i (1150,200);glVertex2i (1290,200);
	glVertex2i (1250,220);glVertex2i (1130,220);
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2i (1250,220);glVertex2i (1130,220);
	glVertex2i (1120,230); glVertex2i (1100,240);  
	glVertex2i (1200,240); glVertex2i (1230,230);	
	glEnd ( );
	glBegin (GL_POLYGON); 
	glVertex2i (1100,240);  glVertex2i (1200,240);
	glVertex2i (1100,275); glVertex2i (1050,275); 	
	glEnd ( );
	
	glColor3f (0.02, 0.278, 0.348);
	glBegin (GL_LINE_STRIP);
	glVertex2i (1190, 120);glVertex2i (1150,200);glVertex2i (1140,210);
	glVertex2i (1130,220);glVertex2i (1120,230); glVertex2i (1100,240);  
	glVertex2i (1090,250); glVertex2i (1070,260);   
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1380, 105);glVertex2i (1290,200);glVertex2i (1270,210);
	glVertex2i (1250,220);glVertex2i (1230,230); glVertex2i (1200,240);  
	glVertex2i (1180,250); glVertex2i (1150,260); glVertex2i (1100,275);  
	glEnd ( );
		glColor3f (0.15, 0.406, 0.453);
	ctcircle(100,60,10,2.5);ctcircle(150,70,10,2.5);ctcircle(200,50,15,2.5);
	ctcircle(250,60,10,2.5);ctcircle(300,40,10,2.5);ctcircle(450,75,13,2.5);
	ctcircle(500,65,10,2.5);ctcircle(650,50,10,2.5);ctcircle(700,40,8,2.5);
	ctcircle(670,30,5,2.5);ctcircle(760,60,10,2.5);ctcircle(800,50,7,2.5);
	
	ctcircle(900,60,10,2.5);ctcircle(950,70,10,2.5);ctcircle(1000,50,15,2.5);
	ctcircle(1050,60,10,2.5);ctcircle(1100,40,10,2.5);ctcircle(1250,75,13,2.5);
	ctcircle(1300,65,10,2.5);ctcircle(1450,50,10,2.5);ctcircle(1500,40,8,2.5);
	ctcircle(1470,30,5,2.5);ctcircle(1560,60,10,2.5);ctcircle(1570,40,7,2.5);
	
	glColor3f (0.701, 0.45, 0.34);//pond
	ctcircle(550,180,55,6);
	ctcircle(500,245,35,6);	
	glColor3f (0.16, 0.66, 0.788);
	ctcircle(550,175,54,6);
	ctcircle(500,240,34,6);
	
	glColor3f (0.33, 0.131, 0.133);//路牌 
	glBegin (GL_POLYGON);
	glVertex2i (1400, 100);glVertex2i (1420,100);glVertex2i (1420,300);
	glVertex2i (1400,300);
	glEnd ( );
	glColor3f (0.23, 0.031, 0.033);	
	glBegin (GL_LINE_LOOP);
	glVertex2i (1400, 100);glVertex2i (1420,100);glVertex2i (1420,300);
	glVertex2i (1400,300);
	glEnd ( );
	glColor3f (0.33, 0.131, 0.133);
	glBegin (GL_POLYGON);
	glVertex2i (1440, 150);glVertex2i (1440,200);glVertex2i (1350,200);
	glVertex2i (1320,175);glVertex2i (1350,150);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1360, 230);glVertex2i (1355,280);glVertex2i (1470,295);
	glVertex2i (1500,270);glVertex2i (1470,245);
	glEnd ( );
	
	glColor3f (0.23, 0.031, 0.033);	
	glBegin (GL_LINE_LOOP);
	glVertex2i (1440, 150);glVertex2i (1440,200);glVertex2i (1350,200);
	glVertex2i (1320,175);glVertex2i (1350,150);
	glEnd ( );
	glBegin (GL_LINE_LOOP);
	glVertex2i (1360, 230);glVertex2i (1355,280);glVertex2i (1470,295);
	glVertex2i (1500,270);glVertex2i (1470,245);
	glEnd ( );
}
void p3::end(){
	int x, y;
	glColor3f (0.1, 0.32, 0.45);//樹，後排 
	circle(180,325,40);circle(380,330,40);ctcircle(460,340,45,1.5);
	circle(525,336,25);circle(570,330,50);ctcircle(640,340,25,1.5);
	circle(710,330,45);circle(760,350,45);ctcircle(820,345,40,1.5);
	ctcircle(1370,315,50,1.5);circle(1450,310,45);
	
	glColor3f (0.109, 0.603, 0.478);//地4
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 330);glVertex2i (380, 330);
	glVertex2i (430, 335);glVertex2i (470, 330);glVertex2i (520, 328);
	glVertex2i (1420, 310);glVertex2i (1480, 310);glVertex2i (1560, 320);
	glVertex2i (1580, 328);glVertex2i (1600, 330);glVertex2i (1600, 0); 
	glEnd ( );
	
	glColor3f (0.05, 0.41, 0.278);//樹5
	t1circle(95,350,80);t1circle(250,350,60);t1circle(1520,340,70);
	
	glColor3f (0.113, 0.49, 0.427);//樹2 
	circle(225,300,20);circle(340,310,40);circle(300,325,50);
	ctcircle(250,310,20,1.5);
	glColor3f (0.062, 0.329, 0.376);//樹1 
	circle(40,305,30);circle(130,330,40);circle(167,300,40);
	ctcircle(82,322,30,1.5);
	
	glColor3f (0.13, 0.56, 0.54);//地3
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 290);glVertex2i (80, 295);
	glVertex2i (160, 300);glVertex2i (280, 295);glVertex2i (320, 293);
	glVertex2i (380, 290);glVertex2i (440, 300);glVertex2i (500, 300);
	glVertex2i (560, 300);glVertex2i (690, 305);glVertex2i (1030, 265);
	glVertex2i (1170, 260);glVertex2i (1250, 260);glVertex2i (1320, 260);
	glVertex2i (1420, 270);glVertex2i (1480, 280);glVertex2i (1560, 285);
	glVertex2i (1600, 290);glVertex2i (1600, 0); 
	glEnd ( );
	
	glColor3f (0.039, 0.274, 0.313);//樹4 
	circle(1030,470,35);circle(990,468,20);circle(965,440,30);
	circle(935,380,50);ctcircle(920,310,60,1.5);circle(1175,400,40);
	circle(1070,430,35);ctcircle(1130,410,35,1.5);
	glBegin (GL_POLYGON); 
	glVertex2i (990, 470);glVertex2i (1180,375); glVertex2i (1110, 240);
	glVertex2i (910, 255); 
	glEnd ( );
	glColor3f (0.05, 0.396, 0.423);//地2 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 250);glVertex2i (80, 260);
	glVertex2i (160, 256);glVertex2i (280, 260);glVertex2i (320, 255);
	glVertex2i (380, 253
	);glVertex2i (440, 250);glVertex2i (500, 255);
	glVertex2i (560, 250);glVertex2i (620, 245);glVertex2i (690, 245);
	glVertex2i (750, 250);glVertex2i (830, 255);glVertex2i (900, 260);
	glVertex2i (950, 270);glVertex2i (1030, 265);glVertex2i (1090, 260);
	glVertex2i (1170, 250);glVertex2i (1250, 250);glVertex2i (1320, 255);
	glVertex2i (1400, 255);glVertex2i (1480, 253);glVertex2i (1560, 250);
	glVertex2i (1600, 250);glVertex2i (1600, 0); 
	glEnd ( );
	
	
	glColor3f (0.113, 0.49, 0.427);//樹3 
	circle(1220,365,40);circle(1270,330,45);circle(1180,332,50);
	ctcircle(1135,285,35,1.5);circle(1320,310,20);ctcircle(1355,280,35,1.5);
	glBegin (GL_POLYGON); 
	glVertex2i (1355, 255);glVertex2i (1320, 250);glVertex2i (1260, 250);
	glVertex2i (1210, 245);glVertex2i (1170, 250);glVertex2i (1125, 260);
	glVertex2i (1110, 270);glVertex2i (1220, 360);glVertex2i (1355, 280);
	glEnd ( );
	
	
	glColor3f (0.06, 0.298, 0.368);//地1 
	glBegin (GL_POLYGON); 
	glVertex2i (0,0); glVertex2i (0, 120);glVertex2i (80, 110);
	glVertex2i (160, 115);glVertex2i (240, 120);glVertex2i (320, 125);
	glVertex2i (400, 120);glVertex2i (480, 115);glVertex2i (540, 105);
	glVertex2i (560, 108);glVertex2i (640, 115);glVertex2i (660, 125);
	glVertex2i (740, 120);glVertex2i (830, 115);glVertex2i (900, 105);
	glVertex2i (980, 110);glVertex2i (1070, 115);glVertex2i (1120, 110);
	glVertex2i (1180, 120);glVertex2i (1260, 110);glVertex2i (1320, 100);
	glVertex2i (1400, 95);glVertex2i (1480, 95);glVertex2i (1560, 110);
	glVertex2i (1600, 120);glVertex2i (1600, 0); 
	glEnd ( );
		glColor3f (0.15, 0.406, 0.453);
	ctcircle(100,60,10,2.5);ctcircle(150,70,10,2.5);ctcircle(200,50,15,2.5);
	ctcircle(250,60,10,2.5);ctcircle(300,40,10,2.5);ctcircle(450,75,13,2.5);
	ctcircle(500,65,10,2.5);ctcircle(650,50,10,2.5);ctcircle(700,40,8,2.5);
	ctcircle(670,30,5,2.5);ctcircle(760,60,10,2.5);ctcircle(800,50,7,2.5);
	
	ctcircle(900,60,10,2.5);ctcircle(950,70,10,2.5);ctcircle(1000,50,15,2.5);
	ctcircle(1050,60,10,2.5);ctcircle(1100,40,10,2.5);ctcircle(1250,75,13,2.5);
	ctcircle(1300,65,10,2.5);
	
	glLineWidth(3);
	glColor3f (0.29, 0.129, 0.13);//房子 
	glBegin (GL_LINE_STRIP);
	glVertex2i (1600, 750);glVertex2i (1600,720);glVertex2i (1130,530);
	glVertex2i (1110,550);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1190, 560);glVertex2i (1210,570);glVertex2i (1210,150);
	glVertex2i (1190,150);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1300, 300);glVertex2i (1310,300);glVertex2i (1310,150);
	glVertex2i (1300,150);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1400, 300);glVertex2i (1410,300);glVertex2i (1410,150);
	glVertex2i (1400,150);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1500, 300);glVertex2i (1510,300);glVertex2i (1510,150);
	glVertex2i (1500,150);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1590, 300);glVertex2i (1600,300);glVertex2i (1600,150);
	glVertex2i (1590,150);
	glEnd ( );
	glBegin (GL_LINE_STRIP);
	glVertex2i (1210, 310);glVertex2i (1600,310);glVertex2i (1600,285);
	glVertex2i (1210,285);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1600, 750);glVertex2i (1600,700);glVertex2i (1140,510);
	glVertex2i (1110,550);
	glEnd ( );
	glColor3f (0.33, 0.231, 0.223);//房子 
	glBegin (GL_POLYGON);
	glVertex2i (1600, 750);glVertex2i (1600,720);glVertex2i (1130,530);
	glVertex2i (1110,550);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1190, 530);glVertex2i (1210,540);glVertex2i (1210,150);
	glVertex2i (1190,150);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1300, 300);glVertex2i (1310,300);glVertex2i (1310,150);
	glVertex2i (1300,150);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1400, 300);glVertex2i (1410,300);glVertex2i (1410,150);
	glVertex2i (1400,150);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1500, 300);glVertex2i (1510,300);glVertex2i (1510,150);
	glVertex2i (1500,150);
	glEnd ( );
		glBegin (GL_POLYGON);
	glVertex2i (1590, 300);glVertex2i (1600,300);glVertex2i (1600,150);
	glVertex2i (1590,150);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1210, 310);glVertex2i (1600,310);glVertex2i (1600,285);
	glVertex2i (1210,285);
	glEnd ( );
	glColor3f (0.25, 0.181, 0.173);
	glBegin (GL_POLYGON);
	glVertex2i (1190, 150);glVertex2i (1600,150);glVertex2i (1600,50);
	glVertex2i (1190,50);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1190, 130);glVertex2i (1100,130);glVertex2i (1100,50);
	glVertex2i (1190,50);
	glEnd ( );
	glBegin (GL_POLYGON);
	glVertex2i (1100, 100);glVertex2i (1010,100);glVertex2i (1010,50);
	glVertex2i (1100,50);
	glEnd ( );
	
	glLineWidth(0.001f); 
	if(isEnd){
		for(int j=0; j<5; j++)
		{
			if(j==0) glColor3f(0.9757, 0.1234, 0.1457);
			else if(j==1) glColor3f(0.7757, 0.3734, 0.1457);
			else if(j==2) glColor3f(0.7757, 0.7734, 0.1457);
			else if(j==3) glColor3f(0.1757, 0.7734, 0.1457);
			else if(j==4) glColor3f(0.1757, 0.1734, 0.7457);
			glBegin(GL_POLYGON);
				glVertex2f(1220+85*j,900-272+35*j);
				glVertex2f(1210+85*j,900-272+35*j);
				glVertex2f(1215+85*j,900-257+35*j);
			glEnd();
			glBegin(GL_POLYGON);
				for(int i=0; i<2000; i++)  
				{ 
					x=42*cos(2*i*PI/2000)+1225;
					y=55*sin(2*i*PI/2000)+900-204;
		   			glVertex2f(x-10+85*j,y+35*j); 
		   		}  
			glEnd();
			glColor3f(0, 0, 0);
			glBegin(GL_LINE_STRIP);
				for(int i=0; i<2000; i++)  
				{ 
					x=12*cos(i*PI/2000+0.5*PI)+1225+5;
					y=25*sin(i*PI/2000+0.5*PI)+900-330;
		   			glVertex2f(x-10+85*j,y+35*j); 
		   		}  
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1215+85*j,900-305+35*j);
				glVertex2f(1215+85*j,900-272+35*j);
			glEnd();
			glBegin(GL_LINE_LOOP);
				glVertex2f(1220+85*j,900-272+35*j);
				glVertex2f(1210+85*j,900-272+35*j);
				glVertex2f(1215+85*j,900-257+35*j);
			glEnd();
			glBegin(GL_LINE_STRIP);
				for(int i=0; i<2000; i++)  
				{ 
					x=42*cos(2*i*PI/2000)+1225;
					y=55*sin(2*i*PI/2000)+900-204;
		   			glVertex2f(x-10+85*j,y+35*j); 
		   		}  
			glEnd();
		}
		for(int j=0; j<4; j++)
		{
			if(j==0) glColor3f(1, 1, 1);
			else if(j==1) glColor3f(1, 0, 0);
			else if(j==2) glColor3f(1, 0.5, 0);
			else if(j==3) glColor3f(1, 1, 0);
			glBegin(GL_LINE_STRIP);
				for(int i=0; i<2000; i++)  
				{ 
					x=178*cos(-0.77*i*PI/2000)+1357;
					y=(200+25*j)*sin(-(0.77+0.025*j)*i*PI/2000)+900-231;
			   		glVertex2f(x-10+60*j,y+26*j); 
			   	}  
			glEnd();
		}
		for(int j=0; j<4; j++)
		{
			if(j==0) glColor3f(1, 1, 1);
			else if(j==1) glColor3f(1, 0, 0);
			else if(j==2) glColor3f(1, 0.5, 0);
			else if(j==3) glColor3f(1, 1, 0);
			glBegin(GL_LINE_STRIP);
				for(int i=0; i<2000; i++)  
				{ 
					x=178*cos(-0.77*i*PI/2000-0.19*PI)+1649;
					y=200*sin(-0.77*i*PI/2000-0.19*PI)+900-231;
			   		glVertex2f(x-10+60*j,y+26*j); 
			   	}  
			glEnd();
		}
		
		glLineWidth(1);
		/*****************往右*******************/ 
		glPushMatrix ();
		glTranslatef(199,0,0);
		
		
		glLineWidth(0.001f); 
			
		//盤子陰影
		glColor3f(0.0784, 0.2, 0.2);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{ 
				x=245*cos(2*i*PI/2000)+960;
				y=81*sin(2*i*PI/2000)+140;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		//盤子 
		glColor3f(1, 0.8823, 0.8039);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{
				x=240*cos(2*i*PI/2000)+998;
				y=76*sin(2*i*PI/2000)+150;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_STRIP);
			for(int i=0; i<2000; i++)  
			{  
				x=240*cos(2*i*PI/2000)+998;
				y=76*sin(2*i*PI/2000)+150;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		//蛋糕底層 
		glColor3f(0.8392, 0.6392, 0.4156);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{
				x=159*cos(2*i*PI/2000)+998;
				y=43*sin(2*i*PI/2000)+150;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f((159*cos(2*PI)+998)*0.4+280,(43*sin(2*PI)+150)*0.4);
	   		glVertex2f((157*cos(2*PI)+998)*0.4+280,(38*sin(2*PI)+270)*0.4);
	   		glVertex2f((157*cos(  PI)+998)*0.4+280,(38*sin(  PI)+270)*0.4);
	   		glVertex2f((159*cos(  PI)+998)*0.4+280,(43*sin(  PI)+150)*0.4);	
	   	glEnd();
	   	glColor3f(0, 0, 0);
		glBegin(GL_LINE_STRIP);
			for(int i=0; i<2000; i++)  
			{
				x=159*cos(i*PI/2000+PI)+998;
				y=43*sin(i*PI/2000+PI)+150;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}
		glEnd();
		glBegin(GL_LINE_STRIP);
			glVertex2f((159*cos(2*PI)+998)*0.4+280,(43*sin(2*PI)+150)*0.4);
	   		glVertex2f((157*cos(2*PI)+998)*0.4+280,(38*sin(2*PI)+270)*0.4);
	   		glVertex2f((157*cos(  PI)+998)*0.4+280,(38*sin(  PI)+270)*0.4);
	   		glVertex2f((159*cos(  PI)+998)*0.4+280,(43*sin(  PI)+150)*0.4);	
	   	glEnd();
		//蛋糕上層 
		glColor3f(0.9058, 0.7568, 0.5803);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{
				x=157*cos(2*i*PI/2000)+998;
				y=38*sin(2*i*PI/2000)+270;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_STRIP);
			for(int i=0; i<2000; i++)  
			{  
				x=157*cos(i*PI/2000)+998;
				y=38*sin(i*PI/2000)+270;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		//紋路 
		glColor3f(0.6353, 0.4863, 0.4039);
		glBegin(GL_LINE_STRIP);
			for(int i=0; i<2000; i++) 
			{  
				x=157*cos(0.65*i*PI/2000+1.1*PI)+998;
				y=38*sin(0.65*i*PI/2000+1.1*PI)+275;
	   			glVertex2f(0.4*x+280,0.4*y);  
	   		}  
		glEnd();
		//蠟燭
		glColor3f(0.9852, 0.9312, 0.1145);
		glBegin(GL_POLYGON);
			glVertex2f(675,137);
			glVertex2f(683,137);
			glVertex2f(683,110);
			glVertex2f(675,110);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(675,137);
			glVertex2f(683,137);
			glVertex2f(683,110);
			glVertex2f(675,110);
		glEnd();
		//火 
		glColor3f(0.9854, 0.4312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{
				x=fire[i][0]+12;
				y=fire[i][1]+48;
			   	glVertex2f(0.4*x+280,0.4*y+20);
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	x=fire[i][0]+12;
				y=fire[i][1]+48;
			   	glVertex2f(0.4*x+280,0.4*y+20);
			}  
		glEnd();
		
		//白色身體
		glColor3f(0.9784, 0.9745, 0.9736);
		glBegin(GL_POLYGON);
			glVertex2f(545,900-824);
			for(int i=0; i<23; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
			 
		glEnd();
		glBegin(GL_POLYGON);
			for(int i=23; i<28; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<23; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}  
		glEnd();
		glBegin(GL_LINE_LOOP);
			for(int i=23; i<28; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		//白色眼睛
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{ 
				x=4*cos(2*i*PI/2000)+569;
				y=4*sin(2*i*PI/2000)+900-803;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<2000; i++)  
			{ 
				x=4*cos(2*i*PI/2000)+569;
				y=4*sin(2*i*PI/2000)+900-803;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{ 
				x=2*cos(2*i*PI/2000)+570;
				y=2*sin(2*i*PI/2000)+900-803;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		//藍色身體
		glColor3f(0.3411, 0.4078, 0.4862);
		glBegin(GL_POLYGON);
			for(int i=28; i<33; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0.3411, 0.4078, 0.4862);
		glBegin(GL_POLYGON);
			for(int i=72; i<77; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=28; i<33; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glBegin(GL_LINE_LOOP);
			for(int i=72; i<77; i++) 
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0.3411, 0.4078, 0.4862);
		glBegin(GL_POLYGON);
			glVertex2f(470,900-822);
			for(int i=33; i<72; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0.9784, 0.9745, 0.9736);
		glBegin(GL_POLYGON);
			for(int i=77; i<93; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0.3411, 0.4078, 0.4862);
		glBegin(GL_POLYGON);
			glVertex2f(503,900-779);
			for(int i=93; i<102; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glBegin(GL_POLYGON);
			for(int i=102; i<107; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=33; i<72; i++) 
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glBegin(GL_LINE_LOOP);
			for(int i=77; i<93; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glBegin(GL_LINE_LOOP);
			for(int i=93; i<102; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		
		glBegin(GL_LINE_LOOP);
			for(int i=102; i<107; i++)  
			{ 
	   			glVertex2f(small_cat[i][0]-10,small_cat[i][1]);  
	   		}
		glEnd();
		//藍色眼睛
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{ 
				x=3*cos(2*i*PI/2000)+496;
				y=5*sin(2*i*PI/2000)+900-750;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<2000; i++)  
			{ 
				x=3*cos(2*i*PI/2000)+496;
				y=5*sin(2*i*PI/2000)+900-750;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		glBegin(GL_POLYGON);
			for(int i=0; i<2000; i++)  
			{ 
				x=2*cos(2*i*PI/2000)+498;
				y=2*sin(2*i*PI/2000)+900-751;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(int i=0; i<2000; i++)  
			{ 
				x=7*cos(i*PI/2000+PI)+467;
				y=15*sin(i*PI/2000+PI)+900-781;
	   			glVertex2f(x-10,y);  
	   		}  
		glEnd();
		/*****************大梅********************/
		glTranslatef(-7,40,0);
		glColor3f (0.588, 0.078, 0.129);
		glBegin (GL_LINE_LOOP);//衣服 
		glVertex2f (800+49,250-62);glVertex2f (800+45,250-65);glVertex2f (800+42,250-68);
		glVertex2f (800+40,250-71);glVertex2f (800+38,250-73);glVertex2f (800+37,250-78);
		glVertex2f (800+38,250-83);glVertex2f (800+41,250-88);glVertex2f (800+46,250-92);
		glVertex2f (800+60,250-89);glVertex2f (800+79,250-121);glVertex2f (800+74,250-126);
		glVertex2f (800+65,250-132);glVertex2f (800+55,250-136);glVertex2f (800+45,250-137);
		glVertex2f (800+37,250-136);glVertex2f (800+27,250-132);glVertex2f (800+20,250-130);
		glVertex2f (800+13,250-126);glVertex2f (800+12,250-119);glVertex2f (800+15,250-106);
		glVertex2f (800+18,250-98);glVertex2f (800+19,250-91);glVertex2f (800+24,250-83);
		glVertex2f (800+28,250-74);glVertex2f (800+37,250-69);glVertex2f (800+48,250-63);
		glEnd ( );
		glColor3f (1.0,1.0,1.0);
		glBegin (GL_LINE_LOOP);//衣服白 
		glVertex2f (800+51,250-58);glVertex2f (800+39,250-59);glVertex2f (800+33,250-64);
		glVertex2f (800+41,250-65);
		glEnd ( );
		glBegin (GL_LINE_LOOP);//衣服白 
		glVertex2f (800+51,250-63);glVertex2f (800+46,250-65);glVertex2f (800+41,250-70);
		glVertex2f (800+38,250-75);glVertex2f (800+39,250-85);glVertex2f (800+43,250-90);
		glVertex2f (800+46,250-92);glVertex2f (800+48,250-94);glVertex2f (800+59,250-93);
		glVertex2f (800+59,250-89);glVertex2f (800+61,250-86);glVertex2f (800+63,250-82);
		glVertex2f (800+63,250-75);glVertex2f (800+60,250-68);glVertex2f (800+55,250-65);
		glEnd ( );
		glColor3f (0.8,0.372,0.041);
		glBegin (GL_LINE_LOOP);//包包 
		glVertex2f (800+63,250-86);glVertex2f (800+66,250-93);glVertex2f (800+68,250-96);
		glVertex2f (800+80,250-105);glVertex2f (800+79,250-109);glVertex2f (800+72,250-118);
		glVertex2f (800+67,250-112);glVertex2f (800+67,250-105);glVertex2f (800+61,250-102);
		glVertex2f (800+59,250-89);
		glEnd ( );
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+36,250-67);glVertex2f (800+29,250-68);glVertex2f (800+28,250-75);
		glVertex2f (800+34,250-72);
		glEnd ( );
			glColor3f (0.213,0.125,0.078);
		glBegin (GL_LINE_STRIP);//頭髮 
		glVertex2f (800+64,250-10);
		glVertex2f (800+72,250-16);glVertex2f (800+78,250-26);glVertex2f (800+79,250-36);
		glVertex2f (800+77,250-40);glVertex2f (800+73,250-43);glVertex2f (800+65,250-49);
		glVertex2f (800+61,250-52);
		glVertex2f (800+53,250-55);glVertex2f (800+48,250-50);glVertex2f (800+47,250-29);
		glVertex2f (800+44,250-25);	glVertex2f (800+37,250-14);glVertex2f (800+40,250-22);
		glVertex2f (800+37,250-16);glVertex2f (800+40,250-5);glVertex2f (800+48,250-2);;
		glVertex2f (800+54,250-5);glVertex2f (800+62,250-9);
		glEnd ( );
		glBegin (GL_LINE_STRIP);//頭髮 
		glVertex2f (800+62,250-51);glVertex2f (800+62,250-9);glVertex2f (800+68,250-64);
		glVertex2f (800+84,250-69);glVertex2f (800+87,250-58);glVertex2f (800+84,250-48);
		glVertex2f (800+78,250-42);
		glEnd ( );
	
	
	
		
		glColor3f (0.96, 0.764, 0.53);//臉 
		glBegin (GL_POLYGON);
		glVertex2f (800+36,250-8);glVertex2f (800+30,250-11);glVertex2f (800+26,250-25);
		glVertex2f (800+24,250-27);glVertex2f (800+18,250-32);glVertex2f (800+20,250-35);
		glVertex2f (800+18,250-38);glVertex2f (800+20,250-44);glVertex2f (800+24,250-50);
		glVertex2f (800+31,250-53);glVertex2f (800+38,250-55);glVertex2f (800+42,250-55);
		glVertex2f (800+47,250-55);glVertex2f (800+48,250-50);glVertex2f (800+51,250-49);
		glVertex2f (800+53,250-47);glVertex2f (800+54,250-43);glVertex2f (800+53,250-40);
		glVertex2f (800+50,250-42);glVertex2f (800+48,250-46);glVertex2f (800+48,250-40);
		glVertex2f (800+48,250-33);glVertex2f (800+44,250-26);glVertex2f (800+40,250-16);
		glEnd ( );
		glBegin (GL_POLYGON);
		glVertex2f (800+36,250-137);glVertex2f (800+37,250-145);glVertex2f (800+38,250-152);
		glVertex2f (800+39,250-160);glVertex2f (800+53,250-161);glVertex2f (800+51,250-154);
		glVertex2f (800+50,250-148);glVertex2f (800+50,250-142);glEnd ( );
		glBegin (GL_POLYGON);
		glVertex2f (800+39,250-164);glVertex2f (800+41,250-165);
		glVertex2f (800+41,250-172);glVertex2f (800+41,250-179);glVertex2f (800+41,250-183);
		glVertex2f (800+41,250-183);glVertex2f (800+40,250-185);glVertex2f (800+41,250-188);
		glVertex2f (800+42,250-189);glVertex2f (800+46,250-189);glVertex2f (800+51,250-188);
		glVertex2f (800+52,250-180);glVertex2f (800+53,250-169);glVertex2f (800+53,250-161);
		glVertex2f (800+51,250-154);glVertex2f (800+50,250-148);glVertex2f (800+50,250-142);
		glEnd ( );
		glBegin (GL_POLYGON);
		glVertex2f (800+50,250-142);glVertex2f (800+57,250-136);glVertex2f (800+58,250-145);
		glVertex2f (800+60,250-150);glVertex2f (800+60,250-158);glVertex2f (800+60,250-164);
		glVertex2f (800+59,250-186);glVertex2f (800+51,250-186);
		glEnd ( );
		glColor3f (0.4, 0.3, 0.2);
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+36,250-8);glVertex2f (800+30,250-11);glVertex2f (800+26,250-25);
		glVertex2f (800+24,250-27);glVertex2f (800+18,250-32);glVertex2f (800+20,250-35);
		glVertex2f (800+18,250-38);glVertex2f (800+20,250-44);glVertex2f (800+24,250-50);
		glVertex2f (800+31,250-53);glVertex2f (800+38,250-55);glVertex2f (800+42,250-55);
		glVertex2f (800+47,250-55);glVertex2f (800+48,250-50);glVertex2f (800+51,250-49);
		glVertex2f (800+53,250-47);glVertex2f (800+54,250-43);glVertex2f (800+53,250-40);
		glVertex2f (800+50,250-42);glVertex2f (800+48,250-46);glVertex2f (800+48,250-40);
		glVertex2f (800+48,250-33);glVertex2f (800+44,250-26);glVertex2f (800+40,250-16);
		glEnd ( );
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+36,250-137);glVertex2f (800+37,250-145);glVertex2f (800+38,250-152);
		glVertex2f (800+39,250-160);glVertex2f (800+39,250-164);glVertex2f (800+41,250-165);
		glVertex2f (800+41,250-172);glVertex2f (800+41,250-179);glVertex2f (800+41,250-183);
		glVertex2f (800+39,250-183);glVertex2f (800+37,250-185);glVertex2f (800+39,250-188);
		glVertex2f (800+42,250-189);glVertex2f (800+46,250-189);glVertex2f (800+51,250-188);
		glVertex2f (800+52,250-180);glVertex2f (800+53,250-169);glVertex2f (800+53,250-161);
		glVertex2f (800+51,250-154);glVertex2f (800+50,250-148);glVertex2f (800+50,250-142);
		glEnd ( );
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+50,250-142);glVertex2f (800+57,250-136);glVertex2f (800+58,250-145);
		glVertex2f (800+60,250-150);glVertex2f (800+60,250-158);glVertex2f (800+60,250-164);
		glVertex2f (800+59,250-186);glVertex2f (800+51,250-186);
		glEnd ( );
		glColor3f (0.788, 0.278, 0.329);
		glBegin (GL_POLYGON);//衣服 
		glVertex2f (800+49,250-62);glVertex2f (800+45,250-65);glVertex2f (800+42,250-68);
		glVertex2f (800+40,250-71);glVertex2f (800+38,250-73);glVertex2f (800+37,250-78);
		glVertex2f (800+38,250-83);glVertex2f (800+41,250-88);glVertex2f (800+46,250-92);
		glVertex2f (800+60,250-89);glVertex2f (800+79,250-121);glVertex2f (800+74,250-126);
		glVertex2f (800+65,250-132);glVertex2f (800+55,250-136);glVertex2f (800+45,250-137);
		glVertex2f (800+37,250-136);glVertex2f (800+27,250-132);glVertex2f (800+20,250-130);
		glVertex2f (800+13,250-126);glVertex2f (800+12,250-119);glVertex2f (800+15,250-106);
		glVertex2f (800+18,250-98);glVertex2f (800+19,250-91);glVertex2f (800+24,250-83);
		glVertex2f (800+28,250-74);glVertex2f (800+37,250-69);glVertex2f (800+48,250-63);
		glEnd ( );
		glColor3f (1.0,1.0,1.0);
		glBegin (GL_POLYGON);//衣服白 
		glVertex2f (800+51,250-58);glVertex2f (800+39,250-59);glVertex2f (800+33,250-64);
		glVertex2f (800+41,250-65);
		glEnd ( );
		glBegin (GL_POLYGON);//衣服白 
		glVertex2f (800+51,250-63);glVertex2f (800+46,250-65);glVertex2f (800+41,250-70);
		glVertex2f (800+38,250-75);glVertex2f (800+39,250-85);glVertex2f (800+43,250-90);
		glVertex2f (800+46,250-92);glVertex2f (800+48,250-94);glVertex2f (800+59,250-93);
		glVertex2f (800+59,250-89);glVertex2f (800+61,250-86);glVertex2f (800+63,250-82);
		glVertex2f (800+63,250-75);glVertex2f (800+60,250-68);glVertex2f (800+55,250-65);
		glEnd ( );
		glColor3f (1.0,0.572,0.141);
		glBegin (GL_POLYGON);//包包 
		glVertex2f (800+63,250-86);glVertex2f (800+66,250-93);glVertex2f (800+68,250-96);
		glVertex2f (800+80,250-105);glVertex2f (800+79,250-109);glVertex2f (800+72,250-118);
		glVertex2f (800+67,250-112);glVertex2f (800+67,250-105);glVertex2f (800+61,250-102);
		glVertex2f (800+59,250-89);
		glEnd ( );
		glBegin (GL_POLYGON);
		glVertex2f (800+36,250-67);glVertex2f (800+29,250-68);glVertex2f (800+28,250-75);
		glVertex2f (800+34,250-72);
		glEnd ( );
			glColor3f (0.513,0.325,0.278);
		glBegin (GL_POLYGON);//頭髮 
		glVertex2f (800+64,250-10);glVertex2f (800+72,250-16);glVertex2f (800+78,250-26);
		glVertex2f (800+79,250-36);glVertex2f (800+77,250-40);glVertex2f (800+73,250-43);
		glVertex2f (800+65,250-49);	glVertex2f (800+61,250-52);glVertex2f (800+53,250-55);
		glVertex2f (800+48,250-50);glVertex2f (800+47,250-29);glVertex2f (800+44,250-25);
		glVertex2f (800+37,250-14);glVertex2f (800+40,250-22);glVertex2f (800+37,250-16);
		glVertex2f (800+40,250-5);glVertex2f (800+48,250-2);;glVertex2f (800+54,250-5);
		glVertex2f (800+62,250-9);
		glEnd ( );
		glBegin (GL_POLYGON);//頭髮 
		glVertex2f (800+62,250-51);glVertex2f (800+62,250-9);glVertex2f (800+68,250-64);
		glVertex2f (800+84,250-69);glVertex2f (800+87,250-58);glVertex2f (800+84,250-48);
		glVertex2f (800+78,250-42);
		glEnd ( );
		glColor3f (0.96, 0.764, 0.53);//手 
		glBegin (GL_POLYGON);
		glVertex2f (800+47,250-94);glVertex2f (800+47,250-102);glVertex2f (800+45,250-105);
		glVertex2f (800+45,250-117);glVertex2f (800+44,250-120);glVertex2f (800+44,250-131);
		glVertex2f (800+49,250-131);glVertex2f (800+49,250-125);glVertex2f (800+50,250-118);
		glVertex2f (800+53,250-114);glVertex2f (800+56,250-107);glVertex2f (800+58,250-103);
		glVertex2f (800+57,250-94);
		glEnd ( );
			glColor3f (0.4, 0.3, 0.2);//手 
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+47,250-94);glVertex2f (800+47,250-102);glVertex2f (800+45,250-105);
		glVertex2f (800+45,250-117);glVertex2f (800+44,250-120);glVertex2f (800+44,250-131);
		glVertex2f (800+49,250-131);glVertex2f (800+49,250-125);glVertex2f (800+50,250-118);
		glVertex2f (800+53,250-114);glVertex2f (800+56,250-107);glVertex2f (800+58,250-103);
		glVertex2f (800+57,250-94);
		glEnd ( );
		glColor3f (1, 0.81, 0.191);//鞋子 
		glBegin (GL_POLYGON);
		glVertex2f (800+55,250-193);glVertex2f (800+58,250-193);glVertex2f (800+59,250-187);
		glVertex2f (800+53,250-188);glVertex2f (800+50,250-189);
		glEnd ( );
		glBegin (GL_POLYGON);
		glVertex2f (800+34,250-185);glVertex2f (800+27,250-188);glVertex2f (800+27,250-193);
		glVertex2f (800+53,250-195);glVertex2f (800+52,250-189);
		glEnd ( );
			
		glColor3f (0.4, 0.21, 0.01);//鞋子 
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+55,250-193);glVertex2f (800+58,250-193);glVertex2f (800+59,250-187);
		glVertex2f (800+53,250-188);glVertex2f (800+50,250-189);
		glEnd ( );
		glBegin (GL_LINE_LOOP);
		glVertex2f (800+34,250-185);glVertex2f (800+27,250-188);glVertex2f (800+27,250-193);
		glVertex2f (800+53,250-195);glVertex2f (800+52,250-189);
		glEnd ( );
	
		circle(832,250-28,2);circle(832,250-30,2);
		
		
		
		glPopMatrix(); 
		glPushMatrix ();
	}
		
	
	
	
}
void p3::hole(){
	glColor3f (0.121, 0.368, 0.262);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0); 
	glVertex2i (0, 900);
 	glVertex2i (1600, 900); 
	glVertex2i (1600, 0); 
	glEnd ( );
	glColor3f (0.08, 0.2, 0.2);
	float g[][2]={{450, 220},{420, 250},{400, 300},{390, 350},{380, 390},{385, 420},{395, 445},{400, 470},{395, 500},{410, 550},
	{430, 620},{450, 700},{470, 755},{510, 800},{580, 830},{600, 840},{620, 850},{700, 870},{780, 865},{830, 850},{910, 830},
	{930, 750},{960, 680},{990, 620},{1010, 560},{1000, 520},{1010, 440},{1010, 400},{1010, 370},{1010, 310},{1000, 260},
	{950, 220},{830, 200},{550, 210}};
	glBegin(GL_POLYGON);
	int n=34;
	for(int i=1; i<n; i++){
		
		glVertex2f (g[i][0], g[i][1]);
	}
	glEnd();
	glLineWidth(2);
	glColor3f (0.05, 0.15, 0.15);
		glBegin(GL_LINE_LOOP);
		for(int i=1; i<n; i++){
		glVertex2f (g[i][0], g[i][1]);
	}
	glEnd();
		
	glColor3f (0.6, 0.776, 0.37);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0);glVertex2i (0, 140);glVertex2i (1600, 140); glVertex2i (1600, 0); 
	glEnd ( );
	
	glLineWidth(3);
	glColor3f (0.227, 0.231, 0.211);
	glBegin (GL_LINE_LOOP); 
	glVertex2i (1100, 120); glVertex2i (1100, 900);glVertex2i (1200, 900); glVertex2i (1200, 120); 
	glEnd (); 
	glBegin (GL_LINE_LOOP); 
	glVertex2i (1110, 170); glVertex2i (1090, 140);glVertex2i (1080, 120); glVertex2i (1060, 100);
	glVertex2i (1100, 120);glVertex2i (1150, 160);
	glEnd ();
	glBegin (GL_LINE_LOOP); 
 	glVertex2i (1190, 170);glVertex2i (1210, 140);glVertex2i (1220, 120);glVertex2i (1230, 100);
	glVertex2i (1190, 120);glVertex2i (1150, 160);
	glEnd (); 
	glBegin (GL_LINE_LOOP); 
 	glVertex2i (1110, 150);	glVertex2i (1190, 150);glVertex2i (1150, 100);
	glEnd (); 
	glBegin (GL_LINE_LOOP); 
	glVertex2i (200, 120); glVertex2i (200, 900);glVertex2i (300, 900); glVertex2i (300, 120); 
	glEnd (); 
	glBegin (GL_LINE_LOOP); 
	glVertex2i (300, 170); glVertex2i (310, 140);glVertex2i (320, 120); glVertex2i (330, 100);
	glVertex2i (300, 120);glVertex2i (250, 160);
	glEnd ();
	glBegin (GL_LINE_LOOP); 
	glVertex2i (210, 170); glVertex2i (190, 140);glVertex2i (180, 120); glVertex2i (160, 100);
	glVertex2i (210, 120);glVertex2i (250, 160);
	glEnd ();
	glBegin (GL_LINE_LOOP); 
 	glVertex2i (210, 150);	glVertex2i (300, 150);glVertex2i (250, 100);
	glEnd (); 
	glColor3f (0.427, 0.431, 0.411);
	glBegin (GL_POLYGON); 
	glVertex2i (1100, 120); glVertex2i (1100, 900);glVertex2i (1200, 900); glVertex2i (1200, 120); 
	glEnd (); 
	glBegin (GL_POLYGON); 
	glVertex2i (1110, 170); glVertex2i (1090, 140);glVertex2i (1080, 120); glVertex2i (1060, 100);
	glVertex2i (1100, 120);glVertex2i (1150, 160);
	glEnd ();
	glBegin (GL_POLYGON); 
 	glVertex2i (1190, 170);glVertex2i (1210, 140);glVertex2i (1220, 120);glVertex2i (1230, 100);
	glVertex2i (1190, 120);glVertex2i (1150, 160);
	glEnd (); 
	glBegin (GL_POLYGON); 
 	glVertex2i (1110, 150);	glVertex2i (1190, 150);glVertex2i (1150, 100);
	glEnd (); 
	glBegin (GL_POLYGON); 
	glVertex2i (200, 120); glVertex2i (200, 900);glVertex2i (300, 900); glVertex2i (300, 120); 
	glEnd (); 
	glBegin (GL_POLYGON); 
	glVertex2i (300, 170); glVertex2i (310, 140);glVertex2i (320, 120); glVertex2i (330, 100);
	glVertex2i (300, 120);glVertex2i (250, 160);
	glEnd ();
	glBegin (GL_POLYGON); 
	glVertex2i (210, 170); glVertex2i (190, 140);glVertex2i (180, 120); glVertex2i (160, 100);
	glVertex2i (210, 120);glVertex2i (250, 160);
	glEnd ();
	glBegin (GL_POLYGON); 
 	glVertex2i (210, 150);	glVertex2i (300, 150);glVertex2i (250, 100);
	glEnd (); 
	

	glColor3f (0.184, 0.462, 0.337);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f (790,870);glVertex2f (790,860);glVertex2f (790,845);glVertex2f (810,830);
	glVertex2f (820,835);glVertex2f (830,820);glVertex2f (845,835);glVertex2f (850,830);
	glVertex2f (860,840);glVertex2f (870,865);glVertex2f (860,870);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (900,840);glVertex2f (870,800);glVertex2f (920,810);glVertex2f (900,750);
	glVertex2f (950,740);glVertex2f (920,720);glVertex2f (970,670);
	glEnd();
	glColor3f (0.08, 0.168, 0.172);
	glBegin(GL_POLYGON);
	glVertex2f (195,300);glVertex2f (200,450);glVertex2f (215,450);glVertex2f (215,300);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (200,500);glVertex2f (200,550);glVertex2f (215,550);glVertex2f (215,500);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (200,700);glVertex2f (200,800);glVertex2f (220,800);glVertex2f (220,700);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (200,800);glVertex2f (200,850);glVertex2f (215,850);glVertex2f (215,800);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (260,310);glVertex2f (200,300);glVertex2f (200,350);glVertex2f (260,360);
	glVertex2f (260,340);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (230,420);glVertex2f (200,410);glVertex2f (200,500);glVertex2f (240,500);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (230,600);glVertex2f (200,620);glVertex2f (200,600);glVertex2f (240,680);
	glEnd();
		glBegin(GL_POLYGON);
	glVertex2f (1200,350);glVertex2f (1200,400);glVertex2f (1185,400);glVertex2f (1185,350);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (1200,500);glVertex2f (1200,550);glVertex2f (1185,550);glVertex2f (1185,500);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (1200,700);glVertex2f (1200,800);glVertex2f (1180,800);glVertex2f (1180,700);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (1200,800);glVertex2f (1200,850);glVertex2f (1185,850);glVertex2f (1185,800);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (1140,310);glVertex2f (1200,300);glVertex2f (1200,350);glVertex2f (1140,360);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (1170,420);glVertex2f (1200,410);glVertex2f (1200,500);glVertex2f (1160,500);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f (1320,410);glVertex2f (1410,450);glVertex2f (1500,410);
	glEnd();circle(1410,445,5);
	
	glColor3f (0.35, 0.281, 0.273);
	glBegin(GL_POLYGON);
	glVertex2f (1310,410);glVertex2f (1310,290);glVertex2f (1510,290);glVertex2f (1510,410);
	glEnd();
	glColor3f (0.3, 0.231, 0.203);
	glBegin(GL_LINE_LOOP);
	glVertex2f (1310,410);glVertex2f (1310,290);glVertex2f (1510,290);glVertex2f (1510,410);
	glEnd();
	glColor3f (0.18, 0.76, 0.798);	
	glBegin(GL_POLYGON);
	glVertex2f (1320,400);glVertex2f (1320,300);glVertex2f (1500,300);glVertex2f (1500,400);
	glEnd();
		
		//信箱 
	glLineWidth(1);	//	glLineWidth(0.001f); 
	glColor3f (0.9, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f (150+5,350-108);glVertex2f (150+5,350-91);glVertex2f (150+6,350-80);
	glVertex2f (150+10,350-67);glVertex2f (150+14,350-60);glVertex2f (150+20,350-51);
	glVertex2f (150+27,350-46);glVertex2f (150+35,350-42);glVertex2f (150+49,350-42);
	glVertex2f (150+66,350-45);glVertex2f (150+117,350-55);glVertex2f (150+130,350-67);
	glVertex2f (150+142,350-83);glVertex2f (150+142,350-105);glVertex2f (150+142,350-120);
	glVertex2f (150+88,350-140);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (150+142,350-120);
	glVertex2f (150+158,350-158);glVertex2f (150+158,350-171);glVertex2f (150+154,350-178);
	glVertex2f (150+145,350-181);glVertex2f (150+135,350-186);glVertex2f (150+124,350-180);
	glVertex2f (150+114,350-170);glVertex2f (150+92,350-141);glVertex2f (150+88,350-140);
	glEnd();
		glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f (150+5,350-108);glVertex2f (150+5,350-91);glVertex2f (150+6,350-80);
	glVertex2f (150+10,350-67);glVertex2f (150+14,350-60);glVertex2f (150+20,350-51);
	glVertex2f (150+27,350-46);glVertex2f (150+35,350-42);glVertex2f (150+49,350-42);
	glVertex2f (150+66,350-45);glVertex2f (150+117,350-55);glVertex2f (150+130,350-67);
	glVertex2f (150+142,350-83);glVertex2f (150+142,350-105);glVertex2f (150+142,350-120);
	glVertex2f (150+158,350-158);glVertex2f (150+158,350-171);glVertex2f (150+154,350-178);
	glVertex2f (150+145,350-181);glVertex2f (150+135,350-186);glVertex2f (150+124,350-180);
	glVertex2f (150+114,350-170);glVertex2f (150+92,350-141);glVertex2f (150+88,350-140);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (150+88,350-140);glVertex2f (150+86,350-119);glVertex2f (150+86,350-92);
	glVertex2f (150+87,350-75);glVertex2f (150+90,350-75);glVertex2f (150+96,350-67);
	glVertex2f (150+100,350-59);glVertex2f (150+107,350-55);glVertex2f (150+117,350-55);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (150+5,350-108);
	glVertex2f (150+92,350-140);glVertex2f (150+140,350-120);glVertex2f (150+87,350-100);
	glEnd();
		glColor3f (1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
	glVertex2f (150+88,350-87);
	glVertex2f (150+141,350-108);glVertex2f (150+97,350-141);glVertex2f (150+88,350-134);
	glEnd();
	
	glColor3f (0.43, 0.331, 0.323);
	glBegin(GL_POLYGON);
	glVertex2f (150+50,350-124);
	glVertex2f (150+50,350-225);glVertex2f (150+50,350-288);glVertex2f (150+66,350-300);
	glVertex2f (150+75,350-285);glVertex2f (150+75,350-225);glVertex2f (150+75,350-135);
	glEnd();
	glColor3f (0.33, 0.231, 0.223);
	glBegin(GL_LINE_LOOP);
	glVertex2f (150+50,350-124);
	glVertex2f (150+50,350-225);glVertex2f (150+50,350-288);glVertex2f (150+66,350-300);
	glVertex2f (150+75,350-285);glVertex2f (150+75,350-225);glVertex2f (150+75,350-135);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f (150+63,350-300);
	glVertex2f (150+63,350-128);
	glEnd();
	
	//時鐘本人
	glColor3f(0.4705, 0.2901, 0.1961);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(60*cos(2*PI*i/2000)+1406, 60*sin(2*PI*i/2000)+900-195);
   		}
   	glEnd();
   	glColor3f(0.6078, 0.4823, 0.4509);
   	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(48*cos(2*PI*i/2000)+1406, 48*sin(2*PI*i/2000)+900-195);
   		}
   	glEnd();
   	glColor3f(0.3254, 0.2901, 0.2705);
   	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(42*cos(2*PI*i/2000)+1406, 42*sin(2*PI*i/2000)+900-195);
   		}
   	glEnd();
   	
//11:00
	glColor3f(0.9254, 0.9901, 0.9705);
   	glBegin(GL_LINE_STRIP);
   		glVertex2f(32*cos(0.5*PI)+1406,32*sin(0.5*PI)+900-195);
   		glVertex2f(1406,900-195);
   		glVertex2f(20*cos(0.6666*PI)+1406,20*sin(0.6666*PI)+900-195);
   	glEnd();


	
}	
void p3::d1(){
	glColor3f (0.294, 0.321, 0.345);
	int n1=28;
	float d[28][2]={{900,310},{910,290},{920,270},{930,260},{940,250},{950,240},{900,230},
	{800,220},{700,210},{630,210},{600,210},{540,230},{500,230},{470, 230},{440, 250},
	{415, 270},{410, 285},{400, 300},{402, 310},{405, 320},{409, 330},{414, 340},
	{420, 350},{427, 360},{435, 370},{450, 380},{475, 390},{500, 415}};
	glBegin(GL_POLYGON);
	
	for(int i=1; i<n1; i++){
		glVertex2f (d[i][0], d[i][1]);
	}glEnd();
	glColor3f (0.886, 0.862, 0.627);
	glBegin(GL_POLYGON);
	glVertex2f (540, 410);glVertex2f (550, 420);glVertex2f (560, 430);glVertex2f (570, 440);
	glVertex2f (580, 450);glVertex2f (600, 465);glVertex2f (610, 470);glVertex2f (630, 477);
	glVertex2f (650, 484);glVertex2f (670, 489);glVertex2f (690, 495);glVertex2f (700, 500);
	glVertex2f (760, 500);glVertex2f (780, 495);glVertex2f (800, 490);glVertex2f (810, 485);
	glVertex2f (830, 480);glVertex2f (850, 460);glVertex2f (870, 440);glVertex2f (890, 410);
	glVertex2f (910, 350);glVertex2f (910, 320);glVertex2f (900, 300);glVertex2f (880, 300);
	glVertex2f (850, 300);glVertex2f (800, 300);glVertex2f (780, 300);glVertex2f (750, 300);
	glVertex2f (550, 370);
	
	glEnd();
	glColor3f (0.431, 0.431, 0.431);
	glBegin(GL_POLYGON);
	glVertex2f (590, 310);glVertex2f (580, 315);glVertex2f (570, 320);glVertex2f (560, 320);
	glVertex2f (550, 325);glVertex2f (540, 330);glVertex2f (530, 340);glVertex2f (520, 350);
	glVertex2f (510, 360);glVertex2f (505, 370);glVertex2f (500, 380);glVertex2f (500, 380);
	glVertex2f (500, 400);glVertex2f (500, 420);glVertex2f (530, 420);glVertex2f (520, 410);
	glVertex2f (520, 405);glVertex2f (533, 405);glVertex2f (535, 400);glVertex2f (545, 390);
	glVertex2f (550, 380);glVertex2f (570, 370);glVertex2f (590, 360);glVertex2f (610, 350);
	glVertex2f (630, 340);
	glEnd();

	ctcircle(623,300,40,1.03);ctcircle(630,295,40,1.03);ctcircle(635,295,40,1.03);
	ctcircle(640,290,40,1.03);ctcircle(650,285,40,1.03);ctcircle(660,280,40,1.03);
	ctcircle(670,275,40,1.03);ctcircle(680,275,40,1.03);ctcircle(690,270,40,1.03);
	ctcircle(700,270,40,1.03);ctcircle(710,268,40,1.03);ctcircle(720,265,40,1.03);
	ctcircle(735,265,40,1.03);ctcircle(750,265,40,1.03);ctcircle(623,310,30,1.03);
	ctcircle(630,315,30,1.03);ctcircle(635,310,30,1.03);ctcircle(640,305,30,1.03);
	ctcircle(650,305,30,1.03);ctcircle(660,303,30,1.03);ctcircle(670,290,40,1.03);
	ctcircle(680,285,40,1.03);ctcircle(690,284,40,1.03);ctcircle(700,280,40,1.03);
	ctcircle(710,278,40,1.03);ctcircle(720,275,40,1.03);ctcircle(520,410,22,1.03);
	
	glBegin(GL_POLYGON);
	glVertex2f (790, 280);glVertex2f (790, 295);glVertex2f (780, 298);glVertex2f (800, 300);
	glVertex2f (810, 303);glVertex2f (820, 305);glVertex2f (840, 308);glVertex2f (860, 315);
	glVertex2f (890, 320);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (910, 330);glVertex2f (910, 310);glVertex2f (913, 300);glVertex2f (922, 270);
	glVertex2f (920, 270);glVertex2f (900, 268);glVertex2f (840, 268);glVertex2f (820, 270);
	glVertex2f (790, 280);
	glEnd();
	glColor3f (0.294, 0.321, 0.345);
	glBegin(GL_LINE_STRIP);
	glVertex2f (580,440);glVertex2f (570,430);glVertex2f (580,420);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (590,400);glVertex2f (585,390);glVertex2f (600,380);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (610,450);glVertex2f (600,440);glVertex2f (610,430);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (630,400);glVertex2f (620,390);glVertex2f (635,380);
	glEnd();
	glColor3f (0.0, 0.0, 0.0);
	circle(497,415,8);circle(496,412,8);circle(465,360,4);circle(465,359,4);
	circle(465,355,4);circle(465,353,4);circle(465,351,4);
		
	glBegin(GL_LINE_STRIP);
	glVertex2f (505, 370);glVertex2f (495, 360);glVertex2f (475, 330);glVertex2f (465, 305);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (520, 360);glVertex2f (506, 330);glVertex2f (495, 280);
	glEnd();	
	glBegin(GL_LINE_STRIP);
	glVertex2f (535, 340);glVertex2f (530, 280);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f (790,265);glVertex2f (800,260);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (790,250);glVertex2f (800,245);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (787,240);glVertex2f (792,237);
	glEnd();
}
void p3::grass(){	
	glLineWidth(3);
	glColor3f (0.211, 0.403, 0.149);
	circleline(400,250,40,1,1);circleline(420,220,50,1,1);circleline(460,200,70,1,1);circleline(500,195,50,1,1);
	circleline(520,200,50,1,1);circleline(540,210,50,1,1);circleline(580,190,50,1,1);circleline(630,200,50,1,1);
	circleline(690,180,70,1,1);circleline(730,200,50,1,1);circleline(780,180,50,1,1);circleline(820,190,50,1,1);
	circleline(860,170,60,1,1);circleline(920,200,50,1,1);circleline(950,190,60,1,1);circleline(1000,215,50,1,1);
	circleline(450,600,10,1,1);circleline(450,650,15,1,1);circleline(470,660,10,1,1);circleline(420,620,10,1,1);
	circleline(425,650,10,1,1);circleline(500,640,10,1,1);circleline(480,640,10,1,1);circleline(470,670,20,1,1);
	circleline(996,580,10,1,1);circleline(1010,550,15,1,1);circleline(1020,570,10,1,1);
	glColor3f (0.411, 0.603, 0.349);
	circle(400,250,40);circle(420,220,50);circle(460,200,70);circle(500,195,50);
	circle(520,200,50);circle(540,210,50);circle(580,190,50);circle(630,200,50);
	circle(690,180,70);circle(730,200,50);circle(780,180,50);circle(820,190,50);
	circle(860,170,60);circle(920,200,50);circle(950,190,60);circle(1000,215,50);
	circle(450,600,10);circle(450,650,15);circle(470,660,10);circle(420,620,10);
	circle(425,650,10);circle(500,640,10);circle(480,640,10);circle(470,670,20);
	circle(996,580,10);circle(1010,550,15);circle(1020,570,10);
	
	glColor3f (0.184, 0.462, 0.337);	
	circle(430,600,10);circle(450,620,20);circle(500,640,10);circle(450,680,20);
	circle(990,560,15);
	glColor3f (0.08, 0.148, 0.182);
	circle(427,635,10);	circle(1008,570,10);	
}
void p3::bubble1(){
		glColor3f (0.16, 0.66, 0.788);
		glBegin(GL_LINE_STRIP);
		glVertex2f (500,450);glVertex2f (500,460);
		glEnd();
		circle(500,460,8);
}
void p3::bubble2(){
	 glColor3f (0.16, 0.66, 0.788); 
	 glBegin(GL_LINE_STRIP); 
	 glVertex2f (505,450);glVertex2f (505,460);glVertex2f (520,460); 
	 glVertex2f (505,450); 
	 glEnd(); 
	 circle(510,470,15); 
	 glColor3f (0.886, 0.862, 0.627); 
	 ctcircle(729,455,60,1.8); 
	 glBegin(GL_POLYGON); 
	 glVertex2f (590,450);glVertex2f (639,490);glVertex2f (620,460); 
	 glEnd(); 
	 glColor3f (0.294, 0.321, 0.345); 
	 glBegin(GL_LINE_STRIP); 
	 glVertex2f (580,440);glVertex2f (570,430);glVertex2f (580,420); 
	 glEnd(); 
	 glBegin(GL_LINE_STRIP); 
	 glVertex2f (590,400);glVertex2f (585,390);glVertex2f (600,380); 
	 glEnd(); 
	 glBegin(GL_LINE_STRIP); 
	 glVertex2f (610,450);glVertex2f (600,440);glVertex2f (610,430); 
	 glEnd(); 
	 glBegin(GL_LINE_STRIP); 
	 glVertex2f (630,400);glVertex2f (620,390);glVertex2f (635,380); 
	 glEnd();
}
void p3::bubble3(){
	glColor3f (0.16, 0.66, 0.788);
	glBegin(GL_POLYGON);
	glVertex2f (495,460);glVertex2f (495,486);glVertex2f (530,480);
	glVertex2f (495,460);
	glEnd();
	circle(515,500,25);
	glColor3f (1,1,1);
	glBegin(GL_LINE_STRIP);
	glVertex2f (500,494);glVertex2f (498,496);glVertex2f (500,501);
	glVertex2f (503,503);glVertex2f (505,507);glVertex2f (507,512);
	glEnd();
	glColor3f (0.886, 0.862, 0.627);
	ctcircle(730,455,65,2);
	glBegin(GL_POLYGON);
	glVertex2f (862,463);glVertex2f (892,400);glVertex2f (820,450);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (585,455);glVertex2f (611,485);glVertex2f (620,460);
	glEnd();
	glColor3f (0.294, 0.321, 0.345);
	glBegin(GL_LINE_STRIP);
	glVertex2f (580,440);glVertex2f (570,430);glVertex2f (580,420);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (590,400);glVertex2f (585,390);glVertex2f (600,380);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (610,450);glVertex2f (600,440);glVertex2f (610,430);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (630,400);glVertex2f (620,390);glVertex2f (635,380);
	glEnd();
}
void p3::card(){
	glColor3f (1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f (400,100);glVertex2f (400,700);glVertex2f (1300,700);
	glVertex2f (1300,100);
	glEnd();
	glColor3f (1, 0.94, 0.89);
	ctcircle(850,400,160,1.7);
	ctcircle(400+41,700-138,15,1.7);ctcircle(400+125,700-36,15,1.7);
	ctcircle(400+189,700-85,15,1.7);ctcircle(400+124,700-186,15,1.7);
	ctcircle(400+41,700-281,15,1.7);ctcircle(400+122,700-334,15,1.7);
	ctcircle(400+41,700-431,15,1.7);ctcircle(400+125,700-482,15,1.7);
	ctcircle(400+41,700-575,15,1.7);ctcircle(400+188,700-375,15,1.7);
	ctcircle(400+191,700-527,15,1.7);ctcircle(400+262,700-574,15,1.7);
	ctcircle(400+262,700-131,15,1.7);ctcircle(400+345,700-42,15,1.7);
	ctcircle(400+347,700-479,15,1.7);ctcircle(400+481,700-575,15,1.7);
	ctcircle(400+560,700-42,15,1.7);ctcircle(400+562,700-483,15,1.7);
	ctcircle(400+632,700-89,15,1.7);ctcircle(400+631,700-528,15,1.7);
	ctcircle(400+702,700-138,15,1.7);ctcircle(400+702,700-431,15,1.7);
	ctcircle(400+702,700-572,15,1.7);ctcircle(400+785,700-41,15,1.7);
	ctcircle(400+785,700-188,15,1.7);ctcircle(400+785,700-338,15,1.7);
	ctcircle(400+785,700-481,15,1.7);ctcircle(400+847,700-87,15,1.7);
	ctcircle(400+847,700-231,15,1.7);ctcircle(400+848,700-381,15,1.7);
	ctcircle(400+846,700-526,15,1.7);
	glColor3f (1, 0.61, 0.191);
	glBegin(GL_LINE_STRIP);
	glVertex2f (400+195,700-120);glVertex2f (400+208,700-118);glVertex2f (400+244,700-111);
	glVertex2f (400+274,700-101);glVertex2f (400+316,700-88);glVertex2f (400+344,700-73);
	glVertex2f (400+373,700-58);glVertex2f (400+391,700-43);glVertex2f (400+404,700-33);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (400+244,700-111);glVertex2f (400+283,700-137);glVertex2f (400+274,700-101);
	glVertex2f (400+316,700-88);glVertex2f (400+355,700-102);glVertex2f (400+344,700-73);
	glVertex2f (400+373,700-58);glVertex2f (400+417,700-70);glVertex2f (400+391,700-43);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+208,700-118);glVertex2f (400+247,700-145);glVertex2f (400+244,700-111);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+274,700-101);glVertex2f (400+319,700-122);glVertex2f (400+316,700-88);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+344,700-73);glVertex2f (400+391,700-84);glVertex2f (400+373,700-58);
	glEnd();
	glColor3f (0.95, 0.635, 0.682);
	glBegin(GL_LINE_STRIP);
	glVertex2f (400+480,700-69);glVertex2f (400+514,700-88);glVertex2f (400+547,700-98);
	glVertex2f (400+577,700-105);glVertex2f (400+619,700-111);glVertex2f (400+672,700-108);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (400+514,700-88);glVertex2f (400+511,700-123);glVertex2f (400+547,700-98);
	glVertex2f (400+577,700-105);glVertex2f (400+596,700-139);glVertex2f (400+619,700-111);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+480,700-69);glVertex2f (400+484,700-110);glVertex2f (400+514,700-88);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+547,700-98);glVertex2f (400+548,700-129);glVertex2f (400+577,700-105);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+619,700-111);glVertex2f (400+641,700-140);glVertex2f (400+672,700-108);
	glEnd();
	
	glColor3f (1, 0.81, 0.191);
	circle(400+595,700-173,10);
	glBegin(GL_LINES);
	glVertex2f (400+173,700-177);glVertex2f (400+239,700-205);
	glVertex2f (400+181,700-216);glVertex2f (400+226,700-230);
	glVertex2f (400+154,700-254);glVertex2f (400+253,700-260);
	glVertex2f (400+154,700-292);glVertex2f (400+241,700-282);
	glVertex2f (400+161,700-323);glVertex2f (400+243,700-302);
	glVertex2f (400+196,700-353);glVertex2f (400+235,700-337);
	glVertex2f (400+198,700-401);glVertex2f (400+251,700-369);
	glVertex2f (400+255,700-441);glVertex2f (400+281,700-393);
	glVertex2f (400+633,700-440);glVertex2f (400+607,700-393);
	glVertex2f (400+693,700-400);glVertex2f (400+635,700-367);
	glVertex2f (400+688,700-353);glVertex2f (400+654,700-338);
	glVertex2f (400+729,700-322);glVertex2f (400+648,700-300);
	glVertex2f (400+739,700-291);glVertex2f (400+650,700-284);
	glVertex2f (400+730,700-253);glVertex2f (400+638,700-259);
	glVertex2f (400+713,700-216);glVertex2f (400+665,700-228);
	glVertex2f (400+720,700-176);glVertex2f (400+654,700-204);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f (400+277,700-311);glVertex2f (400+387,700-288);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f (400+300,700-200);glVertex2f (400+277,700-195);
	glVertex2f (400+300,700-200);glVertex2f (400+281,700-185);
	glVertex2f (400+300,700-200);glVertex2f (400+295,700-185);
	glVertex2f (400+300,700-200);glVertex2f (400+309,700-182);
	glEnd();
	glColor3f (1, 0.635, 0.72);
	glBegin(GL_POLYGON);
	glVertex2f (400+300,700-200);glVertex2f (400+281,700-303);
	glVertex2f (400+377,700-282);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f (400+427,700-97);glVertex2f (400+416,700-114);
	glVertex2f (400+427,700-97);glVertex2f (400+396,700-105);
	glVertex2f (400+427,700-97);glVertex2f (400+405,700-89);
	glVertex2f (400+427,700-97);glVertex2f (400+417,700-82);
	glVertex2f (400+427,700-97);glVertex2f (400+432,700-72);
	glVertex2f (400+427,700-97);glVertex2f (400+452,700-78);
	glVertex2f (400+427,700-97);glVertex2f (400+462,700-95);
	glVertex2f (400+427,700-97);glVertex2f (400+460,700-112);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f (400+495,700-296);glVertex2f (400+627,700-321);
	glEnd();
	

	glColor3f (0.35, 0.596, 0.73);
	glBegin(GL_POLYGON);
	glVertex2f (400+430,700-100);glVertex2f (400+395,700-250);
	glVertex2f (400+519,700-230);
	glEnd();
	glColor3f (1, 0.61, 0.191);
	glBegin(GL_LINES);
	glVertex2f (400+388,700-260);glVertex2f (400+527,700-237);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (400+591,700-183);glVertex2f (400+502,700-290);
	glVertex2f (400+619,700-310);
	glEnd();
	glFlush ( );
	glColor3f (1, 0.41, 0.591);//字 
}
void p3::raining(int offSetX){
	for(int i=0;i<=1600;i+=80)
			for(int j=0;j<=900;j+=100){
				glColor3f (1,1,1);
				glBegin(GL_LINES );
				glVertex2f(i,j);glVertex2f(i-30,j-30);
				glEnd ( );
				glFlush ( );
			}
}
void p3::draw (int offSetX) { 
	glClear (GL_COLOR_BUFFER_BIT); 
	glPushMatrix ();
	glTranslatef(offSetX,0,0);
	glColor3f (0.10, 0.04, 0.31);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0); 
	glVertex2i (0, 900);
 	glVertex2i (8000,900); 
	glVertex2i (8000, 0); 
	glEnd ( );

	forest();
	glTranslatef(1600,0,0);	
	country();
	glTranslatef(1600,0,0);	
	country();
	tree();
	glTranslatef(1600,0,0);	
	pond();
	//house();
	glTranslatef(1600,0,0);	
	glLineWidth(0.001f); 
	end();
	glPopMatrix(); 
	glPushMatrix ();
	glFlush (); 
} 
void p3::drawHouse(){
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (0.10, 0.04, 0.31);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0); 
	glVertex2i (0, 900);
 	glVertex2i (9600,900); 
	glVertex2i (9600, 0); 
	glEnd ( );
	house();
}
void p3::drawSleep(){
	glPushMatrix ();
	glColor3f (0.10, 0.04, 0.31);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0); 
	glVertex2i (0, 900);
 	glVertex2i (9600,900); 
	glVertex2i (9600, 0); 
	glEnd ( );
	hole();
	d1();
	grass();
	if(isWake&&sleepTime>=5000){
		sleepTime=4500;
		eyeTime++;
		if(eyeTime<4)
			PlaySound("eye.wav", NULL, SND_ASYNC|SND_FILENAME);
	}
	else if(isWake&&sleepTime>=4800){;}
	else if(isWake&&sleepTime>=4500){
		glColor3f(1,1,1);
		circle(465,900-545,12);
		glColor3f(0,0,0);
		circle(465,900-540,7);
		glFlush (); 
	}
	else if(sleepTime>2000/1.8)
		sleepTime=0;
	else if(sleepTime>1500/2)
		bubble3();
	else if(sleepTime>1000/2)
		bubble2();
	else if(sleepTime>500/2)
		bubble1();
	glFlush (); 
}
void p3::drawHole(){
	glColor3f (0.10, 0.04, 0.31);
	glBegin (GL_POLYGON); 
	glVertex2i (0, 0); 
	glVertex2i (0, 900);
 	glVertex2i (9600,900); 
	glVertex2i (9600, 0); 
	glEnd ( );
	hole();
	grass();
}
void p3::drawThank(){
	
	glPushMatrix ();
	glTranslatef(0,thankNum,0);
	glColor3f(1,1,1);
	for(int i=0;i<thankSize;i++){
		selectFont(25, DEFAULT_CHARSET, "YouYuan");
		glRasterPos2f(300, -100-i*80);
		drawCNString(thankString[i]);
	}
	glPopMatrix(); 
	glPushMatrix ();
	glFlush (); 
	
}

