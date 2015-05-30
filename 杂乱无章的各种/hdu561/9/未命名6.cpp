#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int> b[50005];
int a[50005];
int dfs(int x,int fa){
    int t=0;
    if(b[x].size()==0)return 1;
    if(b[x].size()==1&&x!=1)return a[x];
    for(int i=0;i<b[x].size();i++)if(b[x][i]!=fa)t+=dfs(b[x][i],x);
    return (t+a[x])%2;
}
int main(){
    int i,j,m,n,x,y;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++){
        scanf("%d%d",&x,&y);
        b[x].push_back(y);
        b[y].push_back(x);
    }
    int ans=dfs(1,-1);
    if(ans==0)cout<<"Great Cdfpysw!"<<endl;
    else cout<<"Poor Nanaya!"<<endl;
    system("pause");
    return 0;
}
