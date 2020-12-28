#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

using namespace std;

void delay(int delay)
{
 int now=time(NULL);
 int later=now+delay;
 while(now<=later)now=time(NULL);
}
void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void block();
int over();

int ch=0,col=0,row=0,pn,winer=0,s,t;

int arr[3][3];

int main()
{
//system("cls");
block();
for(int a=0;a<=2;a++)
 for(int b=0;b<=2;b++)
	arr[a][b]=0;
gotoxy(16,22);cout<<"             [Esc] To Quit the Game              ";
gotoxy(16,23);cout<<"Use keys:SPACE for Sign,Airrow keys for Movement.";
gotoxy(16,24);cout<<"           For Player 1 and X For Player 2      ";
back:
;
for(pn=1;pn<3;pn++)
{
 gotoxy(col*6+36,row*2+12);
 ch=getch();

 //sound(500);
 printf("\a");
 //delay(0.001);
 system("ping 127.0.0.1 -n 1 > nul");
// nosound();

 if (arr[row][col]==0 && pn==1)
     {
     if(ch==32 )
      {
      arr[row][col]=1;
      cout<<"";
      }
     }
 if (arr[row][col]==0 && pn==2)
     {
      if(ch==32 )
      {
      arr[row][col]=2;
      cout<<"X";
      }
     }

 if(ch==77 && col<=1)col=col+1;
 if(ch==75 && col>=1)col=col-1;
 if(ch==80 && row<=1)row=row+1;
 if(ch==72 && row>=1)row=row-1;
 if(ch==27)exit(0);
 if (over()==1 || over()==2)
  {
  gotoxy(30,6);cout<<"Player "<<pn<<" Has Won the Game";
  getch();
  exit(0);
  }

 }
 goto back;
}

void block()
{
gotoxy(26,11); cout<<"       ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿\n";
gotoxy(26,12); cout<<"       ³     ³     ³     ³\n";
gotoxy(26,13); cout<<"       ÃÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄ´\n";
gotoxy(26,14); cout<<"       ³     ³     ³     ³\n";
gotoxy(26,15); cout<<"       ÃÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄ´\n";
gotoxy(26,16); cout<<"       ³     ³     ³     ³\n";
gotoxy(26,17); cout<<"       ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ\n";

}
int over()
 {
 for (s=0;s<3;s++)
  for (t=0;t<3;t++)
  if(arr[s][t]==0)
 {
 if (arr[0][0]==1 && arr[0][1]==1 && arr[0][2]==1)winer=1;
 if (arr[1][0]==1 && arr[1][1]==1 && arr[1][2]==1)winer=1;
 if (arr[2][0]==1 && arr[2][1]==1 && arr[2][2]==1)winer=1;
 if (arr[0][0]==1 && arr[1][0]==1 && arr[2][0]==1)winer=1;
 if (arr[0][1]==1 && arr[1][1]==1 && arr[2][1]==1)winer=1;
 if (arr[0][2]==1 && arr[1][2]==1 && arr[2][2]==1)winer=1;
 if (arr[0][0]==1 && arr[1][1]==1 && arr[2][2]==1)winer=1;
 if (arr[0][2]==1 && arr[1][1]==1 && arr[2][0]==1)winer=1;

 if (arr[0][0]==2 && arr[0][1]==2 && arr[0][2]==2)winer=2;
 if (arr[1][0]==2 && arr[1][1]==2 && arr[1][2]==2)winer=2;
 if (arr[2][0]==2 && arr[2][1]==2 && arr[2][2]==2)winer=2;
 if (arr[0][0]==2 && arr[1][0]==2 && arr[2][0]==2)winer=2;
 if (arr[0][1]==2 && arr[1][1]==2 && arr[2][1]==2)winer=2;
 if (arr[0][2]==2 && arr[1][2]==2 && arr[2][2]==2)winer=2;
 if (arr[0][0]==2 && arr[1][1]==2 && arr[2][2]==2)winer=2;
 if (arr[0][2]==2 && arr[1][1]==2 && arr[2][0]==2)winer=2;

 return winer;
 }
 gotoxy(35,6);
 cout<<"Game Has A Draw";
 getch();
 exit(0);
 return 0;
}

