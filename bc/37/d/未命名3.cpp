#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define P 1000000007
using namespace std;
long long dfs(long long n,long long m){
    long long ans=0;
    for(int i=m-1;i<=n-1;i++)ans=(ans+c(n-1,i)*dfs(n-1-i,m))%P;
    return ans;
}
int main(){
    long long i,j,m,n;
    while(cin>>n>>m){
        long long ans=dfs(n,m);
