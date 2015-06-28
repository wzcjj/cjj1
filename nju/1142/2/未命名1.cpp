#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int i,j,m,n,x;
    while(cin>>n>>m){
        for(i=1;i<=m;i++){
            scanf("%d",&x);
            if(i<m)printf("%d ",x);
            else printf("%d\n",x);
        }
        while(n<m)n=(n<<1);
        cout<<m<<' '<<n<<endl;
    }
    return 0;
}
