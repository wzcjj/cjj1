#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector> 
using namespace std;
vector<int> a[10];
int b[1500];
int po(int x,int y){
    int i;
    int ans=1;
    for(i=1;i<=y;i++)ans*=x;
    return ans;
}
void calc(int x,int y,int now){
    if(x==1){
        b[++b[0]]=now*10+y;
        return;
    }
    for(int i=0;i<a[y].size();i++)calc(x-1,a[y][i],now*10+y);
}
int main(){
    int i,j,m,n,l,r,k,left,right,mid;
    for(i=1;i<=9;i++)for(j=1;j<=i;j++)if(i%j==0)a[i].push_back(j);
    b[0]=0;
    for(i=1;i<=9;i++)for(j=1;j<=9;j++)calc(i,j,0); 
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d%d",&left,&right);
        l=0;
        r=b[0];
        while(r>l+1){
            mid=(l+r)/2;    
            if(b[mid]>=left)r=mid;
            else l=mid;
        }
        int le=r;
        l=1;
        r=b[0]+1;
        while(r>l+1){
            mid=(l+r)/2;
            if(b[mid]<=right)l=mid;
            else r=mid;
        }
        int ri=l;
        printf("%d\n",ri-le+1);
    }
    system("pause");
    return 0;
}
