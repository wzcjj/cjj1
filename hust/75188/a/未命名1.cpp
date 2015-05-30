#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
vector<int> a[200005];
int now;
int b[200005],c[200005],d[200005],e[200005];//b zuidashendu,c zuiyou,d deep,e dierda
void dfs(int x,int fa){
    if(a[x].size()==1&&x!=1){
        b[x]=d[x];
        c[x]=0;
        return;
    }
    b[x]=0;
    c[x]=0;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        d[a[x][i]]=d[x]+1;
        dfs(a[x][i],x);
        if(b[x]<b[a[x][i]]){
            e[x]=b[x];
            b[x]=b[a[x][i]];
        }
        else if(e[x]<b[a[x][i]])e[x]=b[a[x][i]];
        if(c[x]<c[a[x][i]])c[x]=c[a[x][i]];
    }
    if(b[x]+e[x]-2*d[x]>c[x])c[x]=b[x]+e[x]-2*d[x];
}
void bbb(int x,int de,int fa){
    if(de==0){
        printf(" %d",x);
        return;
    }
    for(int i=0;i<a[x].size();i++)if(b[a[x][i]]==b[x]&&a[x][i]!=fa){
        bbb(a[x][i],de-1,x);
        return;
    }
}
void aaa(int x,int fa){
    int z=0,i,y=-2;
    for(i=0;i<a[x].size();i++)if(a[x][i]!=fa&&b[x]==b[a[x][i]]){
        if(b[x]-d[x]>c[1]/4*3){
            z=2;
            bbb(a[x][i],b[x]-d[x]-c[1]/4,x);
            bbb(a[x][i],b[x]-d[x]-c[1]/4*3,x);
            return;
        }
        else if(b[x]-d[x]==c[1]/4*3){
            z=3;
            printf(" %d",x);
            bbb(a[x][i],b[x]-d[x]-c[1]/4,x);
            return;
        }
        else{
            z=1;
            y=i;
            bbb(a[x][i],b[x]-d[x]-c[1]/4,x);
            break;
        }
    }
    if(z==1){
        for(i=0;i<a[x].size();i++)if(e[x]==b[a[x][i]]&& a[x][i]!=fa&&i!=y){
            bbb(a[x][i],b[x]-d[x]-c[1]/4,x);
            return;
        }
    }
}
int main(){
    int i,j,m,n,N;
    cin>>N;
    while(N--){
        cin>>n;
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        d[1]=1;
        dfs(1,-1);
        if(c[1]%4==0)cout<<c[1]/4;
        else cout<<c[1]/4+1;
        aaa(1,-1);
        cout<<endl;
    }
    return 0;
}
