#include <graphics.h>
#include <stdlib.h> 
#include <dos.h>
#include <bios.h>
#include <stdio.h>


#define LEFT 0x4b00 
#define RIGHT 0x4d00 
#define DOWN 0x5000 
#define UP 0x4800 
#define ESC 0x011b 
#define ENTER 0x1c0b


/*0����,1�յ�,2ǽ��,3�Լ�,4����  �����Ǹ���ͼ*/
int a[15][20]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
               2,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,2,
               2,1,2,2,2,1,1,2,1,1,0,0,0,1,1,4,1,1,0,2,
               2,1,1,0,2,1,1,2,0,1,1,2,2,2,2,2,0,0,0,2,
               2,4,1,0,2,1,1,2,1,1,1,0,1,1,1,1,0,1,1,2,
               2,1,2,1,2,1,1,2,1,3,2,2,1,1,1,1,2,2,1,2,
               2,1,2,1,2,1,1,1,1,1,1,1,1,0,0,0,1,1,1,2,
               2,1,2,1,0,1,1,1,1,2,1,0,1,2,2,2,1,1,1,2,
               2,1,0,1,0,1,2,1,1,2,1,0,1,2,1,1,4,1,1,2,
               2,1,0,2,0,1,2,1,1,2,1,0,1,2,1,1,1,1,1,2,
               2,1,0,2,1,1,2,1,1,2,1,0,2,2,1,0,0,0,1,2,
               2,1,1,2,1,1,2,1,1,2,1,0,2,1,1,2,2,1,1,2,
               2,1,2,2,1,2,2,1,1,1,1,0,1,4,1,2,0,0,1,2,
               2,1,0,0,0,0,0,4,0,1,1,0,1,1,1,1,0,0,1,2,
               2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
     

struct play   /*��Ϸ������Ľṹ��*/ 
{ int x;
int y; 
}; 

struct play you,them[5]; 
int sum=0;/*ͳ�ƳԵĶ��Ӹ���,����50�ž���ʤ��*/
int xx[5][2];/*�жϵ��˷����õĽṹ��*/

int false=0;    /*�ж���Ӯ�Ĳ���*/


void init();
void begin();
void play();
void win();
void fun(struct play *them);
void movethem(struct play *them);
void loseyes();
void drawblackdou(int x,int y);
void lose();


/*��Ϸ�淨���������������Ϸ��������������ƶ����Լ�(���ݵ���)��ʼ��ܵ��˺�ǽ�ڣ������ܶ�Զ�*/
void play()
{
     int key,i;
     int bioskey(int cmd);
     while(1)
     {
             key=bioskey(2);
             while(!kbhit())   /*���ް���ʽ�����Լ��ƶ�*/
             {
                   setcolor(GREEN);  /*�ػ����� ��������ɫ��*/
                   for(i=0;i<5;i++)
                   circle(them[i].y*20+100,them[i].x*20+100,9);
                   sleep(1);
                   fun(them);  /*�������*/
                   
                   for(i=0;i<5;i++)
                        if(them[i].x==you.x&&them[i].y==you.y)
                        false=1;  /*����ʧ�ܵĻ�*/
                loseyes();  /*�ж��Ƿ�ʧ��*/
                   if(false)
                      break;
                   }             /*����while(!kbhit())*/
   if(false)
       break;
   key=bioskey(0);
   setcolor(0);   /*���Լ�ԭ��λ�õ���ɾ����*/
   circle(100+you.y*20,100+you.x*20,9);
   if(key==ESC)
        break;
 else if(key==UP)  /*�����ж��Ƿ�Ե����� �� ����ǽ��*/
    { 
        you.x--; 
        if(a[you.x][you.y]==2)
           you.x++; 
            else if(a[you.x][you.y]==0)
               drawblackdou(you.x,you.y);
        } 
else if(key==DOWN)
     {
             you.x++;
             if(a[you.x][you.y]==2)
                you.x--;
           else if(a[you.x][you.y]==0)
              drawblackdou(you.x,you.y);
     } 

else if(key==RIGHT) 

    {
you.y++;

if(a[you.x][you.y]==2)
you.y--; 
else if(a[you.x][you.y]==0) 
drawblackdou(you.x,you.y);
     }
else if(key==LEFT) 
     {
you.y--;
if(a[you.x][you.y]==2)

you.y++; 

else if(a[you.x][you.y]==0) 
drawblackdou(you.x,you.y);
    }

if(sum==50) 

break; 
   
setcolor(RED);    /*ִ����һ�μ��̺��ٻ����Լ���λ��*/ 
circle(100+you.y*20,100+you.x*20,9);
loseyes();          /*�Լ�����ȥ�������˵Ŀ���*/
if(false)
break;
  }
}


void fun(struct play *them)   /*�ƶ��е��ж�*/
{ 

int i; 
setcolor(0);           /*�ѵ���ԭ����λ��ɾ��*/
for(i=0;i<5;i++)
circle(them[i].y*20+100,them[i].x*20+100,9);
movethem(them);         /*���ݿ����ߵ�λ�����������˵��ƶ�����*/ 
}

void lose()      /*��Ļ���*/
{ 
cleardevice();
settextstyle(0,0,4); 
while(!kbhit()) 
 { 
setcolor(rand()%13+1);

outtextxy(180,200,"GAME OVER!"); 

delay(3); 
 }
}

void win()         /*Ӯ�Ļ���*/
{ 
cleardevice(); 

settextstyle(0,0,4);

while(!kbhit()) 
 { 
setcolor(rand()%13+1);

outtextxy(200,200,"YOU WIN!"); 

delay(3); 
  }
}

void drawblackdou(int x,int y)    /*�Զ���*/
{
setcolor(0); 
circle(100+y*20,100+x*20,3);   /*��Բx,y�뾶*/
sum++;                            /*�Ե����Ӻ�ͼ�һ*/
a[x][y]=1;                         /*�Ե�������ͳ�Ϊ��ͨƽ��*/
}


void loseyes()/*�ж��Ƿ�ʧ��*/ 
{
int i; 

for(i=0;i<5;i++) 

if(them[i].x==you.x&&them[i].y==you.y)

false=1;                             /*���ʧ�ܵĻ�*/
} 

void movethem(struct play *them) 
{
int i,loop;
randomize();                      /*��������������*/
for(i=0;i<5;i++) 
 { 

if(you.x==them[i].x&&(them[i].y+1)==you.y) /*ֻҪ�������ڵ�����ߣ����˻῿��ȥ*/

             them[i].y++; 

else if(you.x==them[i].x&&(them[i].y-1)==you.y) 

             them[i].y--; 

else if(you.y==them[i].y&&(them[i].x+1)==you.x) 

              them[i].x++; 

else if(you.y==them[i].y&&(them[i].x-1)==you.x)/*ֻҪ����������߾���������ȥ*/ 

               them[i].x--;

else
{ 
loop: 


   
xx[i][0]=rand()%4+1;     /*����ķ����ȡ�����ֵ,ԭ�����µķ��򲻿��Ժ�ԭ���ķ����෴*/ 

       if(xx[i][0]==1&&xx[i][1]==2||xx[i][0]==2&&xx[i][1]==1) 

goto loop;

       if(xx[i][0]==3&&xx[i][1]==4||xx[i][0]==4&&xx[i][1]==3) 

goto loop; 

xx[i][1]=xx[i][0];

      if(xx[i][0]==1)/*�ĸ�����*/ 
       {
         them[i].x--;

        if(a[them[i].x][them[i].y]==2)/*�����ǽ�ڵĻ��ͻص�ԭ���ĵط��ȴ�����ķ���*/ 

            {them[i].x++;
              goto loop;
            } 
       } 

else if(xx[i][0]==2) 
       {
           them[i].x++;
           if(a[them[i].x][them[i].y]==2) 
           {them[i].x--;
           goto loop;
            } 
        } 

else if(xx[i][0]==3) 
       {
them[i].y++; 

if(a[them[i].x][them[i].y]==2) 

            {them[i].y--;
            goto loop;
            } 
       } 

else if(xx[i][0]==4) 
       {
           them[i].y--; 
           if(a[them[i].x][them[i].y]==2) 
           {
              them[i].y++;
              goto loop;
        } 
      }
    }
 } 
} 

void begin()
{
     int i,j;
     sleep(1);
     for(i=0;i<15;i++)
        for(j=0;j<20;j++)
               if(a[i][j]==2)  /*2����ǽ��*/
               {
                    setfillstyle(SOLID_FILL,9);
                    bar(100+j*20-10,100+i*20+10,100+j*20+10,100+i*20-10);
               }
               else if(a[i][j]==3)   /*3�����Լ� ���ݵ���*/
               {
                    setcolor(RED);
                    circle(100+j*20,100+i*20,9);
               }
               else if(a[i][j]==4)    /*4������� ��ɫ*/
               {
                    setcolor(GREEN);
                    circle(100+j*20,100+i*20,9);
                }
                else if(a[i][j]==0)    /*0������ ��ɫ*/
                {
                     setcolor(YELLOW);
                     setlinestyle(0,0,1);
                     circle(100+j*20,100+i*20,3);
                 }
           you.x=5;you.y=9;      /*�Լ��͵��˵ĳ�ʼ����*/

           them[0].x=2;them[0].y=15; 

            them[1].x=4;them[1].y=1; 

            them[2].x=8;them[2].y=16; 

            them[3].x=12;them[3].y=13; 

             them[4].x=13;them[4].y=7; 

}

void init()     /*�Ƿ�ʼ��Ϸ*/
{
     setcolor(3);
     setlinestyle(DASHED_LINE,0,3);  /*��Ŀ��������ߵĿ�Ⱥ���ʽ*/
     rectangle(100,100,550,350);     /*������*/
     settextstyle(3,0,3);
     outtextxy(200,200,"GAME START!");
     settextstyle(3,0,3);
     outtextxy(110,300,"ESC-exit/press any key to continue");
     getch();
 }

int main(void)
{
      int gd=DETECT,gm;
      int  key;
      initgraph(&gd,&gm,"");   /*ͼ�ν����ʼ��*/
      init();             /*���ó�ʼ��������ʾ������Ϸ��ʼ����*/
      key=bioskey(0);  /*���ռ��̰���*/
      if(key=ESC)
      exit(0);
      else
      {
          cleardevice();
          begin();
          play();
          if(sum==50)   /*����50���������ʤ*/
       {
           win();
           getch();          
        }   
        if(false)  
       {
          lose();
          getch();
         }   
       }
       closegraph();
}





