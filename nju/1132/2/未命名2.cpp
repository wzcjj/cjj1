#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000];
int main(){
    int i,n;
    while(cin>>n){
        for(i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        for(i=0;i<n-1;i++)cout<<a[i]<<' ';
        cout<<a[n-1]<<endl;
    }
    return 0;
}
