#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define maxn 10
using namespace std;
vector<int> a[maxn][3];
int pow(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++)ans*=x;
    return ans;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i,j,k,n,m,t;
    cin>>n;
    for(i=0;pow(3,i)<=n;i++);
    m=i;
    for(i=0;i<m;i++){
        for(j=1;j<=2;j++){
            int x;
            cin>>x;
            a[i][j].push_back(x);
        }
    } 
    for(i=1;i<=n;i++){
        t=i;
        for(j=m-1;j>=0;j--){
            for(k=2;k>=1;k--)if(t-a[j][k][0]>=0){
                a[j][k].push_back(i);
                t-=a[j][k][0];
            }
        }
    }
    int ans=0;
    for(i=0;i<m;i++){
        for(j=1;j<=2;j++){
            for(k=1;k<a[i][j].size();k++)printf("%d ",a[i][j][k]);
            if(a[i][j].size()>ans&&a[i][1][0]!=a[i][2][0])ans=a[i][j].size();
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<ans-1<<endl;
    system("pause");
    return 0;
}
