#include <windows.h>
#include <gl/gl.h>
#include <cmath>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include "all.hpp"
void dragonCat::circleline(int x,int y ,int R,float w,float e){ 
	int i;
 	int n=100;
 	float Pi=3.1415926;
	glBegin(GL_LINE_LOOP);
     for(int i=0; i<n; ++i)
     {	
         glVertex2f(x+w*R*cos(2*Pi/n*i), y+e*R*sin(2*Pi/n*i));
     }
	glEnd();}
void dragonCat::pushRight(){
	if(isLastRight){
		print();
	}else{
		isLastRight=true;
		for(int i=0;i<97;i++)
			position[i][0]=1600-position[i][0];
		for(int i=0;i<19;i++)
			stom[i][0]=1600-stom[i][0];
		for(int i=0;i<2;i++)
			eye[i][0]=1600-eye[i][0];
		for(int i=0;i<20;i++)
			stomGra[i][0]=1600-stomGra[i][0];
		for(int i=0;i<9;i++)
			mow[i][0]=1600-mow[i][0];
		for(int i=0;i<28;i++)
			handR[i][0]=1600-handR[i][0];
		for(int i=0;i<25;i++)
			handL[i][0]=1600-handL[i][0];
		for(int i=0;i<4;i++)
			nose[i][0]=1600-nose[i][0];
		for(int i=0;i<24;i++)
			one[i][0]=1600-one[i][0];
		for(int i=0;i<29;i++)
			umbrella[i][0]=1600-umbrella[i][0];
		for(int i=0;i<32;i++)
			umbreCom[i][0]=1600-umbreCom[i][0];
		for(int i=0;i<18;i++)
			umbreHand[i][0]=1600-umbreHand[i][0];
		print();
	}
}
void dragonCat::pushLeft(){
	if(!isLastRight){
		print();
	}else{
		isLastRight=false;
		for(int i=0;i<97;i++)
			position[i][0]=1600-position[i][0];
		for(int i=0;i<19;i++)
			stom[i][0]=1600-stom[i][0];
		for(int i=0;i<2;i++)
			eye[i][0]=1600-eye[i][0];
		for(int i=0;i<20;i++)
			stomGra[i][0]=1600-stomGra[i][0];
		for(int i=0;i<9;i++)
			mow[i][0]=1600-mow[i][0];
		for(int i=0;i<28;i++)
			handR[i][0]=1600-handR[i][0];
		for(int i=0;i<25;i++)
			handL[i][0]=1600-handL[i][0];
		for(int i=0;i<4;i++)
			nose[i][0]=1600-nose[i][0];
		for(int i=0;i<24;i++)
			one[i][0]=1600-one[i][0];
		for(int i=0;i<29;i++)
			umbrella[i][0]=1600-umbrella[i][0];
		for(int i=0;i<32;i++)
			umbreCom[i][0]=1600-umbreCom[i][0];
		for(int i=0;i<18;i++)
			umbreHand[i][0]=1600-umbreHand[i][0];
		print();
	}
}
void dragonCat::print(){
	//glClear (GL_COLOR_BUFFER_BIT);
	glLineWidth(0.001f); 
	//umbreHand
	
	if(isUmbrella){
		//umbrella
		glColor3f (0.314,0.294,0.353);//80,75,95
		glBegin(GL_POLYGON  );
		for(int i=16;i<21;i++)
			glVertex2fv(umbreCom[i]);
		for(int i=28;i<32;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		glBegin(GL_POLYGON  );
		for(int i=20;i<22;i++)
			glVertex2fv(umbreCom[i]);
		for(int i=27;i<29;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		glBegin(GL_POLYGON  );
		for(int i=21;i<24;i++)
			glVertex2fv(umbreCom[i]);
		for(int i=25;i<28;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		
		//umbrellaLine
		//glColor3f (0,0,0);
		glColor3f (0.294, 0.321, 0.345);
		glBegin(GL_LINE_LOOP  );
		for(int i=16;i<31;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		//umbreHand
		//glColor3f (0.451, 0.451, 0.37);
		glColor3f (0.431, 0.431, 0.431);
		glBegin(GL_POLYGON);
		for(int i=0;i<18;i++){
			if(i==4||i==7||i==10||i==11||i==12)
				continue;
			glVertex2fv(umbreHand[i]);
		}
		glEnd ( );
		//glColor3f (0,0,0);
		glColor3f (0.294, 0.321, 0.345);
		glBegin(GL_LINE_STRIP );
		for(int i=0;i<18;i++){
			glVertex2fv(umbreHand[i]);
		}
		glEnd ( );
	}
	//body
	//glColor3f (0.451, 0.451, 0.37);
	glColor3f (0.431, 0.431, 0.431);
	glBegin(GL_POLYGON    );
	for(int i=0;i<15;i++){
		glColor3f (0.431+0.001*i, 0.431+0.001*i, 0.431+0.001*i);
		glVertex2fv(position[i]);
	} 
		
	if(isOne){
		for(int i=24;i<77;i++){
			glColor3f (0.431+0.001*i, 0.431+0.001*i, 0.431+0.001*i);
			glVertex2fv(position[i]);
		}
			
		
	}else{
		glVertex2fv(position[22]);
		for(int i=0;i<18;i++){
			glColor3f (0.431+0.001*i, 0.431+0.001*i, 0.431+0.001*i);
			glVertex2fv(one[i]);
		}
			
		for(int i=57;i<77;i++){
			glColor3f (0.431+0.001*i, 0.431+0.001*i, 0.431+0.001*i);
			glVertex2fv(position[i]);
		}
			
		
	}
	
	for(int i=85;i<88;i++)
			glVertex2fv(position[i]);
	glEnd ( );
	glBegin(GL_POLYGON    );
	for(int i=14;i<24;i++)
		glVertex2fv(position[i]);
	glEnd ( );
	glBegin(GL_POLYGON    );
	for(int i=76;i<85;i++)
		glVertex2fv(position[i]);
	glEnd ( );
	glBegin(GL_POLYGON    );
	for(int i=87;i<97;i++)
		glVertex2fv(position[i]);
		glVertex2fv(position[0]);
	glEnd ( );

	
	
	//eyes
	glColor3f (1,1,1);
	circle(eye[0][0],eye[0][1],12,GL_POLYGON,360,0);
	//glColor3f (0, 0, 0);
	glColor3f (0.318,0.318,0.259);
	circle(eye[0][0],eye[0][1],12,GL_LINE_LOOP,360,0);
	circle(eye[1][0],eye[1][1],7,GL_POLYGON,360,0);
	//stom
	glColor3f (0.886,0.862,0.627);
	glBegin(GL_POLYGON    );
	for(int i=0;i<19;i++){
		glColor3f (0.886+0.0015*(i+57),0.862+0.0015*(57+i),0.627+0.0015*(57+i));
		glVertex2fv(stom[i]);
	}
	for(int i=57;i>46;i--){
		glColor3f (0.886+0.0015*i,0.862+0.0015*i,0.627+0.0015*i);
		glVertex2fv(position[i]);
	}
		
	glEnd ( );
	//stomLine
	glColor3f (0.294, 0.321, 0.345);
	//glColor3f (0,0,0);
	glBegin(GL_LINE_LOOP    );
	for(int i=0;i<19;i++)
		glVertex2fv(stom[i]);
	for(int i=57;i>46;i--)
		glVertex2fv(position[i]);
	glEnd ( );
	//stomGra
	//glColor3f (0.451, 0.451, 0.37);
	glColor3f (0.431, 0.431, 0.431);
	for(int i=0;i<20;i++){
		if(i%4==0)
			glBegin(GL_POLYGON);
		glVertex2fv(stomGra[i]);
		if(i%4==3)
			glEnd ( );
	}
	//stomLine
	
	//glColor3f (0,0,0);
	glColor3f (0.294, 0.321, 0.345);
	for(int i=0;i<20;i++){
		if(i%4==0)
			glBegin(GL_LINE_LOOP);
		glVertex2fv(stomGra[i]);
		if(i%4==3)
			glEnd ( );
	}
	//oneFoot
	if(!isOne){
		glColor3f (0.431, 0.431, 0.431);
		//glColor3f (0.451, 0.451, 0.37);
		glBegin(GL_POLYGON    );
		glVertex2fv(one[12]);
		for(int i=17;i<24;i++)
			glVertex2fv(one[i]);
		glEnd ( );
	}
	//bodyLine
	
	//glColor3f (0,0,0);
	glColor3f (0.294, 0.321, 0.345);
	if(isOne){
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<97;i++)
			glVertex2fv(position[i]);
		glEnd ( );
	}else{
		glBegin(GL_LINE_STRIP );
		for(int i=0;i<23;i++)
			glVertex2fv(position[i]);
		for(int i=0;i<24;i++)
			glVertex2fv(one[i]);
		glEnd ( );
		glBegin(GL_LINE_STRIP );
		for(int i=57;i<97;i++)
			glVertex2fv(position[i]);
		glVertex2fv(position[0]);
		glEnd ( );
	
	}
	//mow
	//glColor3f (0,0,0);
	glColor3f (0.294, 0.321, 0.345);
	for(int i=0;i<9;i++){
		if(i%3==0)
			glBegin(GL_LINE_STRIP );
		glVertex2fv(mow[i]);
		if(i%3==2)
			glEnd ( );
	}
	//handR
	if(isOne){
		//glColor3f (0.451, 0.451, 0.37);
		glColor3f (0.431, 0.431, 0.431);
		glBegin(GL_POLYGON);
		for(int i=0;i<28;i++){
			glColor3f (0.431+0.001*i, 0.431+0.001*i, 0.431+0.001*i);
			if(i==6||i==7||i==8||i==9||i==11||i==12)
				continue;
			glVertex2fv(handR[i]);
		}
		glEnd ( );
	}
	//handLine
	
	//glColor3f (0,0,0);
	glColor3f (0.294, 0.321, 0.345);
	glBegin(GL_LINE_STRIP);
	if(isOne){
		for(int i=0;i<28;i++)
			glVertex2fv(handR[i]);
	}else{
		for(int i=0;i<25;i++)
			glVertex2fv(handL[i]);
	}
	glEnd ( );
	//nose
	//glColor3f (0,0,0);
	glColor3f (0.294, 0.321, 0.345);
	glBegin(GL_POLYGON);
	for(int i=0;i<4;i++)
		glVertex2fv(nose[i]);
	glEnd ( );
	
	//umbrella
	if(isUmbrella){
		glColor3f (1,1,1);
		glBegin(GL_POLYGON  );
		for(int i=12;i<16;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		
		glColor3f (0.294, 0.321, 0.345);
		glBegin(GL_LINES  );
		for(int i=12;i<16;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		
		
		glColor3f (0.384,0.365,0.455);
		glBegin(GL_POLYGON);
		for(int i=1;i<29;i++)
			glVertex2fv(umbrella[i]);
		glEnd ( );
		
		glColor3f (0.294, 0.321, 0.345);
		glBegin(GL_LINE_LOOP  );
		for(int i=0;i<29;i++)
			glVertex2fv(umbrella[i]);
		glEnd ( );
		//umbrellaGra
		for(int i=0;i<12;i++){
			if(i%4==0)
				glBegin(GL_LINE_STRIP  );
			glVertex2fv(umbreCom[i]);
			if(i%4==3)
				glEnd ( );
		}
		
			
		
	}
	if(isFish){
		if(isOne){
			if(isLastRight){
				glPushMatrix ();
				glTranslatef(20,-10,0);
				fish();
				glPopMatrix(); 
				glPushMatrix ();
			}else{
				glPushMatrix ();
				glTranslatef(-20,-10,0);
				fish();
				glPopMatrix(); 
				glPushMatrix ();
			}
		}
		else{
			if(isLastRight){
				glPushMatrix ();
				glTranslatef(-50,-15,0);
				fish();
				glPopMatrix(); 
				glPushMatrix ();
			}else{
				glPushMatrix ();
				glTranslatef(50,-15,0);
				fish();
				glPopMatrix(); 
				glPushMatrix ();
			}
		}
	}
	
	
	glFlush();
	isOne=!isOne;
}
void dragonCat::init(){
	isLastRight=true;
    isOne=true;
    isUmbrella=false;
    for(int i=0;i<97;i++)
		position[i][1]-=40;
	for(int i=0;i<19;i++)
		stom[i][1]-=40;
	for(int i=0;i<2;i++)
		eye[i][1]-=40;
	for(int i=0;i<20;i++)
		stomGra[i][1]-=40;
	for(int i=0;i<9;i++)
		mow[i][1]-=40;
	for(int i=0;i<28;i++)
		handR[i][1]-=40;
	for(int i=0;i<25;i++)
		handL[i][1]-=40;
	for(int i=0;i<4;i++)
		nose[i][1]-=40;
	for(int i=0;i<24;i++)
		one[i][1]-=40;
	for(int i=0;i<29;i++)
		umbrella[i][1]-=40;
	for(int i=0;i<32;i++)
		umbreCom[i][1]-=40;
	for(int i=0;i<18;i++)
		umbreHand[i][1]-=40;
    
}
void dragonCat::circle(int x,int y,int r,int style,int N,int angle){
	glBegin(style);
	float R=r;
	int n=N;
	for (int i = 0; i < n; i++)
		glVertex2f(x+R*cos( M_PI*i / 180+(angle*M_PI/180)), y+R*sin(M_PI*i / 180+(angle*M_PI/180)));//­pºâ§¤¼Ð
    glEnd ( );
}
void dragonCat::fish(){
	glColor3f (1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f (809,900-769);	
	glVertex2f (794,900-767);glVertex2f (784,900-759);
	glVertex2f (780,900-745);glVertex2f (783,900-748);
	glVertex2f (788,900-747);glVertex2f (791,900-750);
	glVertex2f (794,900-753);glVertex2f (798,900-756);
	glVertex2f (800,900-758);glVertex2f (804,900-758);
	glVertex2f (808,900-758);glVertex2f (811,900-759);
	glVertex2f (813,900-761);glVertex2f (815,900-764);
	glEnd();
	glLineWidth(2);glLineWidth(1.f); 
	glColor3f (0,0,0);
	circleline(794,130,20,1.9,2.2);

	glLineWidth(1);glLineWidth(0.001f); 
	glBegin(GL_LINES);
	glVertex2f (789,900-749);glVertex2f (790,900-765);
	glVertex2f (809,900-760);glVertex2f (798,900-769);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f (780,900-745);glVertex2f (783,900-748);
	glVertex2f (788,900-747);glVertex2f (791,900-750);
	glVertex2f (794,900-753);glVertex2f (798,900-756);
	glVertex2f (800,900-758);glVertex2f (804,900-758);
	glVertex2f (808,900-758);glVertex2f (811,900-759);
	glVertex2f (813,900-761);glVertex2f (815,900-764);
	glEnd();
	glLineWidth(2);
	glColor3f (0.878, 0.349, 0.231);
	glBegin(GL_LINE_STRIP);
	glVertex2f (780,900-745);glVertex2f (781,900-752);
	glVertex2f (782,900-757);glVertex2f (785,900-761);
	glVertex2f (788,900-766);glVertex2f (793,900-769);
	glVertex2f (797,900-770);glVertex2f (801,900-770);
	glVertex2f (807,900-769);glVertex2f (811,900-768);
	glVertex2f (814,900-765);glVertex2f (817,900-763);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f (788,900-766);glVertex2f (781,900-770);
	glVertex2f (775,900-772);glVertex2f (773,900-778);
	glVertex2f (800,900-778);glVertex2f (799,900-770);
	glEnd();
	
	
	glColor3f (0.8, 0.80, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f (768,900-785);glVertex2f (768,900-843);
	glVertex2f (822,900-843);glVertex2f (822,900-785);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f (765,900-779);glVertex2f (825,900-779);
	glEnd();
	glLineWidth(1);
	glColor3f (0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f (768,900-785);glVertex2f (768,900-843);
	glVertex2f (822,900-843);glVertex2f (822,900-785);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f (765,900-777);glVertex2f (825,900-777);
	glVertex2f (825,900-785);glVertex2f (765,900-785);
	glEnd();
}

