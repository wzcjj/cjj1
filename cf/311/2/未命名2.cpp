#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
struct node{
    int l,d,i;
}a[100005],b[100005];
bool flag[100005];
bool cmpa(node x,node y){
    return x.l<y.l;
}
bool cmpb(node x,node y){
    return x.d<y.d;
}
int main(){
    int i,j,m,n,k,l;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i].l);
    for(i=1;i<=n;i++)scanf("%d",&a[i].d);
    memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++)a[i].i=i;
    sort(a+1,a+n+1,cmpa);
    for(i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+n+1,cmpb);
    for(i=1;i<=n;i++)a[b[i].i].i=i;
    int all=0;
    for(i=1;i<=n;i++)all+=a[i].d;
    int ans=2000000000;
    int now=0,nowi=n,aa=0;
    for(i=n;i>=1;i--){
        for(j=i;j>=2;j--)if(a[j].l!=a[j-1].l)break;
        for(k=j;k<=i;k++)if(a[k].i<=nowi){
            aa++;
        }
        else{
            now+=a[k].d;
        }
        if((j-1)-(i-j+1)+1<=0){
            while(nowi>0){
                if(b[nowi].l>=a[i].l){
                    aa--;
                    now+=a[k].d;
                }
                all-=b[nowi].d;
                nowi--;
            }
            if(ans>now)ans=now;
            break;
        }
        while(nowi>0&&nowi>aa+(j-1)-(i-j+1)+1){
            if(b[nowi].l>=a[i].l){
                aa--;
                now+=a[k].d;
            }
            all-=b[nowi].d;
            nowi--;
        }
        if(ans>now+all-(i-j+1)*a[i].d)ans=now+all-(i-j+1)*a[i].d;
        /*l=0;
        int sum=0;
        for(k=1;k<=(j-1)-(i-j+1)+1;k++){
            l++;
            while(b[l].l>=a[i].l)l++;
            sum+=b[l].d;
        }
        if(ans>sum+now)ans=sum+now;
        for(k=j;k<=i;k++)now+=a[k].d;
        i=j;*/
    }
    cout<<ans<<endl;
    return 0;
}
    
            
    
