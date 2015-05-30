#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#define P 1000011
using namespace std;
int a[1000005];
struct node{
    int t,num;
};
vector<node> b[P];
int c[P];
int main(){
    int i,j,m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        c[i]=t;
        int s=t%P;
        int z=0;
        int k=b[s].size();
        for(j=0;j<k;j++)if(b[s][j].t==t){
            b[s][j].num=0;
            z=1;
            break;
        }
        if(z==0){
            node o;
            o.t=t;
            o.num=0;
            b[s].push_back(o);
        }
    }
    for(i=1;i<=n;i++){
        int s=a[i]%P;
        int k=b[s].size();
        for(j=0;j<k;j++)if(b[s][j].t==a[i]){
            b[s][j].num++;
            break;
        }
    }
    for(i=1;i<=m;i++){
        int s=c[i]%P;
        int k=b[s].size();
        for(j=0;j<k;j++)if(b[s][j].t==c[i]){
            printf("%d\n",b[s][j].num);
            b[s][j].num=0;
            break;
        }
    }
    }
    return 0;
}
