#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
vector<int> a[100005];
int deep[100005],maxx[100005][2];
int dfs(int x,int fa,int de){
    deep[x]=de;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        dfs(a[x][i],x,de+1);
    }
    int max1=deep[x],max2=deep[x];
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        if(maxx[a[x][i]][0]>max1){
            max2=max1;
            max1=maxx[a[x][i]][0];
        }
        else if(maxx[a[x][i]][0]>max2){
            max2=maxx[a[x][i]][0];
        }
    }
    maxx[x][0]=max1;
    maxx[x][1]=max2;
}
int main(){
    int i,n,ans=0;
    cin>>n;
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1,0);
    for(i=1;i<=n;i++)if(ans<maxx[i][0]+maxx[i][1]-2*deep[i])ans=maxx[i][0]+maxx[i][1]-2*deep[i];
    cout<<ans<<endl;
    return 0;
}
