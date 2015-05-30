#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20005];
int f(int x){
    if(a[x]!=0) return f(a[x]);
    else return x;
}
int main(){
    int i,j,m,n,I,N;
    scanf("%d",&N);
    for(I=1;I<=N;I++){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        printf("Case #%d:\n",I);
        for(i=1;i<=m;i++){
            char s;
            cin>>s;
            if(s=='C'){
                int t;
                scanf("%d",&t);
                a[t]=0;
            }
            else{
                int x,y;
                scanf("%d%d",&x,&y);
                if(f(x)==f(y))printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    system("pause");
    return 0;
}
                
