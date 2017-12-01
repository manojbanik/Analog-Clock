#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>



#define CX 320
#define CY 140
#define R 66
#define R1 48
#define R2 37


void second(int , int , int , int , int );
void minute(int , int , int , int , int );
void hour(int , int , int , int  , int);
void address(void);
int d(void);


char ch_t[40];
char ch_d[40];


void main(void)
{
   int a=DETECT,b=0,i=320;
   initgraph(&a,&b,"D:\\tc\\bgi");
   setbkcolor(9);
   setcolor(WHITE);
   rectangle(190,30,460,250);
   setfillstyle(1,BLUE);
   floodfill(192,40,WHITE);
   setcolor(RED);
   ellipse(i,140,0,360,110,81);
   ellipse(i,140,0,360,114,81);
   ellipse(i,140,0,360,100,81);
   ellipse(i,140,0,360,112,81);
   ellipse(i,140,0,360,116,81);
   ellipse(i,140,0,360,106,81);
   ellipse(i,140,0,360,108,81);

   setfillstyle(1,WHITE);
   floodfill(i,140,RED);
    setcolor(BLUE);
   outtextxy(314,64,"12");
   outtextxy(316,210,"6");
   outtextxy(400,137,"3");
   outtextxy(230,137,"9");
   outtextxy(359,76,"1");
   outtextxy(383,101,"2");
   outtextxy(385,172,"4");
   outtextxy(355,199,"5");
   outtextxy(280,199,"7");
   outtextxy(250,172,"8");
   outtextxy(243,101,"10");
   outtextxy(273,77,"11");
   address();
   d();

}
void second(int x, int y, int x1, int y1, int color)
{

   setcolor(color);
   line( x, y, x1, y1);

}


void minute(int x, int y, int x1, int y1, int color)
{

   setcolor(color);
   line( x, y, x1, y1);

}


void hour(int x, int y, int x1, int y1, int color)
{

   setcolor(color);  //color
   line( x, y, x1, y1);

}

/**********************************************************************/

int d(void)
{
   int x = CX, y =CY-R, y1=CY-R1,y2=CY-R2;
   char ch=0,day=0;
   int new_x_s = CX, new_y_s=CY, new_x_m = CX, new_y_m=CY, new_x_h = CX, new_y_h=CY;

   float  theta;

   struct  dosdate_t  d;
   struct  dostime_t  t;

 while(!kbhit())
	{

	 _dos_getdate(&d);
	 _dos_gettime(&t);

   if(ch != t.second)
	 {

		second(CX, CY, new_x_s, new_y_s , 15);

		theta = (3.1415926*6*t.second) / 180;
		new_x_s = x + R * sin(theta);
		new_y_s = y + R*( 1-cos(theta) );
		second(CX, CY, new_x_s, new_y_s, BLUE);

		//digital clock
		setcolor(9); // To erase
		outtextxy(10, 10, ch_t);
		setcolor(4);
		sprintf(ch_t, "Ti: %2d:%2d:%02d",t.hour, t.minute, t.second);
		settextstyle(1, 0, 2);
		outtextxy(10,10, ch_t );

		if(day != d.day)
		{

		  setcolor(9); // To erage
		  outtextxy(10, 30, ch_d);
		  setcolor(4);
		  sprintf(ch_d, "Da: %02d/%02d/%02d.",d.day, d.month,d.year);
		  outtextxy(10, 30, ch_d );
		  day = d.day;
		}

		ch = t.second ;

		//min

		minute(CX, CY, new_x_m, new_y_m, 15);

		theta = (3.1415926*6*t.minute) / 180;
		new_x_m = x + R1 * sin(theta);
		new_y_m = y1 + R1*( 1-cos(theta) );
		minute(CX, CY, new_x_m, new_y_m, BLUE);

		//hour

		hour(CX, CY, new_x_h, new_y_h , 15);

		theta = (3.1415926*30*t.hour) / 180+(3.1415926*0.5*t.minute)/180;
		new_x_h = x + R2 * sin(theta);
		new_y_h = y2 + R2*( 1-cos(theta) );
		hour(CX, CY, new_x_h, new_y_h, BLUE);

  }
 }
return  0;
}

void address(void)
{
	   setcolor(1);
	   rectangle(1,370,639,479);
	   setfillstyle(1,15);
	   floodfill(100,400,1);
	   settextstyle(2,0,6);
	   outtextxy(65,380,"MADE BY : URMILA DAS");
	   outtextxy(65,400,"DEPT : CSE.");
	   outtextxy(65,420,"ROLL : 005");
	   outtextxy(65,438,"SEC : A");
	   outtextxy(65,455,"1ST YEAR,2ND SEMISTER.");

}

