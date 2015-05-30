#include<cstdio>
int main()
{
    int i;
    float a[105],t,x;
    while(scanf("%f",&x)!=EOF)
    {
        a[1]=1+x;
        t=x;
        for(i=2;i<=100;i++)
        {
            t=t*x/i;
            a[i]=a[i-1]+t;
        }
        printf("%.3f\n",a[100]);
        for(i=1;i<=100;i++)if(i%10)printf("%.3f ",a[i]);
        else printf("%.3f\n",a[i]);
    }
    return 0;
}
