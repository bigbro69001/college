#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
void main(){ clrscr();
int gd = DETECT, gm;
int stop = 0;

initgraph(&gd,&gm,"c:\\turboc3\\bgi");
for(int i = 200;i<=400;i+ 100){
line(i,150,i,300);
}
cleardevice();
delay(1000);

getch();
closegraph();
}


