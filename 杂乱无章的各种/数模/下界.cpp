#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int pow(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++)ans*=x;
    return ans;
}
int main(){
    int i,j,m,n,n1;
    cin>>n;
    for(i=0;pow(3,i)<=n;i++);
    m=i;
    int ans=0;
    for(i=1;i<=m;i++){
        int sum=(1<<i);
        for(j=m-i+1;j<=m;j++)sum*=j;
        for(j=1;j<=i;j++)sum/=j;
        if(sum<=n){
            ans+=sum*i;
            n-=sum;
        }
        else{
            ans+=n*i;
            break;
        }
    }
    cout<<(ans-1)/m/2+1<<endl;
    system("pause");
    return 0;
}
