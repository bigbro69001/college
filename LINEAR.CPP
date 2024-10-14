#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
void add(int ** a,char key){
	**a *= 10;
	**a += key-48;
}
void del(int **a){
	**a /= 10;
}
void nature(int **a){
	**a *= -1;
}
void main(){ clrscr();
int gd = DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
int midx = getmaxx()/2;
int midy = getmaxy()/2;
int v1x = 100 , v1y = 100 ;
int v2x = 100 , v2y = 100 ;
int stop = 1 , hover = 1,*loc[4] = {&v1x,&v1y,&v2x,&v2y};
float value = 1;
char key ;
while(stop){
	cout<<"use (-) to change nature of number "<<endl;
	for(int i = 1;i<=4;i++){
	switch(i){
		case 1 :
		cout<<"v (x) : "<<v1x;
		break;
		case 2 :
		cout<<"v (y) : "<<v1y;
		break;
		case 3 :
		cout<<"w (x) : "<<v2x;
		break;
		case 4 :
		cout<<"w (y) : "<<v2y;
		break;
		}
		if(hover == i){
		cout<<" <<";
		}
		cout<<endl;
	}
	int vectorx = midx+(v1x+v2x);
	int vectory = midy-(v1y+v2y);
	if(vectorx >= vectory){
	value = 200/float(vectorx);
	}else if(vectory >= vectorx){
	value = 200/float(vectory);
	}

	cout<<"vector x : "<<v1x+v2x<<endl;
	cout<<"vector y : "<<v1y+v2y<<endl;
	line(midx+200,midy,midx-200,midy);
	line(midx,midy+200,midx,midy-200);
	setcolor(2);
	line(midx,midy,midx+v1x*value,midy-v1y*value);
	setcolor(1);
	line(midx+v1x*value,midy-v1y*value,midx+(v1x+v2x)*value,midy-(v1y+v2y)*value);
	setcolor(3);
	line(midx,midy,midx+(v1x+v2x)*value,midy-(v1y+v2y)*value);
	outtextxy((vectorx-20)*value,(vectory-10)*value, "Vector");
	setcolor(7);
	key = getch();
	if(key == '\r'){
	stop = 0;
	}else if(key >= '0'&&key<='9'){
		add(&loc[hover-1],key);
	}else if(key == 'H'){
		hover--;
	}else if(key == 'P'){
		hover++;
	}else if(key == '\b'){
		del(&loc[hover-1]);
	}else if(key == '-'){
		nature(&loc[hover-1]);
	}

	if(hover < 1){
		hover = 4;
	}else if(hover > 4){
		hover = 1;
	}

	clrscr();
	cleardevice();
}
closegraph();
}


