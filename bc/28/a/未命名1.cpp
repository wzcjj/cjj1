#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<alsorithm>
using namespace std;
int a[1005];
int main(){
    int T,i,j,m,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        m=0;
        for(i=1;i<=n;i++){
            while(m<2&&i+m!=a[i]){
                cout<<i+m;
                if(m)cout<<endl;
                else cout<<' ';
                m++;
            }
        }
        if(m<2){
            for(i=m;i<2;i++){
                cout<<n+i+1;
                if(i)cout<<endl;
                else cout<<' ';
            }
        }
    }
    system("pause");
    return 0;
}
