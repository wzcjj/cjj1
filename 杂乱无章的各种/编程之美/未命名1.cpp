#include<cstdio>
#include<iostream>
#include<cmath>
#define P 19999997
using namespace std;
double a[50];
int main(){
    int i,j,m,n;
    cin>>n;
    if(n<5000){
        int a1,a2,a3;
        a1=1; a2=2;
        if(n<3){
            cout<<n<<endl;
            return 0;
        }
        for(i=3;i<=n;i++){
            a3=(a1+a2)%P;
            a1=a2;
            a2=a3;
        }
        cout<<a3<<endl;
        return 0;
    }
    n++; 
    a[0]=(sqrt(5)+1)/2;
    for(i=1;i<=40;i++)
    {
        a[i]=a[i-1]*a[i-1];
        a[i]=a[i]-int(a[i]/a[0]/P)*a[0]*P;
    }
    double ans=1;
    for(i=40;i>=0;i--)if((1<<i)<=n){
        ans*=a[i];
        ans=ans-int(ans/a[0]/P)*a[0]*P;
        n-=(1<<i);
    }
    ans/=a[0];
    cout<<int(ans+0.5)<<endl;
    return 0;
}
