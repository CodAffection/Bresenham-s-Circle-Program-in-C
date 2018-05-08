// Author : youtube channel-dotnetmob
// Date : 23-May-2015
// Description : program for drawing circle using 
//bresenham's mid point circle algorithm

#include<stdio.h>
#include<graphics.h>

void circleplotpt(int x,int y,int x1,int y1)
{
	//change 3rd parameter ie.15 to any other valid color number
	//like 2 for green
	putpixel(x+x1,y+y1,15);
	putpixel(x-x1,y+y1,15);
	putpixel(x+x1,y-y1,15);
	putpixel(x-x1,y-y1,15);
	putpixel(x+y1,y+x1,15);
	putpixel(x-y1,y+x1,15);
	putpixel(x+y1,y-x1,15);
	putpixel(x-y1,y-x1,15);
}

void circlemidpt(int x,int y,int r)
{
	int x1=0,y1=r,p=1-r;
	circleplotpt(x,y,x1,y1);
	while(x1<y1)
	{
		x1++;
		if(p<0)
			p+=2*x1+1;
		else
		{
			y1--;
			p+=2*(x1-y1)+1;
		}
		circleplotpt(x,y,x1,y1);
	}
}


void main()
{
	int xc,yc,x,gd=DETECT,gm,r;
	do
	{
	//change below directory according to your bgi directory
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	printf("\nEnter cirdcle centre cordinates : ");
	scanf("%d%d",&xc,&yc);
	printf("\nEnter the circle radius: ");
	scanf("%d",&r);

	clrscr();
	cleardevice();

	circlemidpt(xc,yc,r);
	delay(2000);

	printf("Enter 'y' for try again");
	}while(getch()=='y');
}