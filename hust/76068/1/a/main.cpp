#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int M,N,K,t;
    int a[102],b[102][102];
    bool f;
    scanf("%d\n",&M);
    for (int i=0;i<M;i++)
    {
        scanf("%d %d\n",&N,&K);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int j=0;j<N;j++)
        {
            scanf("%d",&a[j]);
        }
        for (int j=0;j<N;j++)
        {
            b[a[j]%K][(a[j]-1)/K]+=1;
        }
        f=true;
        for (int j=0;j<K;j++)
        {
            if (j==0) t=N/K;
            else if (N-j>=0) t=(N-j)/K+1;
            else t=-1;
            for (int l=0;l<t;l++)
            {
                //printf("--%d %d %d\n",j,l,b[j][l]);
                if (b[j][l]<l+1) f=false;
                b[j][l+1]+=b[j][l];
            }
        }
        if (f) printf("Jerry\n");
        else printf("Tom\n");
    }
    return 0;
}
