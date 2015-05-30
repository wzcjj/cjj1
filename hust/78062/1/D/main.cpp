#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[100][2];
bool f[100];
#define big 0
int ans=0;
bool flag=false;
 int n;
void tr(int b,int sum,int c1)
{
    int t1,t2;
    if (b==2)
    {
        if (sum>ans) ans=sum;
        return;
    }
    for (int i=c1;i<n;i++)
        if (f[i])
        {
            f[i]=false;
            for (int j=i+1;j<n;j++)
                if (  f[j] && a[i][0]==a[j][0] )
                {
                    f[j]=false;
                    for (int k=i+1;k<n;k++)
                    if ( f[k] && a[k][1]==a[i][1])
                    {
                        f[k]=false;
                          for (int l=i+1;l<n;l++)
                            if ( f[l] && a[l][0]==a[k][0] && a[l][1]==a[j][1])
                            {
                                f[l]=false;
                                t1=sum+abs(a[j][1]-a[i][1])*abs(a[k][0]-a[i][0]);
                                tr(b+1,t1,i+1);
                                f[l]=true;
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
            scanf("%d%d",&a[i][0],&a[i][1]);
            f[i]=true;
        }
 /*       for (int i=0;i<n;i++)
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
        }*/
        ans=0;
        tr(0,0,0);
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
