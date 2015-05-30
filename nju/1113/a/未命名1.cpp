#include<cstdio>
#include<cmath>
int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    printf("%.2lf",(70*pow(a/2.2,0.756)+0.0385*a*b*c)/(d*0.9));
    scanf("%lf",&a);
    return 0;
}
