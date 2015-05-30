#include<cstdio>
int main()
{
    float a,t=0;
    while(scanf("%f",&a)!=EOF)
    {
        if(t<=2.500001)printf("%.2f Please put dollar($3.50):\n",t);
        else if(t>2.49999&&t<3.25001)printf("%.2f Please put quarter($3.50):\n",t);
        else if(t>3.24999&&t<3.40001)printf("%.2f Please put dime($3.50):\n",t);
        else printf("%.2f Please put nickel($3.50):\n",t);
        t+=a;
    }
    printf("Enjoy your deep-fried twinkle, change:%.2f\n",t-3.5);
    return 0;
}
