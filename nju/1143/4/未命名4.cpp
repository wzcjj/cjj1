#include<cstdio>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=n;
        while(n>=7){
            ans+=n/7;
            n=n/7+n%7;
        }
        printf("%d\n",ans);
    }
    return 0;
}
