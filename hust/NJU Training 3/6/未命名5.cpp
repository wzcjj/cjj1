#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct range{
    int x,y,i,t;
}a[100005];
int b[1000005];
int c[1000005];
bool cmp(range x,range y){
    return x.y<y.y;
}
int main(){
    int i,j,m,n,I,N,x,y,z;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int t=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            b[x]=1;
            a[i].x=y;
            a[i].y=z;
            a[i].i=i;
            a[i].t=x;
        }
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++){
            for(;t<=a[i].y;t++)c[t]=c[t-1]+b[t];
            t--;
            if(a[i].x<=a[i].t&&a[i].y>=a[i].t){
                if(c[a[i].y]-c[a[i].x-1]<=1)b[t]++;
            }
            else{
                if(c[a[i].y]-c[a[i].x-1]<=0)b[t]++;
            }
        }
        c[t]=c[t-1]+b[t];
        printf("Case #%d: %d\n",I,c[t]-c[0]);
    }
    return 0;
}
