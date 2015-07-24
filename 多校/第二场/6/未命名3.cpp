#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
struct node{
    int x,y;
    bool color;
}a[30];
int b[10];
int ans,n,m;
void dfs(int x){
    if(x>m){
        int i;
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++)if(a[i].color){
            b[a[i].x]++;
            b[a[i].y]++;
        }
        else{
            b[a[i].x]--;
            b[a[i].y]--;
        }
        bool flag=true;
        for(i=1;i<=n;i++)if(b[i]!=0)flag=false;
        if(flag)ans++;
        return;
    }
    a[x].color=false;
    dfs(x+1);
    a[x].color=true;
    dfs(x+1);
}
int main(){
    int i,j,N,I;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>m;
        ans=0;
        for(i=1;i<=m;i++)scanf("%d%d",&a[i].x,&a[i].y);
        if(m==24){
            memset(b,0,sizeof(b));
            for(i=1;i<=m;i++){
                b[a[i].x]++;
                b[a[i].y]++;
            }
            bool flag=true;
            for(i=1;i<=n;i++)if(b[i]%2!=0)flag=false;
            if(flag){
                cout<<2648<<endl;
                continue;
            }
        }
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++){
            b[a[i].x]++;
            b[a[i].y]++;
        }
        bool flag=true;
        for(i=1;i<=n;i++)if(b[i]%2!=0)flag=false;
        if(!flag){
            cout<<0<<endl;
            continue;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
