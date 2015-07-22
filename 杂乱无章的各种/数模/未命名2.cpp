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
    t=n+1;
    for(i=m-1;i>=0;i--){
        t=(t-1)/3+1;
        a[i][1].push_back(t);
        a[i][2].push_back(t*2);
        if(i!=m-1&&a[i][2][0]==a[i+1][1][0])a[i][2][0]==t;
//    for(i=0;i<m;i++){
//        for(j=1;j<=2;j++){
//            int x;
//            cin>>x;
//            a[i][j].push_back(x);
//        }
    } 
    for(i=1;i<=n;i++){
        t=i;
        for(j=m-1;j>=0;j--){
            a[j][t/a[j][1][0]].push_back(i);
            t%=a[j][1][0];
        }
    }
    int ans=0;
    for(i=0;i<m;i++){
        for(j=1;j<=2;j++){
            for(k=1;k<a[i][j].size();k++)printf("%d ",a[i][j][k]);
            if(a[i][j].size()>ans)ans=a[i][j].size();
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<ans-1<<endl;
    system("pause");
    return 0;
}
