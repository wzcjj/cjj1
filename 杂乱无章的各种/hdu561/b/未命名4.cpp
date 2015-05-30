#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int i,j,m,n,I,N;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n;
        int ans;
        for(i=1;i<=50;i++)if(n+1<(1<<i)){
            ans=i-1;
            break;
        }
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
