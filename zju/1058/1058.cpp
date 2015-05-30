#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int N,i,j,n,before,after;
    float a[6][6];
    float t;
    int b[20];
    cin>>N;
    for(int k=1;k<=N;k++)
    {
        for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
        cin>>a[i][j];
        cin>>n;
        while(n)
        {
            b[0]=1;
            for(i=1;i<=n;i++)cin>>b[i];
            cin>>t;
            for(i=1;i<=n;i++)t*=a[b[i-1]][b[i]];
            t*=a[b[i-1]][1];
            printf("%.2f\n",t);
            cin>>n;
        }
    }
    return 0;
}
