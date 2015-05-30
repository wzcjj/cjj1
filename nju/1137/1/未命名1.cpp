#include<cstdio>
#include<iostream>
using namespace std;
int a[1000005];
int n;
void down(int x){
    if(x>n/2)return;
    if(x*2==n||a[2*x]>a[2*x+1]){
        if(a[2*x]>a[x]){
            int t=a[x];
            a[x]=a[2*x];
            a[2*x]=t;
            down(2*x);
        }
    }
    else{
        if(a[2*x+1]>a[x]){
            int t=a[x];
            a[x]=a[2*x+1];
            a[2*x+1]=t;
            down(2*x+1);
        }
    }
}
int main(){
    int j,m,i;
    while(cin>>n){
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=n/2;i>=1;i--)down(i);
    m=n;
    for(i=n;i>=2;i--){
        int t=a[i];
        a[i]=a[1];
        a[1]=t;
        n--;
        down(1);
    }
    for(i=1;i<m;i++)printf("%d ",a[i]);
    printf("%d\n",a[m]);
    }
    return 0;
}
