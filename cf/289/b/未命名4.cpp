#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[105];
int main(){
    int i,j,m,n;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    int min=200;
    int max=-1;
    for(i=1;i<=n;i++){
        if(a[i]>max)max=a[i];
        if(a[i]<min)min=a[i];
    }
    if(max-min>m){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=min;j++){
            cout<<1;
            if(j==a[i])cout<<endl;
            else cout<<' ';
        }
        for(j=min+1;j<=a[i];j++){
            cout<<j-min;
            if(j==a[i])cout<<endl;
            else cout<<' ';
        }
    }
    system("pause");
    return 0;
}
            
