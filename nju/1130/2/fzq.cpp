#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int l,i;
string s;
void print(char c)
{
  if (c=='0') printf("11000");
  if (c=='1') printf("00011"); 
  if (c=='2') printf("00101"); 
  if (c=='3') printf("00110");
  if (c=='4') printf("01001");
  if (c=='5') printf("01010");
  if (c=='6') printf("01100");
  if (c=='7') printf("10001");
  if (c=='8') printf("10010");
  if (c=='9') printf("10100");   
}
int calc(int a)
{
 if (a==0) return 7;
 if (a==1) return 4;
 if (a==2) return 2;
 if (a==3) return 1;
 return 0;     
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
  l=0;
  while (getline(cin,s))
  {
    bool check=0;
    int num=0;
    for (i=0;i<s.length();i++)
      if (s[i]<'0'||s[i]>'9') 
      {
        if (num!=0&&num!=5) 
        {
          check=1; break;                    
        }                
        num=0;                           
      }
      else num++;
    if (num!=0&&num!=5) check=1;
    for (i=0;i<s.length();i++)
      while (s[i]==' ') s.erase(i,1);
    l=s.length();
    for (i=0;i<l;i++)
      if (s[i]<'0'||s[i]>'9') 
      {
        check=1; break;                        
      }
    if (l!=5&&l!=25) check=1;
    if (check)
    {
      printf("error\n");
      continue;          
    }
    if (l==5)
    {
      for (i=0;i<l;i++)
      {
        if (i>0) printf(" ");
        print(s[i]);    
      }         
      printf("\n");
    }
    else
    {
      for (i=0;i<l;i++)
        if (s[i]!='0'&&s[i]!='1') 
        {
          check=1;
          break;
        }
      if (check)
      {
        printf("error\n");
        continue;
      }
      int t=0,ans=0,d=0,num=0;
      for (i=0;i<l;i++)
      {
        if (s[i]=='1')
        {
          
          t+=calc(i%5); 
          num++; 
          if (num>2) 
          {
            check=1; break;
          }
        }
        if (i%5==4)
        {
          if (num<2) 
          {
            check=1; break;           
          }
          if (t==11) t=0;
          ans=ans*10+t;
          if (ans==0) d++;
          t=num=0;
        }
      } 
      if (check) 
      {
        printf("error\n"); continue;           
      }  
      if (d==5) d--;
      for (i=0;i<d;i++)
        printf("0");
      printf("%d\n",ans);
    }
  }    
  //system("pause");
  return 0;
}
