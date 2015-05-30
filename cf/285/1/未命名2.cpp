#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int max(int x,int y){
    return x>y?x:y;
}
int main(){
    int i,j,m,n;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    m=max(3*a/10,a-a*c/250);
    n=max(3*b/10,b-b*d/250);
    if(m>n)cout<<"Misha";
    else if(m<n)cout<<"Vasya";
    else cout<<"Tie" ;
    system("pause");
    return 0;
}
