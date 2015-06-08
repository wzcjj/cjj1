#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct node{
    int color,l,r,sum;
}a[3000005];
void build(int l,int r,int p){
    int mid=(l+r)>>1;
    a[p].color=2;
    a[p].sum=4;
    a[p].l=l;
    a[p].r=r;
    if(l<r){
        build(l,mid,2*p);
        build(mid+1,r,2*p+1);
    }
}
void add(int l,int r,int color,int p){
    if(a[p].l==l&&a[p].r==r){
        a[p].color=color;
        a[p].sum=(1<<a[p].color);
        return;
    }
    int mid=(a[p].l+a[p].r)>>1;
    if(a[p].color!=0){
        add(a[p].l,mid,a[p].color,2*p);
        add(mid+1,a[p].r,a[p].color,2*p+1);
        a[p].color=0;
    }
    if(l>mid)add(l,r,color,2*p+1);
    else if(r<=mid)add(l,r,color,2*p);
    else{
        add(l,mid,color,2*p);
        add(mid+1,r,color,2*p+1);
    }
    a[p].sum=a[2*p].sum|a[2*p+1].sum;
}
int query(int l,int r,int p){
    if(a[p].l==l&&a[p].r==r){
        return a[p].sum;
    }
    int mid=(a[p].l+a[p].r)>>1;
    if(a[p].color!=0){
        add(a[p].l,mid,a[p].color,2*p);
        add(mid+1,a[p].r,a[p].color,2*p+1);
        a[p].color=0;
    }
    int ans=0;
    if(l>mid){
        ans=query(l,r,2*p+1);
    }
    else if(r<=mid){
        ans=query(l,r,2*p);
    } 
    else{
        ans=query(l,mid,2*p);
        ans=ans|query(mid+1,r,2*p+1);
    }
    a[p].sum=a[2*p].sum|a[2*p+1].sum;
    return ans;
}
int main(){
    int i,j,m,n;
    cin>>n>>m;
    while(n!=0||m!=0){
        build(1,n,1);
        for(i=1;i<=m;i++){
            char c;
            scanf("\n%c",&c);
            if(c=='P'){
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                add(x,y,z,1);
            }
            else{
                int x,y;
                scanf("%d%d",&x,&y);
                int ans=query(x,y,1);
                if(ans-((ans>>1)<<1))ans--;
                bool flag=false;
                for(j=1;ans;j++)if(ans&(1<<j)){
                    if(flag)printf(" %d",j);
                    else printf("%d",j);
                    flag=true;
                    ans-=(1<<j);
                }
                printf("\n");
            }
        }
        cin>>n>>m;
    }
    return 0;
}
                
