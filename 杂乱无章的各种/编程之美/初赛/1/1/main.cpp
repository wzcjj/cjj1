#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> a[100005];
int color[100005];
int father[100005];
int ans;
void dfs(int x,int fa)
{
    father[x]=fa;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        dfs(a[x][i],x);
    }
}
int main()
{
    int i,j,m,n,I,N,x,y;
    cin>>N;
    for(I=1;I<=N;I++){
        scanf("%d",&n);
        printf("Case #%d:\n",I);
        memset(color,0,sizeof(color));
        for(i=1;i<=n-1;i++){
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin>>m;
        ans=1;
        while(m--){
            scanf("%d",&x);
            if(x==1){
                printf("%d\n",ans);
            }
            else{
                scanf("%d%d",&x,&y);
                for(i=0;i<a[x].size();i++)if(color[a[x][i]]==color[x])ans++;
                color[x]=y;
                for(i=0;i<a[x].size();i++)if(color[a[x][i]]==color[x])ans--;
            }
        }
        for(i=1;i<=n;i++)a[i].clear();
    }
    return 0;
}
