#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int i,num;
};
vector<node>b[100005];
int a[100005],c[100005];
void fenjie(int x){
    for(int i=2;i*i<=a[x];i++)if(a[x]%i==0){
        node t;
        t.i=i;
        t.num=0;
        while(a[x]%i==0){
            t.num++;
            a[x]/=i;
        }
        b[x].push_back(t);
    }
    if(a[x]>1){
        node t;
        t.i=a[x];
        t.num=1;
        b[x].push_back(t);
    }
}
void aaa(int x,int i,int now){
    if(i==b[x].size()){
        c[now]++;
        return;
    }
    for(int j=0;j<=b[x][i].num;j++){
        aaa(x,i+1,now);
        now*=b[x][i].i;
    }
}
int main()
{
    int i,j,m,n,N,max=0;
    cin>>N;
    for(int I=1;I<=N;I++){
        memset(c,0,sizeof(c));
        for(i=1;i<=max;i++)b[i].clear();
        max=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>max)max=a[i];
        }
        for(i=1;i<=n;i++)fenjie(i);
        for(i=1;i<=n;i++)aaa(i,0,1);
        for(i=max;i>=1;i--)if(c[i]>1){
            printf("Case #%d: %d\n",I,i);
            break;
        }
    }
    return 0;
}
