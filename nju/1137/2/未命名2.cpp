#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[100005];
bool b[100005];
int main(){
    int j,m,i,n;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(b,false,sizeof(b));
        int num1,num2;
        num1=num2=0;
        for(i=1;i<=n;i++){
            j=a[i]%m;
            if(b[j])num1++;
            else b[j]=true;
        }
        memset(b,false,sizeof(b));
        for(i=1;i<=n;i++){
            j=(int)(((0.6180339887*a[i])-(int)(0.6180339887*a[i]))*m);
            if(b[j])num2++;
            else b[j]=true;
        }
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
    return 0;
}
            
