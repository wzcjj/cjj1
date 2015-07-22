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
    int i,j,k,n=160;
    for(i=0;pow(3,i)<=n;i++){
        a[i][1].push_back(pow(3,i));
        a[i][2].push_back(pow(3,i)*2);
    }
    for(i=1;i<=n;i++){
        int t=i;
        for(j=9;j>=0;j--){
            a[j][(t/pow(3,j))].push_back(i);
            t%=(pow(3,j));
        }
    }
    int ans=0;
    for(i=0;i<=9;i++){
        for(j=1;j<=2;j++){
            for(k=1;k<a[i][j].size();k++)printf("%d ",a[i][j][k]);
            if(a[i][j].size()>ans)ans=a[i][j].size();
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<ans-1<<endl;
    system("pause");
    return 0;
}
