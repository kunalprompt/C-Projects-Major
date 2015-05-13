#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<fcntl.h>
//===Functions Declaration Portion
int kbhit(void);
void clrscr();
void gotoxy(int,int);
void static_display();
void design_button(int x, int y, int ch, int color);
void instructions();
void infault();
int user();
void comp(int);
void user2();
int user_count1();
int user_count2();
int count_location();
void tie();
void initial_static();
void select_type();
//Global Declaration
static int arr[40][100];
static char name[20];
static char name2[20];
static int choice;
//===Start of main()
int main()
{
clrscr();
system("gcc champ.c -o champ.out");
system("./champ.out");
initial_static();
select_type();
clrscr();
static_display();
instructions();
//local variables
int count=0;
int btn1_row=10,btn2_row=20,btn3_row=30,btn_col1=30,btn_col2=50,btn_col3=70;
int btn_color=47;
int loc=0;
int counter1=0,counter2=0;
int i,j,k=0;
design_button(btn1_row,btn_col1,65,btn_color);
design_button(btn1_row,btn_col2,66,btn_color);
design_button(btn1_row,btn_col3,67,btn_color);
design_button(btn2_row,btn_col1,68,btn_color);
design_button(btn2_row,btn_col2,69,btn_color);
design_button(btn2_row,btn_col3,70,btn_color);
design_button(btn3_row,btn_col1,71,btn_color);
design_button(btn3_row,btn_col2,72,btn_color);
design_button(btn3_row,btn_col3,73,btn_color);
//=====================================================
switch(choice)
{
	case 1://we are playing game if user/player is playing first..SINGLE PLAYER FORMAT
	{
	gotoxy(36,68);
	printf("%c[32m",27);	
	printf("Computer");
	printf("%c[0m",27);
	count=count_location();
	while(count<=9)//for(count=1;count<9;)
	{
	loc=user();
	gotoxy(13,120);
	printf("%c[36m",27);
	printf("Game in progress...");
	fflush(stdout);
	usleep(1000000);
	printf("%c[0m",27);
	counter1=user_count1();//count for user
	if(counter1==32)			{usleep(1000000);system("gcc winner.c -o winner.out");system("./winner.out");}
			//clearing screen
			for(i=10;i<=15;i++)
			{
				for(j=120;j<=160;j++)
				{
				gotoxy(i,j);
				printf(" ");
				fflush(stdout);
				}
			}
			//reprinting data
				gotoxy(11,120);
				printf("%c[32m",27);
				printf("Computer is playing...");
				fflush(stdout);
				printf("%c[0m",27);
	usleep(500000);
	comp(loc);
	counter2=user_count2();//counts for computer
	if(counter2==31)			{usleep(1000000);system("gcc winnercomp.c -o winner.out");system("./winnercomp.out");}
	count=count_location();
		if(count==8) 
		{
		count=9;
		loc=user();
		counter1=user_count1();//count for user
		if(counter1==32)			{usleep(1000000);system("gcc winner.c -o winner.out");system("./winner.out");}
		break;
		}
	}
	if(count==9 && counter1!=32 && counter2!=31)	{usleep(1000000);tie();exit(1);}
	break;
	}
	case 2://Multiplayer FORMAT
	{
	gotoxy(36,68);
	printf("%c[32m",27);	
	printf("%s",name2);
	printf("%c[0m",27);
	count=count_location();
	while(count<=9)//for(count=1;count<9;)
	{
	loc=user();
	gotoxy(13,120);
	printf("%c[34m",27);
	printf("Game in progress...");
	fflush(stdout);
	usleep(1000000);
	printf("%c[0m",27);
	counter1=user_count1();//count for user
	if(counter1==32)			{usleep(1000000);gotoxy(20,50);printf("%s Congratulations. You won.",name);}
			//clearing screen
			for(i=10;i<=15;i++)
			{
				for(j=120;j<=160;j++)
				{
				gotoxy(i,j);
				printf(" ");
				fflush(stdout);
				}
			}
	user2();
	gotoxy(13,120);
	printf("%c[36m",27);
	printf("Game in progress...");
	fflush(stdout);
	usleep(1000000);
	printf("%c[0m",27);
	counter2=user_count2();//counts for computer
	if(counter2==31)			{usleep(1000000);gotoxy(20,50);printf("%s Congratulations. You won.",name2);}
	count=count_location();
		if(count==8) 
		{
		count=9;
		loc=user();
		counter1=user_count1();//count for user
		if(counter1==32)			{usleep(1000000);gotoxy(20,50);printf("%s Congratulations. You won.",name);}
		break;
		}
	}
	if(count==9 && counter1!=32 && counter2!=31)	{usleep(1000000);tie();exit(1);}
	break;
	}
}
gotoxy(42,120);
return 0;
}
//=========================================================
//functions definition
void clrscr()
{
printf("%c[2J",27);
}
void gotoxy(int x,int y)
{
printf("%c[%d;%df",27,x,y);
}
//////////////////////////////////////////////////////////
void initial_static()
{
clrscr();
gotoxy(2,65);
printf("%c[31m",27);
printf("**********************************");
printf("%c[0m",27);
printf("%c[31m",27);
gotoxy(3,65);
printf("*     Welcome to Tic Tac Toe     *");
printf("%c[0m",27);
gotoxy(4,65);
printf("%c[31m",27);
printf("**********************************");
printf("%c[0m",27);
gotoxy(5,110);
printf("%c[36m",27);
printf("Surprised!!!This is what we call innovational invention.");
gotoxy(6,110);
printf("A unique graphical game and you can play with computer");
gotoxy(7,110);
printf("as well as with your friend.");
gotoxy(8,110);
printf("Hope you will enjoy this game. Wish you all the best.");
printf("%c[0m",27);
}
void select_type()//to select the type of game
{
printf("%c[32m",27);
gotoxy(5,10);
printf("Select the type of game you want to play:");
gotoxy(6,10);
printf("1. Single Player");
gotoxy(7,10);
printf("2. Multi-Player");
printf("%c[0m",27);
gotoxy(9,10);
scanf("%d",&choice);
switch(choice)
{
	case 1:
	{
	printf("%c[47;35m",27);
	gotoxy(11,10);
	printf("Player enter your first name:");
	printf("%c[0m",27);
	gotoxy(12,10);
	scanf("%s",name);
	break;
	}
	case 2:
	{
	printf("%c[47;35m",27);
	gotoxy(11,10);
	printf("Player1 enter your first name:");
	printf("%c[0m",27);
	gotoxy(12,10);
	scanf("%s",name);
	printf("%c[47;35m",27);
	gotoxy(14,10);
	printf("Player2 enter your first name:");
	printf("%c[0m",27);
	gotoxy(15,10);
	scanf("%s",name2);
	break;
	}
}
}
void user2()//for player 2
{
int i=0,j=0;
int color_changed=40;
int location=0;
for(i=10;i<=15;i++)
{
	for(j=120;j<=160;j++)
	{
	gotoxy(i,j);
	printf(" ");
	fflush(stdout);
	}
}
gotoxy(10,120);
printf("%s select a location:-",name2);
fflush(stdout);
gotoxy(11,120);
scanf("%d",&location);
switch(location)
	{
	case 65	:
		{ arr[10][30]=1;design_button(10,30,1,color_changed); break;}
	case 66	:
		{ arr[10][50]=1;design_button(10,50,1,color_changed); break;}
	case 67	:
		{ arr[10][70]=1;design_button(10,70,1,color_changed); break;}
	case 68	:
		{ arr[20][30]=1;design_button(20,30,1,color_changed); break;}
	case 69	:
		{ arr[20][50]=1;design_button(20,50,1,color_changed); break;}
	case 70	:
		{ arr[20][70]=1;design_button(20,70,1,color_changed); break;}
	case 71	:
		{ arr[30][30]=1;design_button(30,30,1,color_changed); break;}
	case 72	:
		{ arr[30][50]=1;design_button(30,50,1,color_changed); break;}
	case 73	:
		{ arr[30][70]=1;design_button(30,70,1,color_changed); break;}
	default:
		{
		clrscr();
		gotoxy(16,40);
		printf("%c[31m",27);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++");
		gotoxy(17,40);
		printf("Wrong Location Selected. You Loose. Game Over!!!");
		gotoxy(18,40);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++");
		fflush(stdout);
		gotoxy(42,120);
		printf("%c[0m",27);
		exit(1);
		}
	}
}
/////////////////////////////////////////////////////////
void static_display()
{
int i=0,j=0;
for(j=1;j<=100;j++)
{
	gotoxy(1,j);//for top most row
	printf("%c[46m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(2,j);//for 2nd row
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(4,j);//for 4th row
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(39,j);//for 39th row design
	printf("%c[43m",27);
	printf(" ");	printf("%c[0m",27);
	printf("%c[0m",27);
	gotoxy(37,j);//for 37th row design
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	printf("%c[0m",27);
	gotoxy(40,j);//for bottom most row design
	printf("%c[46m",27);
	printf(" ");
	printf("%c[0m",27);
}
for(j=20;j<=80;j++)
{
	gotoxy(5,j);//for 10th row
	printf("%c[41m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(15,j);//for 15 row
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(25,j);//for 25 row
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(35,j);//for 35 row
	printf("%c[41m",27);
	printf(" ");
	printf("%c[0m",27);
}
for(i=10;i<=30;i++)
{
	gotoxy(i,20);//for 20th colum
	printf("%c[41m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(i,80);//for 81th column
	printf("%c[41m",27);
	printf(" ");
	printf("%c[0m",27);
}
for(i=5;i<=35;i++)
{
	gotoxy(i,40);//for 40th colum
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(i,60);//for 60th colum
	printf("%c[43m",27);
	printf(" ");
	printf("%c[0m",27);
}
for(i=1;i<=40;i++)
{
	gotoxy(i,1);//for first colum
	printf("%c[46m",27);
	printf(" ");
	printf("%c[0m",27);
	gotoxy(i,100);//for last column
	printf("%c[46m",27);
	printf(" ");
	printf("%c[0m",27);
}
//printing title
gotoxy(3,36);
printf("%c[1;35m",27);
printf("*^*^*^*^*");
printf("%c[0m",27);
printf("%c[1;30m",27);
printf("Tic Tac Toe");
printf("%c[0m",27);
printf("%c[1;35m",27);
printf("*^*^*^*^*");
printf("%c[0m",27);
//printing players name
gotoxy(36,28);
printf("%c[32m",27);
printf("%s",name);
gotoxy(36,48);
printf("%c[36m",27);
printf("Versus");
printf("%c[0m",27);
//rights reserved
gotoxy(38,32);
printf("All rights reserved with Kunal Sharma.");
fflush(stdout); 
}
void design_button(int x, int y, int ch, int color)
{
int i=0;
for(i=y-5;i<y+6;i++)
{
	gotoxy(x-2,i);
	printf("%c[%dm",27,color);
	printf(" ");
	fflush(stdout);	
	printf("%c[0m",27);
	gotoxy(x-1,i);
	printf("%c[%dm",27,color);
	printf(" ");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(x,i);
	printf("%c[%dm",27,color);
	printf(" ");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(x+1,i);
	printf("%c[%dm",27,color);
	printf(" ");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(x+2,i);
	printf("%c[%dm",27,color);
	printf(" ");
	fflush(stdout);
	printf("%c[0m",27);
}
	gotoxy(x,y);
	arr[x][y]=ch;
	printf("%c[31m",27);
	printf("%d",ch);
	fflush(stdout);
	printf("%c[0m",27);
}
void instructions()
{
	gotoxy(1,120);
	printf("%c[1;4mInstructions:",27);
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(2,120);
	printf("1) User will be assigned a number 2 while");
	fflush(stdout);
	gotoxy(3,123);
	printf("computer is assigned number 1.");
	fflush(stdout);
	gotoxy(4,120);
	printf("2) You will either win or loose.");
	fflush(stdout);
	gotoxy(5,120);
	printf("3) Game may tie also.");
	fflush(stdout);
}
int kbhit(void)//defining kbhit()
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}//end of kbhit()
int user()//for PLAYER 1
{
int i=0,j=0;
int color_changed=46;
int location=0;
//to clear the screen... for user and computer
for(i=10;i<=15;i++)
{
	for(j=120;j<=160;j++)
	{
	gotoxy(i,j);
	printf(" ");
	fflush(stdout);
	}
}
gotoxy(10,120);
printf("%s select a location:-",name);
fflush(stdout);
gotoxy(11,120);
scanf("%d",&location);
switch(location)
	{
	case 65	:
		{ arr[10][30]=2;design_button(10,30,2,color_changed); break;}
	case 66	:
		{ arr[10][50]=2;design_button(10,50,2,color_changed); break;}
	case 67	:
		{ arr[10][70]=2;design_button(10,70,2,color_changed); break;}
	case 68	:
		{ arr[20][30]=2;design_button(20,30,2,color_changed); break;}
	case 69	:
		{ arr[20][50]=2;design_button(20,50,2,color_changed); break;}
	case 70	:
		{ arr[20][70]=2;design_button(20,70,2,color_changed); break;}
	case 71	:
		{ arr[30][30]=2;design_button(30,30,2,color_changed); break;}
	case 72	:
		{ arr[30][50]=2;design_button(30,50,2,color_changed); break;}
	case 73	:
		{ arr[30][70]=2;design_button(30,70,2,color_changed); break;}
	default:
		{
		clrscr();
		gotoxy(16,40);
		printf("%c[31m",27);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++");
		gotoxy(17,40);
		printf("Wrong Location Selected. You Loose. Game Over!!!");
		gotoxy(18,40);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++");
		fflush(stdout);
		gotoxy(42,120);
		printf("%c[0m",27);
		exit(1);
		}
	}
return location;
}
//playing computer---------------------------------------------------------------
void comp(int loc)
{
int i=0,j=0;
int color_changed=40;
int count=1;
switch(loc)
{
	case 65:
		{
		if(arr[10][50]==66 && arr[20][50]==69 && arr[20][30]==68)				{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][50]==2 && arr[20][50]==2 && arr[20][30]==68 && arr[30][70]==73)		{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][50]==1 && arr[10][70]==2 && arr[20][50]==69)				{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][50]==66 && arr[20][30]==2 && arr[30][70]==73 && arr[30][30]==71)	{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][70]==1 && arr[30][70]==1 && arr[30][50]==2 && arr[20][30]==68)
													{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][70]==1 && arr[30][70]==1 && arr[30][50]==2 && arr[20][70]==70)
													{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[20][50]==69 && arr[20][70]==2 && arr[10][70]==1 && arr[30][70]==73)		{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][50]==2 && arr[30][70]==73 && arr[10][70]==67)
		/*ABOVE CASE CHANGED FROM 73 TO 67*/		 					{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[10][50]==2 && arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[30][30]==71 && arr[10][70]==1 && arr[20][50]==1 && arr[30][70]==73)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][70]==1 && arr[30][30]==71 && arr[30][70]==2)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][30]==1 && arr[30][50]==2 && arr[10][70]==67)		{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[30][50]==1 && arr[30][70]==73)				{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][70]==2 && arr[20][30]==2 && arr[20][50]==1 && arr[10][50]==66 && arr[30][70]==1){arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[20][70]==2 && arr[20][50]==1 && arr[10][70]==67)				{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==69)						{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[30][30]==71 && arr[30][70]==73){arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[20][30]==2 && arr[30][70]==1 && arr[30][30]==71)	{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][50]==2 && arr[10][70]==1 && arr[20][50]==2 && arr[30][50]==1 && arr[20][70]==1 && arr[30][30]==71)
													{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else {infault();}
		
	break;
		}
	case 66:
		{
		if(arr[10][70]==67 && arr[20][50]==69 && arr[20][70]==70)				{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[10][30]==1 & arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==1 && arr[20][70]==2 && arr[30][70]==73)				
													{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][70]==2 && arr[20][50]==1 && arr[20][70]==1 && arr[30][70]==2 && arr[20][30]==68 && arr[10][30]==65)
													{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][30]==71)				{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==67)				{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[10][30]==65 && arr[10][70]==67)		{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][70]==1 && arr[10][70]==2 && arr[10][30]==65)		{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][30]==1 && arr[30][70]==73)				{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[30][70]==1 && arr[30][50]==1 && arr[20][50]==2 && arr[30][30]==71)		{arr[30][71]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][70]==2 && arr[20][50]==1 && arr[30][30]==71 && arr[10][70]==67)		{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else {infault();}
	break;
		}	
	case 67:
		{
		if(arr[10][50]==66 && arr[20][50]==69 && arr[20][70]==70)				{arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[20][50]==2 && arr[30][30]==71)						{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[30][30]==1 && arr[20][50]==1 && arr[10][30]==2 && arr[10][50]==66)		{arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[30][70]==73)				{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][50]==66)				{arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[20][30]==1 && arr[20][70]==2 && arr[20][50]==1 && arr[30][70]==73)		{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][70]==2 && arr[20][70]==70)				{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else {infault();}
	break;
		}
	case 68:
		{
		if(arr[20][50]==69 && arr[10][30]==65 && arr[20][70]==70 && arr[30][30]==71)		{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][70]==1 && arr[10][50]==2 && arr[20][50]==2 && arr[30][50]==72)		{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[10][30]==2 && arr[10][50]==1 && arr[20][50]==1 && arr[20][70]==1 && arr[30][70]==73 && arr[30][30]==71 && arr[30][50]==2)
													{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][70]==1 && arr[10][50]==2 && arr[30][50]==1 && arr[20][70]==70 && arr[10][30]==65 && arr[30][70]==73)
													{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][70]==1 && arr[10][50]==2 && arr[30][50]==1 && arr[20][70]==70 && arr[10][30]==1 && arr[30][70]==73)
													{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][30]==1 && arr[30][70]==1 && arr[20][70]==70 && arr[30][30]==71)
													{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][70]==1 && arr[10][70]==1 && arr[20][70]==2 && arr[10][30]==65){arr[10][30]=1;design_button(10,30,1,color_changed);}	
		else if(arr[20][50]==1 && arr[30][70]==1 && arr[10][70]==1 && arr[20][70]==70 && arr[10][30]==1){arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][30]==2 && arr[10][70]==1 && arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==2 && arr[10][50]==66)		{arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][70]==1 && arr[10][30]==2 && arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[10][50]==1 && arr[20][50]==1 && arr[30][50]==72)		{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[10][70]==1 && arr[10][50]==2 && arr[30][70]==2 && arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][70]==2 && arr[30][30]==1 && arr[20][70]==70)		{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[30][70]==1 && arr[30][50]==1 && arr[30][30]==71)		{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][30]==71)				{arr[30][30]=1;design_button(30,30,1,color_changed);}	 
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67)		{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==67 && arr[30][30]==71 && arr[30][70]==73 && arr[10][50]==66)
													{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else {infault();}
	break;
		}
	case 69:
		{
		if(arr[30][50]==72 && arr[10][50]==2 &&  arr[10][70]==1 || arr[10][30]==1)		{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[10][30]==65 && arr[30][50]==72 && arr[20][30]==68 && arr[10][70]==67)	{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[20][30]==1 && arr[30][30]==2 && arr[10][70]==67 && arr[10][30]==65 && arr[30][50]==72){arr[10][70]==67;design_button(10,70,1,color_changed);}
		else if(arr[30][30]==2 && arr[20][30]==1 && arr[10][30]==65 && arr[10][50]==66 && arr[30][70]==73){arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][30]==68 && arr[20][70]==2 &&  arr[10][70]==1)				{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[30][30]==1 &&  arr[20][50]==2 &&  arr[20][30]==1 && arr[10][70]==67)	{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==65 && arr[30][70]==2 &&  arr[30][30]==2)				{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[10][70]=2 && arr[10][50]==1 && arr[30][30]==71)				{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else {infault();}
	break;
		}
	case 70:
		{
		if(arr[20][50]==1 && arr[30][70]==2 && arr[10][70]==67)						{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==2 && arr[20][30]==68 && arr[30][50]==1)			{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][50]==2 && arr[10][70]==1 && arr[20][50]==1 && arr[20][70]==2 && arr[30][50]==72 && arr[30][70]==73)
														{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[30][70]==73 && arr[10][70]==2 && arr[10][50]==1 && arr[20][50]==69 && arr[30][50]==72){arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][30]==65 && arr[20][50]==1 && arr[10][70]==2 && arr[30][70]==1)			{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[10][30]==1 && arr[30][70]==73 && arr[20][30]==2)			{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[20][30]==68 && arr[10][70]==67 && arr[30][30]==71){arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67)			{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][70]==1 && arr[10][50]==2 && arr[20][50]==2 && arr[30][50]==1 && arr[30][70]==1 && arr[30][30]==71)
														{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][70]==2 && arr[20][50]==2 && arr[20][70]==2 && arr[20][30]==68)			{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][70]==2 && arr[20][50]==1 && arr[10][50]==1 && arr[20][30]==2 && arr[30][50]==72){arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[20][30]==2 && arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67){arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[20][30]==68)							{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][70]==67 && arr[20][50]==69 && arr[30][70]==73)					{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==2 && arr[30][70]==73 && arr[20][30]==68 && arr[30][50]==1){arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[30][30]==71 && arr[20][50]==1 && arr[10][70]==1)					{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][50]==2 && arr[20][50]==69 && arr[10][70]==1)					{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][30]==65 && arr[20][50]==1 && arr[30][70]==1 && arr[10][70]==1)			{arr[10][30]=1;design_button(10,30,1,color_changed);}
			
		else {infault();}
	break;
		}
	case 71:
		{
		if(arr[20][30]==68 && arr[20][50]==69 && arr[30][50]==72)	{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[10][30]==65)	{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][70]==67 && arr[30][50]==1)	{arr[10][30]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==67 && arr[10][50]==66 && arr[20][30]==68 && arr[30][50]==72)
										{arr[20][30]==1;design_button(20,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==1 && arr[20][30]==68 && arr[30][50]==72 && arr[20][70]==2)
														{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][50]==72 && arr[20][30]==2)			{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==67 && arr[30][30]==71 && arr[30][70]==73)
														{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][50]==72 && arr[20][70]==2 && arr[30][70]==73){arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[30][50]==1 && arr[20][30]==68 && arr[10][70]==67 && arr[20][70]==2){arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[20][50]==2 && arr[30][50]==1 && arr[20][30]==2 && arr[10][70]==67 && arr[20][70]==70){arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[10][70]==2 && arr[10][50]==1 && arr[20][50]==1 && arr[30][50]==72){arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][50]==2 && arr[30][70]==73 && arr[10][30]==2 && arr[20][30]==68){arr[20][30]=1;design_button(20,30,1,color_changed);}
		//above case is not getting folowed
		else if(arr[10][50]==2 && arr[20][50]==2 && arr[30][50]==1 && arr[30][70]==1 && arr[10][70]==1 && arr[20][70]==70)
											{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else {infault();}
	break;
		}
	case 72:
		{
		if(arr[20][50]==1 && arr[30][70]==2 && arr[30][30]==71)						{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][50]==1 && arr[20][50]==1 && arr[20][30]==68 && arr[20][70]==70)			{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[10][30]==1 && arr[20][50]==1 && arr[20][30]==2 && arr[30][70]==73)			{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[10][30]==1 && arr[20][30]==2 && arr[10][50]==66)					{arr[10][50]=1;design_button(10,50,1,color_changed);}
		else if(arr[10][30]==1 && arr[20][30]==2 && arr[10][70]==67)					{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67)			{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][30]==71)					{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[30][30]==2 && arr[30][70]==73)							{arr[30][70]=1;design_button(30,70,1,color_changed);}
		else if(arr[30][30]==71 && arr[20][50]==69 && arr[20][30]==68 && arr[30][70]==73)		{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67 && arr[20][70]==70)			{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][50]==1 && arr[30][70]==1 && arr[10][30]==65)					{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][50]==1 && arr[20][30]==2 && arr[30][30]==71)					{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==67 && arr[30][30]==71)			{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[30][30]==2 && arr[20][30]==1 && arr[20][50]==1 && arr[30][70]==2 && arr[20][70]==70){arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[10][50]==1 && arr[20][50]==1 && arr[20][70]==70 && arr[20][30]==1 || arr[20][30]==2){arr[20][70]=1;design_button(20,70,1,color_changed);}
		else {infault();}
	break;
		}
	case 73:
		{
		if(arr[20][50]==2 && arr[30][30]==71 && arr[10][30]==65)			{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[20][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67)	{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][30]==65)					{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[10][50]==1 && arr[10][70]==2 && arr[20][50]==69 && arr[20][70]==70)	{arr[20][70]=1;design_button(20,70,1,color_changed);}
		else if(arr[20][50]==69 && arr[10][70]==1 && arr[10][30]==2)			{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[10][30]==1 && arr[20][30]==2 && arr[30][30]==2 && arr[20][50]==1 && arr[10][70]==67 && arr[30][50]==72)
												{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[30][50]==2 && arr[20][50]==1 && arr[30][30]==71 && arr[10][30]==2 && arr[20][30]==68){arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[10][70]==2 && arr[10][50]==1 && arr[20][50]==2 && arr[20][30]==68 && arr[30][30]==71 && arr[30][50]==72)
												{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[20][50]==69 && arr[20][70]==70 && arr[30][50]==72)			{arr[20][50]=1;design_button(20,50,1,color_changed);}
		else if(arr[20][50]==2 && arr[10][70]==1 && arr[20][50]==1 && arr[10][30]==65)	{arr[10][30]=1;design_button(10,30,1,color_changed);}
		else if(arr[30][50]==72 && arr[20][50]==1 && arr[10][70]==2 && arr[30][30]==1)	{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[20][50]==1 && arr[20][30]==2 && arr[10][70]==67)			{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[10][70]==1 && arr[20][50]==1 && arr[20][70]==2 && arr[30][30]==71){arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==71 && arr[30][50]==72 && arr[10][70]==67){arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[30][30]==1 && arr[10][70]==67)	{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else if(arr[10][30]==2 && arr[20][50]==1 && arr[10][70]==1 && arr[30][30]==71)	{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[20][30]==2 && arr[30][30]==71)	{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][30]==71 && arr[10][30]==65)	{arr[30][30]=1;design_button(30,30,1,color_changed);}
		else if(arr[30][30]==2 && arr[30][50]==72)					{arr[30][50]=1;design_button(30,50,1,color_changed);}
		else if(arr[30][50]==2 && arr[30][30]==71 && arr[10][30]==2 && arr[10][50]==1 && arr[20][50]==1 && arr[20][70]==1 && arr[20][30]==68)
												{arr[20][30]=1;design_button(20,30,1,color_changed);}
		else if(arr[20][50]=1 && arr[10][30]==1 && arr[20][70]==2 && arr[10][70]==67)	{arr[10][70]=1;design_button(10,70,1,color_changed);}
		else {infault();}
	break;
		}
}
}
void infault()
{
int i=0,j=0;
int color_changed=40;
if(arr[20][50]==69)
	{arr[20][50]=1; design_button(20,50,1,color_changed);}
else if(arr[10][70]==67)
	{arr[10][70]=1; design_button(10,70,1,color_changed);}
else if(arr[30][70]==73)
	{arr[30][70]=1; design_button(30,70,1,color_changed);}
else if(arr[10][30]==65)
	{arr[10][30]=1; design_button(10,30,1,color_changed);}
else if(arr[30][30]==71)
	{arr[30][30]=1; design_button(30,30,1,color_changed);}
else if(arr[20][30]==68)
	{arr[20][30]=1; design_button(20,30,1,color_changed);}
else if(arr[20][70]==70)
	{arr[20][70]=1; design_button(20,70,1,color_changed);}
else if(arr[10][50]==66)	
	{arr[10][50]=1; design_button(10,50,1,color_changed);}
else if(arr[30][50]==72)
	{arr[30][50]=1; design_button(30,50,1,color_changed);}
}
int user_count1()//for first player
{
if(arr[10][30]==2 && arr[10][50]==2 && arr[10][70]==2)			{return 32;}
else if(arr[20][30]==2 && arr[20][50]==2 && arr[20][70]==2)		{return 32;}
else if(arr[30][30]==2 && arr[30][50]==2 && arr[30][70]==2)		{return 32;}
else if(arr[10][30]==2 && arr[20][30]==2 && arr[30][30]==2)		{return 32;}
else if(arr[10][50]==2 && arr[20][50]==2 && arr[30][50]==2)		{return 32;}
else if(arr[10][70]==2 && arr[20][70]==2 && arr[30][70]==2)		{return 32;}
else if(arr[10][30]==2 && arr[20][50]==2 && arr[30][70]==2)		{return 32;}
else if(arr[10][70]==2 && arr[20][50]==2 && arr[30][30]==2)		{return 32;}
else 									{return 0;}
}
int user_count2()//can be used for computer and 2nd player
{
if(arr[10][30]==1 && arr[10][50]==1 && arr[10][70]==1)			{return 31;}
else if(arr[20][30]==1 && arr[20][50]==1 && arr[20][70]==1)		{return 31;}
else if(arr[30][30]==1 && arr[30][50]==1 && arr[30][70]==1)		{return 31;}
else if(arr[10][30]==1 && arr[20][30]==1 && arr[30][30]==1)		{return 31;}
else if(arr[10][50]==1 && arr[20][50]==1 && arr[30][50]==1)		{return 31;}
else if(arr[10][70]==1 && arr[20][70]==1 && arr[30][70]==1)		{return 31;}
else if(arr[10][30]==1 && arr[20][50]==1 && arr[30][70]==1)		{return 31;}
else if(arr[10][70]==1 && arr[20][50]==1 && arr[30][30]==1)		{return 31;}
else 									{return 0;}
}
int count_location()
{
int row,col;
int count=0;
for(row=5;row<=35;row++)
{
	for(col=20;col<=80;col++)
	{
	if(arr[row][col]==1 || arr[row][col]==2)	{count=count+1;}
	}
}
return count;
}
void tie()
{
switch(choice)
{
	case 1:
		clrscr();
		gotoxy(16,40);
		printf("%c[31m",27);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(17,40);
		printf("Game Ties. You played a good game. Thanks for playing with us.");
		gotoxy(18,40);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		fflush(stdout);
		gotoxy(42,120);
		printf("%c[0m",27);
		exit(1);
	case 2:
		clrscr();
		gotoxy(16,40);
		printf("%c[31m",27);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(17,40);
		printf("Game Ties. Both of you played a good game. Thanks for playing with us.");
		gotoxy(18,40);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		fflush(stdout);
		gotoxy(42,120);
		printf("%c[0m",27);
		exit(1);
}
}
//======================================================GAME HINTS
//Use of Mind.....
/*
40*100 total allocation..
30*80 main Matrix for Tic Tac Toe...starting at 5th row, 20th column and ends at 35th row, 80th column
*/
