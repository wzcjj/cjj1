#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int i,j,m,n;
    cin>>m>>n;
    if(n>2*m){
        cout<<m;
        return 0;
    }
    if(m>2*n){
        cout<<n;
        return 0;
    }
    cout<<(n+m)/3;
    return 0;
}
