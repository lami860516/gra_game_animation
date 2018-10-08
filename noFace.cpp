/*
{}, {}, {}, {}, {}, {}, {}, {}, {}, {},
*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<windows.h>
#define PI 3.14159265358
#include<iostream>
#include "all.hpp"
using namespace std;

void noFace::background (){
	glBegin(GL_POLYGON);
		glColor3f(0.9368, 0.9231, 0.8062);
		glVertex2f(0, sizeY);
		glColor3f(0.9960, 0.9507, 0.9741);
		glVertex2f(sizeX, sizeY);
		glColor3f(0.9372, 0.8941, 0.6981);
		glVertex2f(sizeX, 0);
		glColor3f(0.8549, 0.6078, 0.4862);
		glVertex2f(0, 0);
	glEnd();
	
	glColor3f(0.5412, 0.3333, 0.2588);
  	glBegin(GL_POLYGON);
  		for(int i=0; i<6; i++)
  		{
  			glVertex2f(table[i][0],table[i][1]);
		}
	glEnd();
	
	glColor3f(0.2706, 0.2, 0.1725);
  	glBegin(GL_POLYGON);
  		for(int i=6; i<9; i++)
  		{
  			glVertex2f(table[i][0],table[i][1]);
		}
	glEnd();
	
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<6; i++)
  		{
  			glVertex2f(table[i][0],table[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=6; i<9; i++)
  		{
  			glVertex2f(table[i][0],table[i][1]);
		}
	glEnd();
}
void noFace::popoHair(){
	//左耳 
	glColor3f(0.9529, 0.7059, 0.5765);
	glBegin(GL_POLYGON);
		for(int i=0; i<4; i++)
		{
	  		glVertex2f(popo_ear[i][0],popo_ear[i][1]);
		}
	glEnd();
	
	//頭髮底色 
	glColor3f(0.8784, 0.7372, 0.6117);
	glBegin(GL_POLYGON);
		glVertex2f(1219,900);
		for(int i=0; i<54; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(983,700);
		for(int i=53; i<63; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1213,830);
		for(int i=62; i<81; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
		glVertex2f(1219,900);
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=81; i<99; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	
	//頭髮陰影 
	glColor3f(0.6941, 0.5451, 0.4706);
	glBegin(GL_POLYGON);
		for(int i=17; i<21; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
		for(int i=86; i<99; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=16; i<23; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=22; i<67; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
		for(int i=99; i<153; i++)
		{
	  		glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	
	//右耳 
	glColor3f(0.9529, 0.7059, 0.5765);
	glBegin(GL_POLYGON);
		for(int i=4; i<15; i++)
		{
	  		glVertex2f(popo_ear[i][0],popo_ear[i][1]);
		}
	glEnd();
	
	//右耳環
	glColor3f(1, 0.7882, 0.3961);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(33*cos(2*i*PI/2000)+1447,33*sin(2*i*PI/2000)+538);  
   		}  
	glEnd();
	
	//右耳環框
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(33*cos(2*i*PI/2000)+1447,33*sin(2*i*PI/2000)+538);  
   		}  
	glEnd();
	
	//頭髮紋路
	glColor3f(0.5696, 0.4362, 0.2872);
	for(int j=0; j<11; j++)
	{
		glBegin(GL_LINE_STRIP);
			for(int i=155; i<160; i++)
			{
		  		glVertex2f(popo_hair[i+5*j][0],popo_hair[i+5*j][1]);
			}
		glEnd();
		
	}
}
void noFace::popoCloth(){
	glColor3f(0.2471, 0.3137, 0.3843);
	glBegin(GL_POLYGON);
		for(int i=0; i<23; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	
	glColor3f(0.1686, 0.2078, 0.2117);
	glBegin(GL_POLYGON);
		for(int i=23; i<32; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	
	glColor3f(0.7372, 0.5333, 0.4392);
	glBegin(GL_POLYGON);
		for(int i=0; i<5; i++)
		{
	  		glVertex2f(popo_cloth_diamond[i][0],popo_cloth_diamond[i][1]);
		}
	glEnd();

	glColor3f(0.5608, 0.1803, 0.2157);
	glBegin(GL_POLYGON);
		for(int i=5; i<10; i++)
		{
	  		glVertex2f(popo_cloth_diamond[i][0],popo_cloth_diamond[i][1]);
		}
	glEnd();
	
	//蕾絲框 
	glColor3f(0.1451, 0.2078, 0.2706);
	glBegin(GL_LINE_STRIP);
		for(int i=32; i<44; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=44; i<71; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	
	//衣服框 
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<21; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=23; i<32; i++)
		{
	  		glVertex2f(popo_cloth[i][0],popo_cloth[i][1]);
		}
	glEnd();
	
	glColor3f(0, 0, 0);
	//衣服上鑽石框 
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<5; i++)
		{
	  		glVertex2f(popo_cloth_diamond[i][0],popo_cloth_diamond[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=5; i<10; i++)
		{
	  		glVertex2f(popo_cloth_diamond[i][0],popo_cloth_diamond[i][1]);
		}
	glEnd();
}
void noFace::popoFace(){
	//右臉 
	glColor3f(0.9529, 0.7059, 0.5765);
	glBegin(GL_POLYGON);
		for(int i=0; i<33; i++)
		{
	  		glVertex2f(popo_face[i][0],popo_face[i][1]);
		}
		glVertex2f(popo_face[65][0],popo_face[65][1]);
		glVertex2f(popo_face[64][0],popo_face[64][1]);
	glEnd();
	
	//左耳環
	glColor3f(1, 0.7882, 0.3961);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(33*cos(2*i*PI/2000)+1041,33*sin(2*i*PI/2000)+547);  
   		}  
	glEnd();
	
	//左耳環框
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(33*cos(2*i*PI/2000)+1041,33*sin(2*i*PI/2000)+547);  
   		}  
	glEnd();
	
	//左臉
	glColor3f(0.9529, 0.7059, 0.5765);
	glBegin(GL_POLYGON);
		for(int i=32; i<66; i++)
		{
	  		glVertex2f(popo_face[i][0],popo_face[i][1]);
		}
	glEnd();
}
void noFace::popoFrame(){
	glColor3f(0, 0, 0);
	//頭髮框 
	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<81; i++)
  		{
  			glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=81; i<99; i++)
  		{
  			glVertex2f(popo_hair[i][0],popo_hair[i][1]);
		}
	glEnd();
	
	//耳框 
	glBegin(GL_LINE_STRIP);
		for(int i=1; i<3; i++)
		{
	  		glVertex2f(popo_ear[i][0],popo_ear[i][1]);
		}
	glEnd();
	
	//臉框 
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<29; i++)
		{
	  		glVertex2f(popo_face[i][0],popo_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=29; i<66; i++)
		{
	  		glVertex2f(popo_face[i][0],popo_face[i][1]);
		}
	glEnd();
	
	//皺紋
	glColor3f(0.6353, 0.4863, 0.4039);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<6; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=6; i<16; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=16; i<18; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=18; i<21; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=21; i<26; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=26; i<36; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=36; i<51; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=51; i<54; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=54; i<60; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=60; i<76; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=76; i<96; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=96; i<106; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=106; i<109; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=109; i<112; i++)
		{
	  		glVertex2f(popo_wrinkle[i][0],popo_wrinkle[i][1]);
		}
	glEnd();
	for(int j=0; j<18; j+=2)
	{
		glBegin(GL_LINE_STRIP);
			for(int i=112; i<114; i++)
			{	
		  		glVertex2f(popo_wrinkle[i+j][0],popo_wrinkle[i+j][1]);
			}
		glEnd();
	}
}
void noFace::popoUpperFace(){
	//紅色圈圈 
	glColor3f(0.8392, 0.5098, 0.4157);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(25*cos(2*i*PI/2000)+1210,25*sin(2*i*PI/2000)+633);  
   		}  
	glEnd();
	glColor3f(0.5412, 0.3686, 0.2314);
	glBegin(GL_LINE_LOOP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(25*cos(2*i*PI/2000)+1210,25*sin(2*i*PI/2000)+633);  
   		}  
	glEnd();
	
	//眉毛顏色
	glColor3f(0.8784, 0.7372, 0.6117);
	glBegin(GL_POLYGON);
		glVertex2f(1143,900-217);
  		for(int i=49; i<68; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1293,900-220);
  		for(int i=68; i<88; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	
	//眼影顏色
	glColor3f(0.7529, 0.7098, 0.7765);
	glBegin(GL_POLYGON);
		glVertex2f(1121,900-261);
  		for(int i=104; i<123; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1327,900-265);
  		for(int i=123; i<143; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	
	//眼白
	glColor3f(0.9058, 0.8471, 0.8274);
	glBegin(GL_POLYGON);
		glVertex2f(1125,900-295);
  		for(int i=143; i<158; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1330,900-302);
  		for(int i=158; i<173; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	
	//眼球底色
	glColor3f(0.4431, 0.3137, 0.2392);
	glBegin(GL_POLYGON);
  		for(int i=173; i<192; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_POLYGON);
  		for(int i=192; i<209; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	
	//瞳孔
	glColor3f(0, 0, 0); 
	glBegin(GL_POLYGON);
  		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(7*cos(2*i*PI/2000)+1126,7*sin(2*i*PI/2000)+605);  
   		}  
	glEnd();
	glBegin(GL_POLYGON);
  		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(7*cos(2*i*PI/2000)+1316,7*sin(2*i*PI/2000)+598);  
   		}  
	glEnd();
	
	//瞳孔白白 
	glColor3f(0.9058, 0.8471, 0.8274); 
	glBegin(GL_POLYGON);
  		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(5*cos(2*i*PI/2000)+1135,5*sin(2*i*PI/2000)+605);  
   		}  
	glEnd();
	glBegin(GL_POLYGON);
  		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(5*cos(2*i*PI/2000)+1324,5*sin(2*i*PI/2000)+600);  
   		}  
	glEnd(); 
	
	//五官 
	glColor3f(0, 0, 0); 
	glBegin(GL_LINE_STRIP);
  		for(int i=0; i<37; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=37; i<42; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=42; i<49; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=49; i<68; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=68; i<88; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=88; i<96; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=96; i<104; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=104; i<123; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=123; i<143; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=143; i<158; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
  		for(int i=158; i<173; i++)
  		{
  			glVertex2f(popo_upper_face[i][0],popo_upper_face[i][1]);
		}
	glEnd();
}
void noFace::popo(){
	glEnable(GL_LINE_SMOOTH);
	popoCloth();
	popoHair();
	popoFace();
	popoFrame();
	popoUpperFace();
}
void noFace::noFace_1(){
	//身體 
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		for(int i=0; i<20; i++)  
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
	glEnd();
	//面具底色 
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=20; i<42; i++)  
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
	glEnd();
	//面具陰影 
	glColor3f(0.8521, 0.7266, 0.6264);
	glBegin(GL_POLYGON);
		glVertex2f(308,900-380);
		for(int i=42; i<55; i++)
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(298,900-278);
		for(int i=55; i<63; i++)
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
   	glEnd();
   	glBegin(GL_POLYGON);
		glVertex2f(308,900-380);
		for(int i=55; i<64; i++)
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
   	glEnd();
   	//嘴巴
   	glColor3f(0.8521, 0.1266, 0.1264);
   	glBegin(GL_POLYGON);
		for(int i=64; i<71; i++)
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
   	glEnd();
   	glColor3f(0.6521, 0.1266, 0.1264);
   	glBegin(GL_POLYGON);
		for(int i=66; i<70; i++)
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
   	glEnd();
   	
   	//紫色三角形 
   	glColor3f(0.6313, 0.5137, 0.5137);
   	for(int j=0; j<4; j++)
   	{
		glBegin(GL_POLYGON);
			for(int i=125; i<135; i++)
			{  
	   			glVertex2f(noFace_Man_1[i+10*j][0],noFace_Man_1[i+10*j][1]); 
	   		}
	   	glEnd();
	}
	
	//手
	glColor3f(0.2, 0.1725, 0.2);
	for(int j=0; j<2; j++)
   	{
		glBegin(GL_POLYGON);
			if(j==0) glVertex2f(412,900-668);
			else glVertex2f(145,900-668);
			for(int i=165; i<190; i++)
			{ 
		   		glVertex2f(noFace_Man_1[i+25*j][0],noFace_Man_1[i+25*j][1]); 
		   	}
		glEnd();		
	}	
   	
   	//五官
   	glColor3f(0, 0, 0);
   	for(int j=0; j<30; j+=10)
   	{
		glBegin(GL_POLYGON);
			for(int i=71; i<81; i++)
			{  
	   			glVertex2f(noFace_Man_1[i+j][0],noFace_Man_1[i+j][1]); 
	   		}
	   	glEnd();
	}
	//眼袋&下巴 
	for(int j=0; j<3; j++)
   	{
		glBegin(GL_POLYGON);
			for(int i=101; i<109; i++)
			{  
	   			glVertex2f(noFace_Man_1[i+8*j][0],noFace_Man_1[i+8*j][1]); 
	   		}
	   	glEnd();
	}
   	
	//面具框
	glBegin(GL_LINE_LOOP);
		for(int i=20; i<42; i++)  
		{  
   			glVertex2f(noFace_Man_1[i][0],noFace_Man_1[i][1]); 
   		}
	glEnd();
	//杯盤 
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=0; i<20; i++)  
		{  
   			glVertex2f(cup[i][0],cup[i][1]);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		for(int i=0; i<20; i++)  
		{  
   			glVertex2f(cup[i][0],cup[i][1]);
   		}  
	glEnd();
	glColor3f(0.2, 0.1725, 0.2);
	glBegin(GL_POLYGON);
		for(int i=11; i<15; i++)  
		{  
   			glVertex2f(cup[i][0],cup[i][1]);
   		}  
	glEnd();
	//杯子陰影 
	glColor3f(0.8521, 0.7266, 0.6264);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(35*cos(2*i*PI/2000)+360,11*sin(2*i*PI/2000)+230);
   		}  
	glEnd();
	//杯子
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=20; i<40; i++)  
		{  
   			glVertex2f(cup[i][0],cup[i][1]);
   		}  
	glEnd();
	for(int j=0; j<2; j++)
	{
		glBegin(GL_POLYGON);
			if(j==0) glVertex2f(293,900-604);
			else glVertex2f(310,900-648);
			for(int i=40; i<49; i++)  
			{  
	   			glVertex2f(cup[i+9*j][0],cup[i+9*j][1]);
	   		}  
		glEnd();
	}
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		for(int i=20; i<40; i++)  
		{  
   			glVertex2f(cup[i][0],cup[i][1]);
   		}  
	glEnd();
	for(int j=0; j<2; j++)
	{
		glBegin(GL_LINE_LOOP);
			for(int i=40; i<49; i++)  
			{  
	   			glVertex2f(cup[i+9*j][0],cup[i+9*j][1]);
	   		}  
		glEnd();
	}
	glColor3f(0.3706, 0.3, 0.2725);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(40*cos(0.8*i*PI/2000+1.1*PI)+361,9*sin(0.8*i*PI/2000+1.1*PI)+298);
   		}  
	glEnd();
}
void noFace::noFace_2(){
	float x, y;
	//身體 
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		for(int i=0; i<15; i++)  
		{  
   			glVertex2f(noFace_Man_2[i][0],noFace_Man_2[i][1]); 
   		}
	glEnd();
	//面具底色 
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=20; i<42; i++)  
		{
			x=(noFace_Man_1[i][0]-382)*cos(45/180*PI)-(noFace_Man_1[i][1]-350)*sin(45/180*PI)+382-40;
			y=(noFace_Man_1[i][1]-382)*cos(45/180*PI)+(noFace_Man_1[i][1]-350)*sin(45/180*PI)+350+88;
   			glVertex2f(x, y); 
   		}
	glEnd();
	//面具陰影 
	glColor3f(0.8521, 0.7266, 0.6264);
	glBegin(GL_POLYGON);
		glVertex2f(308-40,900-380+50);
		for(int i=42; i<55; i++)
		{  
   			x=(noFace_Man_1[i][0]-382)*cos(45/180*PI)-(noFace_Man_1[i][1]-350)*sin(45/180*PI)+382-40;
			y=(noFace_Man_1[i][1]-382)*cos(45/180*PI)+(noFace_Man_1[i][1]-350)*sin(45/180*PI)+350+88;
   			glVertex2f(x, y); 
   		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(298-40,900-278+50);
		for(int i=55; i<63; i++)
		{  
   			x=(noFace_Man_1[i][0]-382)*cos(45/180*PI)-(noFace_Man_1[i][1]-350)*sin(45/180*PI)+382-40;
			y=(noFace_Man_1[i][1]-382)*cos(45/180*PI)+(noFace_Man_1[i][1]-350)*sin(45/180*PI)+350+88;
   			glVertex2f(x, y); 
   		}
   	glEnd();
   	glBegin(GL_POLYGON);
		glVertex2f(308-40,900-380+50);
		for(int i=55; i<64; i++)
		{  
   			x=(noFace_Man_1[i][0]-382)*cos(45/180*PI)-(noFace_Man_1[i][1]-350)*sin(45/180*PI)+382-40;
			y=(noFace_Man_1[i][1]-382)*cos(45/180*PI)+(noFace_Man_1[i][1]-350)*sin(45/180*PI)+350+88;
   			glVertex2f(x, y); 
   		}
   	glEnd();
   	
   	//紫色三角形 
   	glColor3f(0.6313, 0.5137, 0.5137);
   	for(int j=0; j<4; j++)
   	{
		glBegin(GL_POLYGON);
			for(int i=125; i<135; i++)
			{  
	   			x=(noFace_Man_1[i+10*j][0]-382)*cos(45/180*PI)-(noFace_Man_1[i+10*j][1]-350)*sin(45/180*PI)+382-40;
				y=(noFace_Man_1[i+10*j][1]-382)*cos(45/180*PI)+(noFace_Man_1[i+10*j][1]-350)*sin(45/180*PI)+350+88;
	   			glVertex2f(x, y);
	   		}
	   	glEnd();
	}
	
	//左手
	glColor3f(0.2, 0.1725, 0.2);
	glBegin(GL_POLYGON);
		glVertex2f(412-26,900-668+60);
		for(int i=165; i<185; i++)
		{ 
		   	glVertex2f(noFace_Man_1[i][0]-23,noFace_Man_1[i][1]+60); 
		}
		for(int i=11; i<14; i++)
		{ 
		   	glVertex2f(noFace_Man_2[i][0],noFace_Man_2[i][1]); 
		}
	glEnd();
	
	//五官
   	glColor3f(0, 0, 0);
   	for(int j=0; j<3; j++)
   	{
		glBegin(GL_POLYGON);
			for(int i=71; i<81; i++)
			{  
	   			x=(noFace_Man_1[i+10*j][0]-382)*cos(45/180*PI)-(noFace_Man_1[i+10*j][1]-350)*sin(45/180*PI)+382-40;
				y=(noFace_Man_1[i+10*j][1]-382)*cos(45/180*PI)+(noFace_Man_1[i+10*j][1]-350)*sin(45/180*PI)+350+88;
	   			glVertex2f(x, y); 
	   		}
	   	glEnd();
	}
	//眼袋&下巴 
	for(int j=0; j<3; j++)
   	{
		glBegin(GL_POLYGON);
			for(int i=101; i<109; i++)
			{  
	   			x=(noFace_Man_1[i+8*j][0]-382)*cos(45/180*PI)-(noFace_Man_1[i+8*j][1]-350)*sin(45/180*PI)+382-40;
				y=(noFace_Man_1[i+8*j][1]-350)*sin(45/180*PI)+(noFace_Man_1[i+8*j][1]-382)*cos(45/180*PI)+350+88;
	   			glVertex2f(x, y); 
	   		}
	   	glEnd();
	}
   	
	//面具框
	glBegin(GL_LINE_LOOP);
		for(int i=20; i<42; i++)  
		{  
   			x=(noFace_Man_1[i][0]-382)*cos(45/180*PI)-(noFace_Man_1[i][1]-350)*sin(45/180*PI)+382-40;
			y=(noFace_Man_1[i][1]-382)*cos(45/180*PI)+(noFace_Man_1[i][1]-350)*sin(45/180*PI)+350+88;
   			glVertex2f(x, y);  
   		}
	glEnd();
	//杯盤 
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=0; i<20; i++)  
		{
			glVertex2f(cup[i][0]-30, cup[i][1]+58);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		for(int i=0; i<20; i++)  
		{  
   			glVertex2f(cup[i][0]-30, cup[i][1]+58);
   		}  
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i=11; i<15; i++)  
		{  
   			glVertex2f(cup[i][0]-30, cup[i][1]+58);
   		}  
	glEnd();
	glColor3f(0.2, 0.1725, 0.2);
	glBegin(GL_POLYGON);
		for(int i=11; i<15; i++)  
		{  
   			glVertex2f(cup[i][0]-30, cup[i][1]+58);
   		}  
	glEnd();
	
	//杯子
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=58; i<78; i++)  
		{  
   			glVertex2f(cup[i][0]-5,cup[i][1]-10);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		for(int i=58; i<78; i++)  
		{  
   			glVertex2f(cup[i][0]-5,cup[i][1]-10);
   		}  
	glEnd();
	glColor3f(1, 0.8823, 0.8039);
	for(int j=0; j<2; j++)
	{
		glBegin(GL_POLYGON);
			
			for(int i=78; i<83; i++)  
			{  
	   			glVertex2f(cup[i+5*j][0]-5,cup[i+5*j][1]-10);
	   		}  
		glEnd();
	}
	glColor3f(0, 0, 0);
	for(int j=0; j<3; j++)
	{
		glBegin(GL_LINE_STRIP);
			
			for(int i=78; i<83; i++)  
			{  
	   			glVertex2f(cup[i+5*j][0]-5,cup[i+5*j][1]-10);
	   		}  
		glEnd();
	}
	//杯底陰影 
	glColor3f(0.8521, 0.7266, 0.6264);
	glBegin(GL_POLYGON);
		for(int i=93; i<101; i++)  
		{
			glVertex2f(cup[i][0]-5, cup[i][1]-10);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		for(int i=93; i<101; i++)  
		{
			glVertex2f(cup[i][0]-5, cup[i][1]-10);
   		}  
	glEnd();
	//右手 
	glColor3f(0.2, 0.1725, 0.2);
	glBegin(GL_POLYGON);
		for(int i=15; i<21; i++)
		{ 
		   	glVertex2f(noFace_Man_2[i][0],noFace_Man_2[i][1]); 
		}
		for(int i=32; i<35; i++)
		{ 
		   	glVertex2f(noFace_Man_2[i][0],noFace_Man_2[i][1]); 
		}
	glEnd();
	glBegin(GL_POLYGON);
		for(int i=20; i<33; i++)
		{ 
		   	glVertex2f(noFace_Man_2[i][0],noFace_Man_2[i][1]); 
		}
	glEnd();
}
void noFace::straw(int n){
	if(n==0)
	{
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+12,strawberry[i][1]+48);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+12,strawberry[i][1]+48);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988+12-5*j,3*sin(2*i*PI/2000)+270-5*j+48);
			   		}
				}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988+12-j,3*sin(2*i*PI/2000)+270-15*j+48);
			   		}
				}
			glEnd();
		}
	}
	else if(n==1)
	{
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+80,strawberry[i][1]+40);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+80,strawberry[i][1]+40);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988+80-5*j,3*sin(2*i*PI/2000)+270-5*j+40);
			   		}
				}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988+80-j,3*sin(2*i*PI/2000)+270-15*j+40);
			   		}
				}
			glEnd();
		}
	}
	else if(n==2)
	{
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]-60,strawberry[i][1]+40);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]-60,strawberry[i][1]+40);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-60-5*j,3*sin(2*i*PI/2000)+270-5*j+40);
			   		}
				}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-60-j,3*sin(2*i*PI/2000)+270-15*j+40);
			   		}
				}
			glEnd();
		}
	}
	else if(n==3||n==4)
	{
		int k=n%3+1;
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+65*k,strawberry[i][1]+10*k);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]+65*k,strawberry[i][1]+10*k);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-5*j+65*k,3*sin(2*i*PI/2000)+270-5*j+10*k);
			   		}
		   		}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-j+65*k,3*sin(2*i*PI/2000)+270-15*j+10*k);
			   		}
				}
			glEnd();
		}
	}
	if(n==5)
	{
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0],strawberry[i][1]+5);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0],strawberry[i][1]+5);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-5*j,3*sin(2*i*PI/2000)+270-5*j+5);
			   		}
				}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-j,3*sin(2*i*PI/2000)+270-15*j+5);
			   		}
				}
			glEnd();
		}
	}
	else if(n==6||n==7)
	{
		int k=n%3+1;
		glColor3f(0.9854, 0.1312, 0.1145);
		glBegin(GL_POLYGON);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]-58*k,strawberry[i][1]+12*k);  
			}  
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
			for(int i=0; i<8; i++)  
			{  
			   	glVertex2f(strawberry[i][0]-58*k,strawberry[i][1]+12*k);  
			}  
		glEnd();
		for(int j=0; j<3; j++)
		{
			glBegin(GL_POLYGON);
				if(j==2)
				{
					for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-5*j-58*k,3*sin(2*i*PI/2000)+270-5*j+12*k);
			   		}
		   		}
				else
				{
				for(int i=0; i<2000; i++)  
					{  
			   			glVertex2f(2*cos(2*i*PI/2000)+988-j-58*k,3*sin(2*i*PI/2000)+270-15*j+12*k);
			   		}
				}
			glEnd();
		}
	}
}
void noFace::food(){
	//盤子陰影
	glColor3f(0.3706, 0.3, 0.2725);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(245*cos(2*i*PI/2000)+960,81*sin(2*i*PI/2000)+140);
   		}  
	glEnd();
	//盤子 
	glColor3f(1, 0.8823, 0.8039);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(240*cos(2*i*PI/2000)+998,76*sin(2*i*PI/2000)+150);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(240*cos(2*i*PI/2000)+998,76*sin(2*i*PI/2000)+150);
   		}  
	glEnd();
	//蛋糕陰影
	glColor3f(0.8521, 0.7266, 0.6264);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(164*cos(2*i*PI/2000)+960,48*sin(2*i*PI/2000)+145);
   		}
	glEnd();
	//蛋糕底層 
	glColor3f(0.8392, 0.6392, 0.4156);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(159*cos(2*i*PI/2000)+998,43*sin(2*i*PI/2000)+150);
   		}
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(159*cos(2*PI)+998,43*sin(2*PI)+150);
   		glVertex2f(157*cos(2*PI)+998,38*sin(2*PI)+270);
   		glVertex2f(157*cos(PI)+998,38*sin(PI)+270);
   		glVertex2f(159*cos(PI)+998,43*sin(PI)+150);	
   	glEnd();
   	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(159*cos(i*PI/2000+PI)+998,43*sin(i*PI/2000+PI)+150);
   		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2f(159*cos(2*PI)+998,43*sin(2*PI)+150);
   		glVertex2f(157*cos(2*PI)+998,38*sin(2*PI)+270);
   		glVertex2f(157*cos(PI)+998,38*sin(PI)+270);
   		glVertex2f(159*cos(PI)+998,43*sin(PI)+150);	
   	glEnd();
	//蛋糕上層 
	glColor3f(0.9058, 0.7568, 0.5803);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(157*cos(2*i*PI/2000)+998,38*sin(2*i*PI/2000)+270);
   		}  
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(157*cos(i*PI/2000)+998,38*sin(i*PI/2000)+270);  
   		}  
	glEnd();
	//紋路 
	glColor3f(0.6353, 0.4863, 0.4039);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<2000; i++)  
		{  
   			glVertex2f(157*cos(0.65*i*PI/2000+1.1*PI)+998,38*sin(0.65*i*PI/2000+1.1*PI)+275);  
   		}  
	glEnd();
	//草莓
	for(int k=0; k<8; k++)
	{
		straw(k);
	}
	
	//時鐘本人
	glColor3f(0.4705, 0.2901, 0.1961);
	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(60*cos(2*PI*i/2000)+711, 60*sin(2*PI*i/2000)+900-140);
   		}
   	glEnd();
   	glColor3f(0.6078, 0.4823, 0.4509);
   	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(48*cos(2*PI*i/2000)+711, 48*sin(2*PI*i/2000)+900-140);
   		}
   	glEnd();
   	glColor3f(0.3254, 0.2901, 0.2705);
   	glBegin(GL_POLYGON);
		for(int i=0; i<2000; i++)  
		{
   			glVertex2f(42*cos(2*PI*i/2000)+711, 42*sin(2*PI*i/2000)+900-140);
   		}
   	glEnd();

//9:00
	glColor3f(0.9254, 0.9901, 0.9705);
   	glBegin(GL_LINE_STRIP);
   		glVertex2f(32*cos(0.5*PI)+711,32*sin(0.5*PI)+900-140);
   		glVertex2f(711,900-140);
   		glVertex2f(20*cos(PI)+711,20*sin(PI)+900-140);
   	glEnd();
}
void noFace::draw ()
{
	glLineWidth(1);
	glEnable(GL_LINE_SMOOTH);
	background();
	popo();
	if(noFaceNum==2)
		noFace_2();
	else{
		noFace_1();
		PlaySound("glass.wav", NULL, SND_ASYNC|SND_FILENAME);
	}
	isShow=true;
	food();
	glFlush ( );
}
