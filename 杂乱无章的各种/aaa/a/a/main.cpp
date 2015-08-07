#include<stdio.h>
int main(){
    int n,i,j,e,o,s;
    scanf("%d",&n);
    e=n/2+1;
    s=0;
    o=1;
    /*for (i=1;i<=e;i++){
        o=1;
        for(j=1;j=n-i;j++)
            o=o*2;
        for(j=1;j<=n-i+1;j++)
            o=o*j;
        for(j=1;j<=e;j++){
            o=o/j;
            o=o/j;}	
        s=s+o;
    }*/
    printf("%d",s);
    return 0;
}