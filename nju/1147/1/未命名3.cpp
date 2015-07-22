#include<cstdio>
int main(){
    freopen("a.in","w",stdout);
    for(int i=1;i<=10010;i++)printf("%d %d\n",i%10000+1,i%10000+1);
    printf("0 0\n");
    return 0;
}
