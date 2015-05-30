#include<cstdio>
int main()
{
    int a[2],i,n;
    while(scanf("%d%d",&a[0],&n)!=EOF)
    {
        a[1]=a[0];
        n=n/5;
        for(i=2;i<=n;i++)a[i%2]=a[0]+a[1];
        printf("%d\n",a[n%2]);
    }
    return 0;
}
