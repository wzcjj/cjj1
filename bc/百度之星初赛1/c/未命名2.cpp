#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[10005];
int main(){
    int i,j,n,N,k;
    long long m;
    cin>>N;
    for(int I=1;I<=N;I++){
        printf("Case #%d:\n",I);
        cin>>n>>m>>k;
        for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
        sort(a+1,a+1+n);
        int cnt=0;
        int now=0;
        bool flag=false;
        for(i=1;i<=n;i++){
            while(a[i]>m){
            if(i==now+1){
                printf("madan!\n");
                flag=true;
                break;
            }
            m=max(a[i-1]+k-cnt,m);
            cnt++;
            now=i-1;
            }
            if(flag)break;
        }
        if(!flag)printf("why am I so diao?\n");
    }
    return 0;
}
