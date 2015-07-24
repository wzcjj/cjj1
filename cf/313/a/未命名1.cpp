#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
int a[10];
long long calc(){
    long long sum=0;
    bool flag=false,flag1=false;
    for(int i=1;i<=6;i++)if(a[i]!=0){
        flag=true;
        sum+=2*a[i]-1;
        a[i]--;
    }
    else flag1=true;
    if(flag1&&flag)return 1;
    else if(flag)sum+=calc();
    return sum;
}
int main(){
    int i,j,m,n;
    for(i=1;i<=6;i++)scanf("%d",&a[i]);
    long long ans=calc();
    cout<<ans<<endl;
    return 0;
} 
