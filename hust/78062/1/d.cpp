#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int T;
    double x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4,xn1,xn2,yn1,yn2,zn1,zn2,b1,b2,a1,a2,t,k,lx,ly,lz,xr1,yr1,zr1,xr2,yr2,zr2,l;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        xn1=x1-x2;
        yn1=y1-y2;
        zn1=z1-z2;
        xn2=x3-x4;
        yn2=y3-y4;
        zn3=z3-z4;
        lx=yn1*zn2-zn1*yn2;
        ly=zn1*xn2-xn1*zn2;
        lz=xn1*yn2-xn2*yn1;
        a1=ly*xn2-lx*yn2;
        a2=lz*xn2-lx*zn2;
        b1=ly*xn1-lx*yn1;
        b2=lz*xn1-lx*zn1;
        k=-((ly*(x1-x3)-lx*(y1-y3))/a1-((lz*(x1-x3)-lx*(z1-z3))/a2))/(b1/a1-b2/a2); 
        t=-((ly*(x1-x3)-lx*(y1-y3))/b1-((lz*(x1-x3)-lx*(z1-z3))/b2))/(a2/b2-a1/b1);
        xr1=(x1+k*xn1);
        yr1=(y1+k*yn1);
        xr2=(x3+k*xn2);
        yr2=(y3+k*yn2);
        zr2=(z3+k*zn2);
        l=abs((x1-x3)*lx+(y1-y3)*ly+(z1-z3)*lz))/sqrt(lx*lx+ly*ly+lz*lz);
        printf("%.6llf\n%.6llf %.6llf %.6llf %.6llf %.6llf %.6llf\n",l,xr1,yr1,zr1,xr2,yr2,zr2);
    }
    return 0;
} 
