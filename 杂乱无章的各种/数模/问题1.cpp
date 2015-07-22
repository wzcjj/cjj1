#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define maxn 10
using namespace std;
vector<int> a[maxn];
int main(){
    int i,j,k,n=60,m;
    for(i=0;(1<<i)<=n;i++);
    m=i;
    for(i=0;i<m;i++){
        a[i].push_back((1<<i));
    }
    for(i=1;i<=n;i++){
        int t=i;
        for(j=m;j>=0;j--){
            if(i&(1<<j))a[j].push_back(i);
            t-=((1<<i));
        }
    }
    int ans=0;
    for(i=0;i<=m;i++){
        for(k=1;k<a[i].size();k++)printf("%d ",a[i][k]);
        if(a[i].size()>ans)ans=a[i].size();
        cout<<endl;
    }
    cout<<ans-1<<endl;
    system("pause");
    return 0;
}
