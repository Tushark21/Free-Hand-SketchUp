#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>

//Function to Erase
void eraser(int l)
{
union REGS i,o;
int x,y,c;

i.x.ax=1;
int86(0x33,&i,&o);

while(!kbhit())
{
i.x.ax=3;
int86(0x33,&i,&o);
x=o.x.cx;
y=o.x.dx;
gotoxy(1,1);
cout<<"("<<x<<","<<y<<")  ";
c=o.x.bx;

i.x.ax=2;                          //value 2  Hides Pointer
int86(0x33,&i,&o);
if(c==1 && x<550 && y>40)
{
if(y-l<=40)
{
setcolor(0);
rectangle(x-l+1,42,x-1,y-1);
bar(x-l,41,x-1,y-1);
}

else
{
setcolor(0);
rectangle(x-l+1,y-l+1,x-1,y-1);
bar(x-l,y-l,x-1,y-1);
}
}

//
else if(c==1 && x>590 && x<600 && y>55 && y<65)
{
gotoxy(1,2);
cout<<"Small ";
eraser(10);
}

else if(c==1 && x>580 && x<610 && y>80 && y<110)
{
gotoxy(1,2);
cout<<"Medium";
eraser(30);
}

else if(c==1 && x>570 && x<620 && y>130 && y<180)
{
gotoxy(1,2);
cout<<"Large ";
eraser(50);
}
//

if(c==1 && x>231 && x<281 && y>16 && y<33)
{
i.x.ax=1;                          //value 2  Unhides Pointer
int86(0x33,&i,&o);
goto again;
}

i.x.ax=1;                          //value 2  Unhides Pointer
int86(0x33,&i,&o);
}

again:
}

//Function to call Eraser
void calleraser()
{
//
union REGS i,o;
int x,y,c;

i.x.ax=1;
int86(0x33,&i,&o);

while(!kbhit())
{
i.x.ax=3;
int86(0x33,&i,&o);
x=o.x.cx;
y=o.x.dx;
gotoxy(1,1);
cout<<"("<<x<<","<<y<<")  ";
c=o.x.bx;

gotoxy(1,2);

if(c==1 && x>590 && x<600 && y>55 && y<65)
{
cout<<"Small ";
eraser(10);
}

else if(c==1 && x>580 && x<610 && y>80 && y<110)
{
cout<<"Medium";
eraser(30);
}

else if(c==1 && x>570 && x<620 && y>130 && y<180)
{
cout<<"Large ";
eraser(50);
}

else if(c==1 && x>231 && x<281 && y>16 && y<33)
{
goto again;
}

}

again:
bar(565,50,625,185);
//Colour Choices
setcolor(0);
rectangle(560,20,620,80);
line(590,20,590,80);
line(560,50,620,50);
setfillstyle(1,0);
floodfill(561,21,0);       //Black
setfillstyle(1,1);
floodfill(591,21,0);       //Blue
setfillstyle(1,4);
floodfill(561,51,0);       //Red
setfillstyle(1,2);
floodfill(591,51,0);       //Green
}


// Main Function
void main()
{union REGS i,o;

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setfillstyle(SOLID_FILL,15);
floodfill(50,50,15);

int col=0;
//Colour Choices
setcolor(0);
rectangle(560,20,620,80);
line(590,20,590,80);
line(560,50,620,50);
setfillstyle(1,0);
floodfill(561,21,0);       //Black
setfillstyle(1,1);
floodfill(591,21,0);       //Blue
setfillstyle(1,4);
floodfill(561,51,0);       //Red
setfillstyle(1,2);
floodfill(591,51,0);       //Green
gotoxy(76,1);
cout<<"Black";

line(0,40,550,40);
line(550,40,550,479);
rectangle(231,16,281,33);

gotoxy(30,2);
cout<<"Pencil";

rectangle(303,16,353,33);

gotoxy(39,2);
cout<<"Eraser";

gotoxy(1,2);
cout<<"Pencil";

int x,y,c;
setcolor(0);
i.x.ax=1;
int86(0x33,&i,&o);

while(!kbhit())
{
i.x.ax=3;
int86(0x33,&i,&o);
x=o.x.cx;
y=o.x.dx;
gotoxy(1,1);
cout<<"("<<x<<","<<y<<")  ";
c=o.x.bx;

if(c==1 && x<=550 && y>41)
{
i.x.ax=2;
putpixel(x-1,y-1,col);
putpixel(x-2,y-2,col);
putpixel(x-2,y-1,col);
putpixel(x-1,y-2,col);
}

//Change Pencil Color
else if(c==1 && x>560 && x<590 && y>20 && y<50)
{
col=0;
gotoxy(76,1);
cout<<"Black";
}

else if(c==1 && x>590 && x<620 && y>20 && y<50)
{
col=1;
gotoxy(76,1);
cout<<"Blue ";
}

else if(c==1 && x>560 && x<590 && y>50 && y<80)
{
col=4;
gotoxy(76,1);
cout<<"Red  ";
}

else if(c==1 && x>590 && x<620 && y>50 && y<80)
{
col=2;
gotoxy(76,1);
cout<<"Green";
}
//

else if(c==1 && x>303 && x<353 && y>16 && y<33)
{
gotoxy(1,2);
cout<<"Eraser";

setfillstyle(1,15);
bar(560,20,620,80);
rectangle(590,55,600,65);
rectangle(580,80,610,110);
rectangle(570,130,620,180);
calleraser();
gotoxy(1,2);
cout<<"Pencil";
}
i.x.ax=1;
}

getch();
cleardevice();
closegraph();
}
//K21