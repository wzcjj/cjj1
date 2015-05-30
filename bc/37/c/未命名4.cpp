#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#define P 1000000007
using namespace std;
struct node{
    int i,v;
};
node a[10005];
bool cmp(node x,node y){
    return x.v<y.v;
}
int main(){
    int i,j,m,n,sorted;
    cin>>n;
    int lo=0;
    for(int aa=1;aa<=n;aa++){
        scanf("%d",&m);
        if(m==1){
            scanf("%lld",&j);
            node t;
            t.i=lo;
            t.v=j;
            a[lo]=t;
            lo++;
            sorted=0;
        }
        else{
            long long l,r,k;
            scanf("%lld%lld%lld",&l,&r,&k);
            if(sorted==0){sort(a,a+lo,cmp);sorted=1;}
            for(i=0;i<lo;i++){
                long long num=(r+(1LL<<(lo-a[i].i-1)))/(1LL<<(lo-a[i].i))-(l-1+(1LL<<(lo-a[i].i-1)))/(1LL<<(lo-a[i].i));
                k-=num;
                if(k<=0){
                    cout<<a[i].v<<endl;
                    break;
                }
            } 
        }
    }
    system("pause");
    return 0;
}
