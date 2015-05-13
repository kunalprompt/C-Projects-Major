#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void clrscr();
void gotoxy(int x,int y);
void box(int row,int col,int color);
void sequence1(int color);
void sequence2(int color);
void sequence3(int color);
void sequence4(int color);
void print_text(int);
int random_number40(void);
int main()
{
clrscr();
int color=41,i=0;
while(1)
{
if(color<=45)
{
switch(color)
{	
	case 41:
	{
	sequence1(color);
	sequence2(47);
	sequence3(47);
	sequence4(47);
	print_text(color);
	color++;
	usleep(100000);continue;	
	}
	case 42:
	{
	sequence1(47);
	sequence2(color);
	print_text(color);
	sequence3(47);
	sequence4(47);
	color++;
	usleep(100000);continue;
	}
	case 43:
	{
	sequence1(47);
	sequence2(47);
	sequence3(color);
	sequence4(47);
	print_text(color);
	color++;
	usleep(100000);continue;
	}
	case 44:
	{
	sequence1(47);
	sequence2(47);
	sequence3(47);
	sequence4(color);
	print_text(color);
	color++;
	usleep(100000);continue;
	}
	case 45:
	{
	sequence1(47);
	sequence2(47);
	sequence3(47);
	sequence4(47);
	print_text(color);
	color++;
	usleep(100000);continue;
	}
}
}
else color=41;
}
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
void box(int row,int col,int color)
{
gotoxy(row,col);
printf("%c[%dm",27,color);
printf("    ");
fflush(stdout);
printf("%c[0m",27);
gotoxy(row+1,col);
printf("%c[%dm",27,color);
printf("    ");
fflush(stdout);
printf("%c[0m",27);
}

void sequence1(int color)
{
int i=1,j=1;
int col=0,row=0;	
	for(i=1;i<=10;i++)//for first sequence
	{
	for(j=1;j<=20;j++)
	{
		row=4*i-3;
		col=7*j-6;
		box(1,col,color);
		box(37,col,color);
		box(row,1,color);
		box(row,134,color);
	}
	}
}
void sequence2(int color)
{
int i=1,j=1;
int col=0,row=0;
	for(i=2;i<=9;i++)//for 2nd sequence
	{
	for(j=2;j<=19;j++)
	{
		row=4*i-3;
		col=7*j-6;
		box(5,col,color);
		box(33,col,color);
		box(row,8,color);
		box(row,127,color);
	}
	}
}
void sequence3(int color)
{
int i=1,j=1;
int col=0,row=0;
	for(i=3;i<=8;i++)//for 3rd sequence
	{
	for(j=3;j<=18;j++)
	{
		row=4*i-3;
		col=7*j-6;
		box(9,col,color);
		box(29,col,color);
		box(row,15,color);
		box(row,120,color);
	}
	}
}
void sequence4(int color)
{
int i=1,j=1;
int col=0,row=0;
	for(i=4;i<=7;i++)//for 4th sequence
	{
	for(j=4;j<=17;j++)
	{
		row=4*i-3;
		col=7*j-6;
		box(13,col,color);
		box(25,col,color);
		box(row,22,color);
		box(row,113,color);
	}
	}
}
void print_text(int color)
{
gotoxy(20,50);
printf("%c[1;37;%dm",27,color);
printf("Welcome to Kunal's World of Programming");
fflush(stdout);
printf("%c[0m",27);
gotoxy(40,120);
}
/*
int random_number40(void)
{
time_t seconds;
seconds = time (NULL);
seconds=seconds%8;
int random=seconds+40;
return random;
}
int random_number(void)
{
time_t seconds;
seconds = time (NULL);
seconds=seconds%4;
int random=seconds+1;
return random;
}*/

