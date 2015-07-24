#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
struct node{
    int x,num;
}a[100005];
bool cmp(node x,node y){
    return x.x>y.x;
}
int main(){
    int i,j,m,n,N,I,o;
    cin>>N;
    for(I=1;I<=N;I++){
        long long ans=0;
        scanf("%d%d%d",&n,&m,&o);
        for(i=1;i<=m;i++){
            scanf("%d%d",&a[i].x,&a[i].num);
            if(a[i].x>n-a[i].x)a[i].x=n-a[i].x;
        }
        sort(a+1,a+1+m,cmp);
        for(i=1;i<=m;i++){
            ans+=a[i].num/o*a[i].x*2;
            a[i].num%=o;
            if(a[i].num){
                if(i!=m)a[i+1].num-=o-a[i].num;
                ans+=a[i].x*2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
