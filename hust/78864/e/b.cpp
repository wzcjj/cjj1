#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[100];
bool f[100];
#define big 0
double ans=0;
bool flag=false;
 int n;
void tr(int b,double sum,int c1)
{
    double t1,t2;
    if ((b+1)*3>n ||c1>=n)
    {
        return;
    }
    for (int i=c1;i<n;i++)
        if (f[i]) 
        {
            f[i]=false;
            for (int j=i+1;j<n;j++)
                if (  f[j])
                {
                    f[j]=false;
                    for (int k=j+1;k<n;k++)
                    if ( f[k])
                    {
                        f[k]=false;
                        if (a[k]+a[j]>a[i])
                        {
                            flag=true; 
                            t2=(a[i]+a[j]+a[k])/2.0;
                            t1=sum+sqrt(t2*(t2-a[i])*(t2-a[j])*(t2-a[k]));
                            if (t1>ans) ans=t1;
                            tr(b+1,t1,i+1);
                        }
                        f[k]=true;
                    }
                    f[j]=true;
                }
            f[i]=true;
        }
}
    
int main()
{
   
    int t;
    scanf("%d",&n);
    while (n!=0)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            f[i]=true;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (a[i]<a[j]) 
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        ans=0;
        tr(0,0,0);
        printf("%.2lf\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
