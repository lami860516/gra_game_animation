#include <windows.h>
#include <gl/gl.h>
#include <cmath>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include <windows.h>
#include <string>
#define MAX_CHAR        128
bool isFight=false;
int p3OffsetX;
int MyTime=0;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);  
	gluOrtho2D (0, 1600, 0, 900);
}
void circle(int x,int y,float r,int style,int N,int angle){
	glBegin(style);
	float R=r;
	int n=N;
	for (int i = 0; i < n; i++)
		glVertex2f(x+R*cos( M_PI*i / 180+(angle*M_PI/180)), y+R*sin(M_PI*i / 180+(angle*M_PI/180)));//計算坐標
    glEnd ( );
}
class dragonCat{
	public:	
		float position[97][2]={//  15~23 77~84 88~96 //47~57 //One 0~23 g 58~96 //不25 ~46
		{741,900-509},{732,900-511},{722,900-517},{715,900-525},{707,900-538},{702,900-553},{697,900-567},{695,900-580},{691,900-595},{688,900-610},
		{686,900-628},{682,900-647},{679,900-665},{674,900-683},{668,900-707},{653,900-707},{635,900-708},{628,900-715},{632,900-728},{633,900-729},
		{646,900-741},{658,900-752},{669,900-761},{667,900-738},{668,900-707},{667,900-738},{670,900-777},{673,900-794},{680,900-811},{690,900-820},
		{691,900-827},{690,900-820},{698,900-826},{699,900-820},{710,900-811},{729,900-810},{753,900-811},{777,900-813},{803,900-811},{825,900-809},
		{845,900-810},{862,900-816},{881,900-824},{892,900-825},{903,900-814},{909,900-795},{909,900-778},{909,900-771},{916,900-759},{921,900-743},
		{922,900-726},{923,900-705},{922,900-684},{921,900-664},{916,900-646},{910,900-629},{902,900-612},{889,900-597},{880,900-588},{871,900-581},
		{872,900-570},{879,900-572},{872,900-570},{872,900-562},{878,900-564},{872,900-562},{868,900-555},{866,900-550},{856,900-548},{855,900-542},
		{851,900-540},{848,900-531},{844,900-525},{837,900-516},{825,900-509},{808,900-505},{793,900-502},{791,900-492},{797,900-491},{794,900-471},
		{789,900-448},{776,900-468},{773,900-489},{779,900-491},{780,900-501},{793,900-502},{780,900-501},{757,900-503},{756,900-495},{764,900-494},
		{756,900-472},{751,900-452},{744,900-435},{738,900-452},{736,900-470},{731,900-498},{739,900-497}
		};
		float stom[19][2]={
		{900,900-781},{891,900-790},{879,900-797},{866,900-803},{850,900-805},{835,900-798},{824,900-785},{817,900-768},{811,900-748},{808,900-727},
		{807,900-707},{809,900-686},{819,900-642},{827,900-628},{837,900-612},{850,900-600},{864,900-594},{880,900-595},{890,900-598}
		};
		float eye[2][2]={{822,900-548},{826,900-548}};
		float stomGra[20][2]={
		{846,900-621},{847,900-639},{851,900-630},{858,900-625},{872,900-606},{872,900-620},{878,900-614},{888,900-613},{840,900-654},{838,900-669},
		{844,900-666},{853,900-667},{872,900-632},{869,900-648},{877,900-641},{886,900-641},{895,900-620},{896,900-632},{901,900-629},{907,900-628}
		};
		float mow[9][2]={
		{821,900-570},{808,900-572},{796,900-578},{831,900-576},{813,900-583},{799,900-595},{823,900-588},{818,900-595},{817,900-599}
		};
		float handR[28][2]={
		{790,900-603},{800,900-620},{810,900-638},{817,900-654},{820,900-670},{820,900-681},{829,900-683},{832,900-690},{829,900-683},{820,900-681},
		{818,900-690},{827,900-699},{818,900-690},{811,900-694},{818,900-707},{811,900-694},{806,900-695},{808,900-708},{806,900-695},{800,900-695},
		{800,900-703},{800,900-695},{789,900-690},{776,900-682},{765,900-673},{757,900-662},{749,900-650},{735,900-632}
		};
		float handL[25][2]={
		{802,900-623},{795,900-642},{785,900-660},{774,900-678},{762,900-689},{752,900-694},{755,900-707},{752,900-694},{747,900-695},{747,900-713},
		{747,900-695},{736,900-695},{739,900-707},{736,900-695},{730,900-692},{726,900-702},{730,900-692},{727,900-684},{723,900-693},{727,900-684},
		{723,900-673},{723,900-658},{728,900-643},{732,900-628},{739,900-606}
		};
		float nose[4][2]={
		{861,900-549},{857,900-557},{863,900-556},{869,900-556}
		};
		float one[24][2]={//~17
		{679,900-778},{676,900-799},{677,900-815},{697,900-813},{715,900-806},{696,900-796},{679,900-778},{696,900-796},{715,900-806},{736,900-811},
		{759,900-813},{780,900-816},{797,900-820},{811,900-830},{825,900-838},{839,900-833},{847,900-822},{847,900-807},{844,900-792},{839,900-775},
		{832,900-759},{823,900-747},{812,900-733},{802,900-722}
		};
		float umbrella[29][2]={
		{854,900-326},{852,900-339},{812,900-352},{775,900-368},{784,900-363},{762,900-381},{745,900-402},{731,900-425},{722,900-456},{748,900-435},
		{772,900-426},{793,900-413},{823,900-401},{859,900-395},{887,900-381},{922,900-367},{966,900-366},{991,900-364},{1012,900-368},{1026,900-375},
		{1012,900-354},{998,900-343},{980,900-334},{957,900-328},{938,900-327},{908,900-328},{883,900-333},{862,900-338},{854,900-326} 
		};
		float umbreCom[32][2]={
		{796,900-365},{787,900-380},{779,900-397},{775,900-410},{855,900-349},{855,900-361},{856,900-376},{858,900-386},{920,900-332},{931,900-336},
		{946,900-345},{959,900-354},{922,900-528},{870,900-386},{877,900-383},{930,900-527},{930,900-527},{922,900-528},{922,900-540},{930,900-560},
		{935,900-575},{933,900-586},{926,900-585},{922,900-575},{917,900-574},{915,900-582},{923,900-594},{934,900-597},{944,900-592},{948,900-578},
		{946,900-566},{938,900-546}
		};
		float umbreHand[18][2]={
		{904,900-624},{914,900-603},{920,900-588},{923,900-572},{935,900-572},{923,900-572},{921,900-566},{932,900-563},{921,900-566},{914,900-562},
		{922,900-555},{932,900-556},{922,900-555},{914,900-562},{904,900-564},{893,900-568},{882,900-573},{868,900-582}
		};
		float posiX,posiY;
		void pushRight();
		void pushLeft();
		void print();
		void init();
		bool isOne;
		bool isLastRight;
		bool isUmbrella;
};
dragonCat DC;
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
		glColor3f (0,0,0);
		//umbrellaLine
		
		glBegin(GL_LINE_LOOP  );
		for(int i=16;i<31;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		//umbreHand
		glColor3f (0.451, 0.451, 0.37);
		glBegin(GL_POLYGON);
		for(int i=0;i<18;i++){
			if(i==4||i==7||i==10||i==11||i==12)
				continue;
			glVertex2fv(umbreHand[i]);
		}
		glEnd ( );
		glColor3f (0,0,0);
		glBegin(GL_LINE_STRIP );
		for(int i=0;i<18;i++){
			glVertex2fv(umbreHand[i]);
		}
		glEnd ( );
	}
	//body
	glColor3f (0.451, 0.451, 0.37);
	glBegin(GL_POLYGON    );
	for(int i=0;i<15;i++)
		glVertex2fv(position[i]);
	if(isOne){
		for(int i=24;i<77;i++)
			glVertex2fv(position[i]);
		
	}else{
		glVertex2fv(position[22]);
		for(int i=0;i<18;i++)
			glVertex2fv(one[i]);
		for(int i=57;i<77;i++)
			glVertex2fv(position[i]);
		
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
	glColor3f (0, 0, 0);
	
	
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
	for(int i=0;i<19;i++)
		glVertex2fv(stom[i]);
	for(int i=57;i>46;i--)
		glVertex2fv(position[i]);
	glEnd ( );
	//stomLine
	glColor3f (0.318,0.318,0.259);
	//glColor3f (0,0,0);
	glBegin(GL_LINE_LOOP    );
	for(int i=0;i<19;i++)
		glVertex2fv(stom[i]);
	for(int i=57;i>46;i--)
		glVertex2fv(position[i]);
	glEnd ( );
	//stomGra
	glColor3f (0.451, 0.451, 0.37);
	for(int i=0;i<20;i++){
		if(i%4==0)
			glBegin(GL_POLYGON);
		glVertex2fv(stomGra[i]);
		if(i%4==3)
			glEnd ( );
	}
	//stomLine
	
	//glColor3f (0,0,0);
	glColor3f (0.318,0.318,0.259);
	for(int i=0;i<20;i++){
		if(i%4==0)
			glBegin(GL_LINE_LOOP);
		glVertex2fv(stomGra[i]);
		if(i%4==3)
			glEnd ( );
	}
	//oneFoot
	if(!isOne){
		glColor3f (0.451, 0.451, 0.37);
		glBegin(GL_POLYGON    );
		glVertex2fv(one[12]);
		for(int i=17;i<24;i++)
			glVertex2fv(one[i]);
		glEnd ( );
	}
	//bodyLine
	
	//glColor3f (0,0,0);
	glColor3f (0.318,0.318,0.259);
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
	glColor3f (0.318,0.318,0.259);
	for(int i=0;i<9;i++){
		if(i%3==0)
			glBegin(GL_LINE_STRIP );
		glVertex2fv(mow[i]);
		if(i%3==2)
			glEnd ( );
	}
	//handR
	if(isOne){
		glColor3f (0.451, 0.451, 0.37);
		glBegin(GL_POLYGON);
		for(int i=0;i<28;i++){
			if(i==6||i==7||i==8||i==9||i==11||i==12)
				continue;
			glVertex2fv(handR[i]);
		}
		glEnd ( );
	}
	//handLine
	
	//glColor3f (0,0,0);
	glColor3f (0.318,0.318,0.259);
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
	glColor3f (0.318,0.318,0.259);
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
		
		glColor3f (0,0,0);
		glBegin(GL_LINES  );
		for(int i=12;i<16;i++)
			glVertex2fv(umbreCom[i]);
		glEnd ( );
		
		
		glColor3f (0.384,0.365,0.455);
		glBegin(GL_POLYGON);
		for(int i=1;i<29;i++)
			glVertex2fv(umbrella[i]);
		glEnd ( );
		
		glColor3f (0,0,0);
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
class fight{
	public:
		float carpKingTailRed[19][2]={
		{1197,900-201},{1183,900-189},{1165,900-171},{1150,900-148},{1150,900-122},{1167,900-126},{1170,900-147},{1183,900-168},{1204,900-187},{1221,900-201},
		{1244,900-201},{1263,900-190},{1286,900-178},{1306,900-158},{1318,900-165},{1304,900-189},{1286,900-201},{1271,900-207},{1251,900-215}
		};
		float carpKingTailWhite[16][2]={
		{1165,900-136},{1185,900-132},{1205,900-130},{1217,900-140},{1221,900-154},{1235,900-159},{1257,900-156},{1282,900-156},{1291,900-161},{1311,900-165},
		{1194,900-132},{1198,900-163},{1217,900-205},{1274,900-154},{1257,900-180},{1228,900-209}
		};
		float carpBody[19][2]={
		{1213,900-193},{1182,900-200},{1164,900-207},{1129,900-213},{1072,900-244},{1060,900-262},{1060,900-295},{1070,900-328},{1087,900-347},{1104,900-342},
		{1119,900-356},{1143,900-358},{1173,900-354},{1200,900-340},{1218,900-322},{1232,900-297},{1244,900-255},{1251,900-213},{1248,900-202} 
		};
		float carpChi[11][2]={
		{1226,900-217},{1217,900-246},{1203,900-269},{1196,900-288},{1204,900-298},{1227,900-298},{1262,900-293},
		{1234,900-238},{1196,900-288},{1200,900-293},{1248,900-275}
		};
		float carpLine[28][2]={
		{1157,900-210},{1181,900-216},{1185,900-226},{1205,900-220},//4
		{1129,900-214},{1129,900-228},{1147,900-229},{1149,900-243},{1172,900-245},{1178,900-259},//10
		{1125,900-245},{1074,900-243},//12
		{1138,900-250},{1150,900-252},{1169,900-267},//15
		{1210,900-205},{1205,900-226},{1197,900-228},{1199,900-245},{1187,900-252},{1178,900-268},{1173,900-272},{1174,900-287},//23
		{1147,900-340},{1164,900-339},{1182,900-333},{1199,900-316},{1210,900-303} //28
		};
		float carpMouth[17][2]={
		{1074,900-334},{1078,900-323},{1090,900-313},{1110,900-311},{1128,900-318},{1145,900-333},{1144,900-348},{1134,900-360},{1117,900-356},{1112,900-346},
		{1087,900-346},{1093,900-327},{1116,900-326},{1129,900-339},{1122,900-349},{1111,900-343},{1094,900-340}
		};
		float CarpUpChi[9][2]={
		{1128,900-215},{1100,900-192},{1081,900-187},{1089,900-206},{1104,900-209},{1043,900-199},{1070,900-218},{1037,900-231},{1083,900-242}
		};
		float carpTwoChi[19][2]={
		{1131,900-306},{1148,900-297},{1162,900-295},{1177,900-298},{1192,900-306},{1210,900-312},{1228,900-316},{1247,900-311},{1268,900-303},{1283,900-296},
		{1097,900-348},{1102,900-360},{1116,900-367},{1134,900-371},{1155,900-372},{1174,900-376},{1186,900-387},{1190,900-398},{1185,900-407}
		};
		float carpLastChi[9][2]={
		{1209,900-332},{1237,900-358},{1231,900-341},{1252,900-345},{1251,900-332},{1265,900-327},{1258,900-317},{1268,900-312},{1231,900-305}
		};
		float upDialog[8][2]={
		{106,900-227},{780,900-227},{757,900-219},{744,900-201},{737,900-176},{727,900-145},{717,900-101},{106,900-101}
		};
		float RightDialog[7][2]={
		{846,900-620},{900,900-574},{900,900-440},{927,900-418},{1487,900-418},{1500,900-437},{1500,900-620}
		};
		float eye[2]={1127,900-277};
		char* talk[4]={{"啊! 野生的鯉魚王跳了出來!"},{"就決定是你了! 龍貓!"},{"想要龍貓做什麼?"},{"鯉鯉魚王文明的被解決掉了"}} ;
		void drawString(const char* str);
		void drawCNString(const char* str);
		void selectFont(int size, int charset, const char* face);
		void ctcircle(int x,int y ,float R,float c,int style);
		void start();
		void drawBackGround();
		void drawCarpKing();
		void drawDialog();
		void drawRightDialog();
		void circle(int x,int y,float r,int style,int N,int angle);
		bool isFightStartFinish=false;	
		bool isFighting=false;
		int talkIndex=0;
		char* wayToEat[4]={{"生吃就好"},{"蒸了"},{"烤了"},{"炸了"}};
		int curX=864,curY=900-748;
		int curXL=864,curXR=1233,curYU=900-748,curYD=900-836;
		int MyTime=0;
};
fight Fight;
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
	    drawString("!!!!!!!!!!!!!!!!!!!!!!");
		glColor3f (0,0,0);
		glPushMatrix ();
		glTranslatef(0,MyTime/3,0);
		glBegin(GL_POLYGON);
			glVertex2f(0,450);glVertex2f(0,900);glVertex2f(1600,900);glVertex2f(1600,450);
		glEnd ( );
		glPopMatrix(); 
		glPushMatrix ();
		glTranslatef(0,-MyTime/3,0);
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
    drawCNString("鯉魚王");
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
    drawCNString("龍貓");
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
    drawString("Lv9999");
    glColor3f(0.941,0.573,0.439);
    glRasterPos2f(1073, 900-532);
    selectFont(27, DEFAULT_CHARSET, "Comic Sans MS");
    drawString("HP");
    glLineWidth(10.f); 
	glColor3f (0.204,0.937,0.494);
	glBegin(GL_LINES);
		glVertex2f(1135,900-520);glVertex2f(1467,900-520);
	glEnd ( );
	glLineWidth(0.001f); 
	glColor3f(0.247,0.247,0.247);
    glRasterPos2f(1250, 900-572);
    selectFont(30, DEFAULT_CHARSET, "Comic Sans MS");
    drawString("9999999/1");
    glLineWidth(10.f); 
	glColor3f (0.914,0.973,0.510);
    glRasterPos2f(940, 900-612);
    selectFont(20, DEFAULT_CHARSET, "Comic Sans MS");
    drawString("EXP");
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
void fight::circle(int x,int y,float r,int style,int N,int angle){
glBegin(style);
	float R=r;
	int n=N;
	for (int i = 0; i < n; i++)
		glVertex2f(x+R*cos( M_PI*i / 180+(angle*M_PI/180)), y+R*sin(M_PI*i / 180+(angle*M_PI/180)));//計算坐標
    glEnd ( );
}
void myidle()  {  
	if(isFight){
		Fight.MyTime ++;  
		//測試用 
		Fight.MyTime=2250;
	    if(Fight.MyTime==2250&&Fight.isFightStartFinish==false){
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
	    }
	    if(!Fight.isFightStartFinish)
	    	Fight.start();
	    
	}
} 
/*
	selectFont(48, DEFAULT_CHARSET, "YouYuan");
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2f(710, 505);
    drawCNString("傳統的中國漢字");
	glFlush ( );*/
	
void gameStart(void){
	glClear (GL_COLOR_BUFFER_BIT);
	DC.init();
	MyTime=0;
	isFight=true;
	
	//吵死了 
	PlaySound("fight.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
void myKey(unsigned char key, int x, int y){ 
	if(Fight.isFighting){
		switch(key){
	   	case ' ':
		   	if(Fight.isFighting&&Fight.talkIndex==4)
		   		exit(0);
		    
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
   
}
void SpecialKey(GLint key,GLint x,GLint y){  
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
    
}  
void myMouse (int touch, int state, int x, int y){
	float nowX=x*2;
	float nowY=900-y*2;
	if(isFight){
		if(touch == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    	{
	    	glClear (GL_COLOR_BUFFER_BIT);
	    	//click START
	    	if(190<nowX && nowX<700 && 900-490<nowY && nowY<900-370)
	    	{
	    		
	    	}
			
			//click EXIT
	    	if(190<nowX && nowX<700 && 900-678<nowY && nowY<900-558)
	    	{
	    		
	    	}
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
	glutDisplayFunc(gameStart);
	glutIdleFunc(myidle);
	glutMainLoop ( );              

}
