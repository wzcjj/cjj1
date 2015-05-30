#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long double x[4],y[4];
int main(){
    int i,j,m,n;
    int N,I;
    cin>>N;
    while(N--){
        cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
        long double d[4],a[4],c[4],ans;
        d[3]=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
        d[2]=sqrt((x[1]-x[3])*(x[1]-x[3])+(y[1]-y[3])*(y[1]-y[3]));
        d[1]=sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]));
        c[1]=abs((x[3]-x[1])*(x[2]-x[1])+(y[3]-y[1])*(y[2]-y[1]))/d[2]/d[3];
        c[2]=abs((x[3]-x[2])*(x[1]-x[2])+(y[3]-y[2])*(y[1]-y[2]))/d[1]/d[3];
        c[3]=abs((x[1]-x[3])*(x[2]-x[3])+(y[1]-y[3])*(y[2]-y[3]))/d[2]/d[1];
        a[1]=sqrt(d[2]*d[3]*(1-c[1]));
        a[2]=sqrt(d[1]*d[3]*(1-c[2]));
        a[3]=sqrt(d[2]*d[1]*(1-c[3])); 
        ans=2147483647;
        if(ans>a[1])ans=a[1];
        if(ans>a[2])ans=a[2];
        if(ans>a[3])ans=a[3];
        cout << fixed << setprecision(4) << ans << endl;
    }
    system("pause");
    return 0;
}
