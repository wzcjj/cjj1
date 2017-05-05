#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn=105;
int a[maxn];
int n,m,t;

int gcd(int a,int b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d%d",&n,&m);
        int t1,t2;
        for (int i=0;i<=n;i++)
            a[i]=-1;
        for (int j=0;j<m;j++)
        {
            scanf("%d%d",&t1,&t2);
            a[n-t1+1]=t2;
        }
        int min=0;
        for (int j=1;j<=n-2;j++)
        {
            if (a[j]==-1) a[j]=min;
            else if (a[j]>min) min=a[j];
        }
        if (a[n-1]==-1) {
            if(a[n]==-1) a[n-1]=100;
            else a[n-1]=a[n];
        }
        if (a[n]==-1) a[n]=100;
        int sum=0;
        for (int j=1;j<=n;j++)
            sum+=a[j];
        int p=a[n]+a[n-1];
        //printf("ok");
        int c=gcd(p,sum);
        //cout << p<< " "<<sum<<endl;
        printf("%d/%d\n",p/c,sum/c);
    }
    return 0;
}