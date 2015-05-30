#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
struct node{
    unsigned l,r;
}a[10000005];

int main()
{
    int i,n,N,b,c,d,e;
    cin>>N;
    while(N--){
        cin>>n;
        scanf("%d%d%d%d%d%d",&a[1].l,&a[1].r,&b,&c,&d,&e);
        for(i=2;i<=n;i++){
            a[i].l=a[i-1].l*b+c;
            a[i].r=a[i-1].r*d+e;
        }
        for(i=1;i<=n;i++){
            if(a[i].l>a[i].r){
                unsigned t=a[i].l;
                a[i].l=a[i].r;
                a[i].r=t;
            }
        }
        unsigned maxl=0,minr=4294967295u;
        for(i=1;i<=n;i++){
            if(maxl<a[i].l)maxl=a[i].l;
            if(minr>a[i].r)minr=a[i].r;
        }
        int z=0;
        for(i=1;i<=n;i++){
            if(maxl>a[i].r&&minr<a[i].l){
                z=1;
                break;
            }
        }
        if(z==1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
