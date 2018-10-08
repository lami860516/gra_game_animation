#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include <windows.h>
#define PI 3.14159265358
#include "all.hpp"
//龍貓身體 glColor3f(0.451, 0.451, 0.376);
//龍貓肚子 glColor3f(0.886, 0.862, 0.627);
//背景深色 glColor3f(0.0784, 0.2, 0.2);
//背景淺色 glColor3f(0.1215, 0.3686, 0.2627);
//背景淺淺 glColor3f(0.4117, 0.6039, 0.3491);
//鏡子反射 glColor3f(0.8901, 0.9294, 0.9333);
//反射淺淺 glColor3f(0.9176, 0.9647, 0.9647);
//混色 0.7451 0.8392 0.8392
//結果1 0.4333 0.6039 0.5509 
//結果2 0.5195, 0.7215, 0.6569

void LookMirror::background()
{
	glBegin(GL_POLYGON);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(0, 0);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(0, sizeY);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(0, sizeY);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(sizeX, sizeY);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(sizeX, sizeY);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(sizeX, 0);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(sizeX, 0);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
		glColor3f(0.0784, 0.2, 0.2);
		glVertex2f(0, 0);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(sizeX/2, sizeY/2);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.1215, 0.3686, 0.2627);
		glVertex2f(250, 25);
		glColor3f(0.4117, 0.6039, 0.3491);
		glVertex2f(250, 875);
		glVertex2f(1350, 875);
		glColor3f(0.1215, 0.3686, 0.2627);
		glVertex2f(1350, 25);
	glEnd();
}
void LookMirror::mirror()
{
	int mirror_size=50;
	glColor3f(0.5412, 0.3333, 0.2588);
	glBegin(GL_POLYGON);
		glVertex2f(200, 0);
		glVertex2f(200, 900);
		glVertex2f(250, 900);
		glVertex2f(250, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(250, 900);
		glVertex2f(250, 875);
		glVertex2f(1350, 875);
		glVertex2f(1350, 900);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1350, 0);
		glVertex2f(1350, 900);
		glVertex2f(1400, 900);
		glVertex2f(1400, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(200, 25);
		glVertex2f(200, 0);
		glVertex2f(1350, 0);
		glVertex2f(1350, 25);
	glEnd();
	glColor3f(0.4333, 0.6039, 0.5509);
	glBegin(GL_POLYGON);
		glVertex2f(1160, 875);
		glVertex2f(1350, 760);
		glVertex2f(1350, 730);
		glVertex2f(1100, 875);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1040, 870);
		glVertex2f(1350, 680);
		glVertex2f(1350, 670);
		glVertex2f(1020, 870);
	glEnd();
	glColor3f(0.2333, 0.4039, 0.3509);
	glBegin(GL_POLYGON);
		glVertex2f(590, 25);
		glVertex2f(250, 160);
		glVertex2f(250, 180);
		glVertex2f(670, 25);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(470, 25);
		glVertex2f(250, 90);
		glVertex2f(250, 100);
		glVertex2f(500, 25);
	glEnd();
}
void LookMirror::see()
{
	//身體底色 
	glColor3f (0.431, 0.431, 0.431);
	glBegin(GL_POLYGON);
		glVertex2f(700,900-478);
  		for(int i=0; i<32; i++)
  		{
  			glVertex2f(watch[i][0],watch[i][1]);
		}
		glVertex2f(800,0);
		glVertex2f(watch[0][0],watch[0][1]);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(935+45,900-358);
  		for(int i=30; i<64; i++)
  		{
  			glVertex2f(watch[i][0],watch[i][1]);
		}
		glVertex2f(watch[0][0],watch[0][1]);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(980,900-358);
		glVertex2f(885,900-286);
		glVertex2f(860,900-500);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<64; i++)
  		{
  			glVertex2f(watch[i][0],watch[i][1]);
		}
	glEnd();
	//肚子
	glColor3f(0.886, 0.862, 0.627);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(490*cos(i*PI/2000)+810,550*sin(i*PI/2000)-288);  
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(490*cos(i*PI/2000)+810,550*sin(i*PI/2000)-288);  
   		}  
	glEnd();
	//肚子紋路
	glColor3f (0.431, 0.431, 0.431);
	glBegin(GL_POLYGON);
		for(int i=64; i<74; i++)  
		{  
   			glVertex2f(watch[i][0],watch[i][1]); 
   		}  
	glEnd();
	for(int j=0; j<6; j++)
	{
		glBegin(GL_POLYGON);
			if(j==0) 	  glVertex2f( 584,900-759);
			else if(j==1) glVertex2f( 698,900-845);
			else if(j==2) glVertex2f( 800,900-727);
			else if(j==3) glVertex2f( 891,900-831);
			else if(j==4) glVertex2f(1026,900-741);
			else if(j==5) glVertex2f(1109,900-867);
			for(int i=74; i<87; i++)
			{  
	   			glVertex2f(watch[i+13*j][0],watch[i+13*j][1]);
	   		}  
		glEnd();
	}
	//斑紋黑框 
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=64; i<74; i++)  
		{  
   			glVertex2f(watch[i][0],watch[i][1]); 
   		}  
	glEnd();
	for(int j=0; j<5; j++)
	{
		glBegin(GL_LINE_LOOP);
			for(int i=74; i<87; i++)  
			{  
	   			glVertex2f(watch[i+13*j][0],watch[i+13*j][1]); 
	   		}  
		glEnd();
	}
	glBegin(GL_LINE_STRIP);
		for(int i=139; i<152; i++)  
		{  
   			glVertex2f(watch[i][0],watch[i][1]); 
   		}  
	glEnd();
	
	//手
	for(int j=0; j<2; j++)
	{
		glBegin(GL_LINE_STRIP);
			for(int i=152; i<157; i++)  
			{  
	   			glVertex2f(watch[i+5*j][0],watch[i+5*j][1]); 
	   		}  
		glEnd();
	}
	
	//眼白
	glColor3f(1, 1, 0.9935);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(48*cos(2*i*PI/2000)+653,42*sin(2*i*PI/2000)+900-427);  
   		}  
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(48*cos(2*i*PI/2000)+995,42*sin(2*i*PI/2000)+900-427);  
   		}  
	glEnd();
	
	//瞳孔
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(20*cos(2*i*PI/2000)+660,20*sin(2*i*PI/2000)+900-426);  
   		}  
	glEnd(); 
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(20*cos(2*i*PI/2000)+985,20*sin(2*i*PI/2000)+900-426);  
   		}  
	glEnd();
	
	//鼻子
	glBegin(GL_LINE_STRIP);
		for(int i=162; i<165; i++)  
		{  
	   		glVertex2f(watch[i][0],watch[i][1]); 
	   	}  
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=165; i<169; i++)  
		{  
	   		glVertex2f(watch[i][0],watch[i][1]); 
	   	}  
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=169; i<174; i++)  
		{  
	   		glVertex2f(watch[i][0],watch[i][1]); 
	   	}  
	glEnd();
	
	//鬍鬚
	glColor3f (0.431, 0.431, 0.431);
	for(int j=0; j<6; j++)
	{
		glBegin(GL_POLYGON);
			for(int i=174; i<179; i++)  
			{  
		   		glVertex2f(watch[i+5*j][0],watch[i+5*j][1]); 
		   	}  
		glEnd();
	}
	glColor3f (0, 0, 0);
	for(int j=0; j<6; j++)
	{
		glBegin(GL_LINE_LOOP);
			for(int i=174; i<179; i++)  
			{  
		   		glVertex2f(watch[i+5*j][0],watch[i+5*j][1]); 
		   	}  
		glEnd();
	}
}
void LookMirror::mouse1()
{
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
  		for(int i=0; i<6; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
}
void LookMirror::mouse2()
{
	glColor3f(1, 1, 0.9823);
	glBegin(GL_POLYGON);
		glVertex2f(835,900-529);
  		for(int i=7; i<26; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
  		for(int i=7; i<26; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=26; i<29; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=29; i<32; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=32; i<34; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=34; i<36; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
}

void LookMirror::mouse3()
{
	glColor3f(1, 1, 0.9823);
	glBegin(GL_POLYGON);
		glVertex2f(835,900-561);
  		for(int i=36; i<56; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
		glVertex2f(mouse[36][0],mouse[36][1]);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
  		for(int i=36; i<56; i++)
  		{
  			glVertex2f(mouse[i][0],mouse[i][1]);
		}
	glEnd();
	for(int j=0; j<6; j++)
	{
		glBegin(GL_LINE_STRIP);
			for(int i=56; i<59; i++)
	  		{
	  			glVertex2f(mouse[i+3*j][0],mouse[i+3*j][1]);
			}
		glEnd();
	}
}

void LookMirror::draw ()
{
	glLineWidth(1); 
	glEnable(GL_LINE_SMOOTH);
	background();
	see();
	if(smileNum==1)
		mouse1();
	else if(smileNum==2)
		mouse2();
	else 
		mouse3();
	mirror();
	glFlush ();
}

