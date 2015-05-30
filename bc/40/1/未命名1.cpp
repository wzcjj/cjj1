#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int i,j,m,n;
    cin>>m;
    for(j=1;j<=m;j++){
        cin>>n;
        int max =0;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                max = i+n/i;
            }
        }
        cout<<max*2<<endl;
    }
    return 0;
}
             
