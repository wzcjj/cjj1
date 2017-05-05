#include<stdio.h>
int main()
{
    int n,i,m,mid=0,j;
    scanf("%d",&n);
    int a[10000];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("search m:");
    scanf("%d",&m);
    /*i=0;
    j=n;
    while(!(j-i<=1))
    {
        mid=(i+j)>>1;
        if(m==a[mid]) break;
        if(m>a[mid])
            i=mid;
        else j=mid;
        
    }*/
    int l=0,r=n;
    while(l<r-1){
        int mid=(l+r)>>1;
        if(m<a[mid])r=mid;
        else l=mid;
    }
    printf("%d",l);
    return 0;
}
