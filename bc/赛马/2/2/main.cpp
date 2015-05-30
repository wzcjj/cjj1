#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
vector<int> a[100005],b[100005];
bool c[300005];
int deep[100005];
int odd;
bool a1,a2;
void dfs(int x,int fa,int de)
{
    deep[x]=de;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa&&c[b[x][i]]==false){
        c[b[x][i]]=true;
        if(deep[a[x][i]]>0){
            if(odd==0){
                if((deep[a[x][i]]-deep[x])%2==0){
                    odd=1;
                    a1=true;
                }
                else{
                    odd=-1;
                    a2=true;
                }
            }
            else if(odd==1){
                a1=a2=true;
            }
            else{
                if((deep[a[x][i]]-deep[x])%2==0)a1=true;
            }
        }
        else{
            dfs(a[x][i],x,de+1);
        }
    }
}
int main()
{
    int i,j,m,n,N;
    cin>>N;
    while(N--){
        cin>>n>>m;
        memset(c,false,sizeof(c));
        memset(deep,0,sizeof(deep));
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
            b[x].push_back(i);
            b[y].push_back(i);
        }
        a1=a2=false;
        for(i=1;i<=n;i++)if(deep[i]==0){
            odd=0;
            dfs(i,-1,1);
        }
        if(a1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(a2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)b[i].clear();
    }
    return 0;
}
