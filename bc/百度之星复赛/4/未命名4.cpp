#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[100005],l[100005],r[100005];
int main(){
    int i,j,m,n,N,k,l;
    cin>>N;
    int I=0;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        cin>>n>>m;
        int max1=0,maxi=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(max1<a[i]){
                max1=a[i];
                maxi=i;
            }
        }
        j=2;
        for(i=1;i<=n;i++){
            while(a[j+1]>a[j]+incr(i,j))
