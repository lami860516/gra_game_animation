#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include <windows.h>
#define PI 3.14159265358
#include "all.hpp"

void menuQAQ::qqq ()
{
	glColor3f(0.996, 0.9607, 0.8941);
	glBegin(GL_POLYGON);
		glVertex2f(0, sizeY);
		glVertex2f(sizeX, sizeY);
		glVertex2f(sizeX, 0);
		glVertex2f(0, 0);
	glEnd();
	
	glLineWidth(2); 
	glEnable(GL_LINE_SMOOTH);
  	glColor3f(0.0196, 0.6196, 0.7921);
  	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<110; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=110; i<120; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=120; i<132; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=132; i<142; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=142; i<160; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=160; i<163; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=163; i<166; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=166; i<168; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=168; i<170; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=170; i<172; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=172; i<175; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=175; i<181; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=181; i<184; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=184; i<187; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=187; i<190; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
  	
  	glBegin(GL_LINE_STRIP);
  		for(int i=190; i<220; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_POLYGON);
  		for(int i=220; i<231; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=231; i<262; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=262; i<278; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
  	
  	glBegin(GL_LINE_STRIP);
  		for(int i=278; i<295; i++)
  		{
  			glVertex2f(draginCat[i][0],draginCat[i][1]);
		}
	glEnd();
}
void menuQAQ::button ()
{
	glColor3f(0.9960, 0.9098, 0.8275);
//start button
	glBegin(GL_POLYGON);
  		for(int i=0; i<8; i++)
  		{
  			glVertex2f(Button[i][0],Button[i][1]);
		}
	glEnd();
//exit button(¸òstart®t188)
	glBegin(GL_POLYGON);
  		for(int i=0; i<8; i++)
  		{
  			glVertex2f(Button[i][0],Button[i][1]-188);
		}
	glEnd();
	
	
	glColor3f(0.75, 0.4, 0.02);
	glLineWidth(3); 
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<6; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=6; i<10; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=10; i<16; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=16; i<23; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=6; i<10; i++)
  		{
  			glVertex2f(font[i][0]+225,font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=23; i<30; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=30; i<35; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
  		for(int i=35; i<41; i++)
  		{
  			glVertex2f(font[i][0],font[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=6; i<10; i++)
  		{
  			glVertex2f(font[i][0]+187.5,font[i][1]-187);
		}
	glEnd();
}

void menuQAQ::draw ()
{
	qqq();
	button();
	glFlush ( );
}
