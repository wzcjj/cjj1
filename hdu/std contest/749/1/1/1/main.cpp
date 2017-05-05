#include <cstdio>
int main() {
    int n,x,y;
    while (scanf("%d%d%d",&x,&y,&n)!=EOF) {
        if(x+n<y)printf("0.000\n");
        else if(y>=x)printf("%.3lf\n",1-1.0*(y-x+1)/(n+1));
        else printf("1.000\n");
    }
    return 0;
}
