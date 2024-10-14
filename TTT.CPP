#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
void win(){
cout<<"win";
}
void main(){ clrscr();
int gd = DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
int stop = 0;

int x1 = 225,y1 = 100,x2=100,y2=100+83.3;
int px[3]={175,300,425},py[3]={300,400,500};

while(x1<400){
line(x1,y1,x1,y1+250);
x1+=150;
} while(y2<300){
line(x1-375,y2,x1-75,y2);
y2+=100;
}
  for(int pyi = 0;pyi<3;pyi++){
  for(int pxi = 0;pxi<3;pxi++){
  putpixel(px[pxi],py[pyi]-175,7);
  }   }

int turn=0,over=0,play = 'o';
char game[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
while(turn<9){
  int key = 0 ;
  while(key < 1||key>9){
  key = getch();
  }
 for(int i = 0;i<3;i++){
 if(game[i]==play&&game[3+i]==play&&game[6+i]==play){win();
 }else if(game[(i*3)+0]==play&&game[(i*3)+1]==play&&game[(i*3)+2]==play){win();
 }else if(game[0]==play&&game[4]==play&&game[9]==play){win();
 }else if(game[2]==play&&game[4]==play&&game[7]==play){win();
 }}
 turn++;
 if(play == 'o'){
 play = 'x';
 }else{
 play = 'o';
 }

 }//turn
getch();
closegraph();
}


