
#include <cstdio>
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%d",&N);
    while (N--) {
        scanf("%d",&n);
        m=0;
        for(i=1;i<=n;i++){
            scanf("%d",&j);
            m^=j;
        }
        j=0;
        while(m){
            j^=(m&1);
            m>>=1;
        }
        if(j)printf("odd\n");
        else printf("even\n");
    }
    return 0;
}
