#include<stdio.h>
#include<stdlib.h>
void clrscr();
void gotoxy(int x,int y);
void box1(int);
int main()
{
clrscr();
int row,col=0;
int color=41;
while(1)
{
	for(color=41;color<=43;color++)
	{
	printf("%c[37;1;%dm",27,color-1);
	gotoxy(20,30);
	printf("HEY!YOU WON.");
	gotoxy(20,110);
	printf("CONGRATULATIONS!!!");
	printf("%c[0m",27);
	box1(color);
	usleep(1000000);
	}
}
gotoxy(42,162);
return 0;
}
void clrscr()
{
printf("%c[2J",27);
}
void gotoxy(int x,int y)
{
printf("%c[%d;%df",27,x,y);
}
void box1(int color)
{
int row,col=0;
printf("%c[%dm",27,color);
for(row=1;row<=19;row++)
{
	for(col=1;col<=80;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+1);
for(row=1;row<=19;row++)
{
	for(col=81;col<=160;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+2);
for(row=21;row<=39;row++)
{
	for(col=1;col<=80;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+3);
for(row=21;row<=39;row++)
{
	for(col=81;col<=160;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
}
