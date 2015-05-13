#include<stdio.h>
//functions declarations
void clrscr();
void gotoxy(int x,int y);
void box_row_inc(int,int);
void box_row_dec(int,int);
void straight_box_inc(int,int,int);
void straight_box_dec(int,int,int);
//universal variables
int i=0,j=0;
//start of main()
int main()
{
clrscr();
int count=0;
int sleep_time=50000;
for(count=0; count<5;count++)
{
for(i=10;i<=40;i++)
{
	box_row_inc(1,41);
	box_row_inc(10,42);
	box_row_inc(20,43);
	box_row_inc(30,44);
	box_row_inc(40,45);
	box_row_inc(50,46);
	box_row_inc(60,41);
	box_row_inc(70,42);
	box_row_inc(80,43);
	box_row_inc(90,44);
	box_row_inc(100,45);
	box_row_inc(110,46);
	usleep(sleep_time);
	clrscr();

}
for(i=40;i>=10;i--)
{
	box_row_dec(1,41);
	box_row_dec(10,42);
	box_row_dec(20,43);
	box_row_dec(30,44);
	box_row_dec(40,45);
	box_row_dec(50,46);
	box_row_dec(60,41);
	box_row_dec(70,42);
	box_row_dec(80,43);
	box_row_dec(90,44);
	box_row_dec(100,45);
	box_row_dec(110,46);
	usleep(sleep_time);
	clrscr();
}
for(j=40;j<=70;j++)
{
	straight_box_inc(3,j,41);
	straight_box_inc(6,j,42);
	straight_box_inc(9,j,43);
	straight_box_inc(12,j,44);
	straight_box_inc(15,j,45);
	straight_box_inc(18,j,46);
	straight_box_inc(21,j,41);
	straight_box_inc(24,j,42);
	straight_box_inc(27,j,43);
	straight_box_inc(30,j,44);
	straight_box_inc(33,j,45);
	straight_box_inc(36,j,46);
	straight_box_inc(39,j,41);
	usleep(sleep_time);
	clrscr();
}
for(j=70;j>=40;j--)
{
	straight_box_dec(3,j,41);
	straight_box_dec(6,j,42);
	straight_box_dec(9,j,44);
	straight_box_dec(12,j,45);
	straight_box_dec(15,j,46);
	straight_box_dec(18,j,41);
	straight_box_dec(21,j,42);
	straight_box_dec(24,j,43);
	straight_box_dec(27,j,44);
	straight_box_dec(30,j,45);
	straight_box_dec(33,j,46);
	straight_box_dec(36,j,42);
	straight_box_dec(39,j,41);
	usleep(sleep_time);
	clrscr();
}
}
return 0;
}//end of main()
//functions definition
void clrscr()
{
printf("%c[2J",27);
}
void gotoxy(int x,int y)
{
printf("%c[%d;%df",27,x,y);
}
void box_row_inc(int col,int color)
{	
	gotoxy(i,col);
	printf("%c[1;37;%dm",27,color);
	printf(" @ ");
	fflush(stdout);	
	printf("%c[0m",27);
}
void box_row_dec(int col,int color)
{
	gotoxy(i,col);
	printf("%c[1;37;%dm",27,color);
	printf(" ^ ");
	fflush(stdout);	
	printf("%c[0m",27);
}
void straight_box_inc(int row,int col,int color)
{
	gotoxy(row,col);
	printf("%c[1;37;%dm",27,color);
	printf(" > ");
	fflush(stdout);	
	printf("%c[0m",27);
}
void straight_box_dec(int row,int col,int color)
{
		gotoxy(row,col);
		printf("%c[1;37;%dm",27,color);
		printf(" < ");
		fflush(stdout);	
		printf("%c[0m",27);
}
























