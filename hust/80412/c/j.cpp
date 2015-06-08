#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define N 30
int n,m,t;
int m[N][N];
int b[N][N];
int gcd(int a,int b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}
int select(int x,int y)
{
    int x1,y1,x2,y2,t1;bool f;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            b[i][j]=0;
    b[x][y]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            f=false;
            if (b[i][j]==0)
            {
                x1=abs(i-x);
                y1=abs(j-y);
                t1=gcd(x1,y1);
                x1/=t1;
                y1/=t1;
                for (int k=0;k<25;k++)
                {
                    x2=x1*k+x;
                    y2=y1*k+y;
                    if (a[x2][y2]==0) f=false;
                    b[x2][y2]=1;
                }
                
            }
            
                
int main()
{
    
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        n++;m++;
        for (int j=0;j<n;i++)
            for (int k=0;k<m;k++)
                scanf("%d",&m[j][k]);
        
