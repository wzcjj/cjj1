#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    string a[1005][2];
    string s1,s2;
    int i,j,m,n;
    cin>>n;
    m=0;
    for(i=1;i<=n;i++){
        cin>>s1>>s2;
        int z=0;
        for(j=1;j<=m;j++)if(a[j][1]==s1){
            a[j][1]=s2;
            z=1;
            break;
        }
        if(z==0){
            m++;
            a[m][0]=s1;
            a[m][1]=s2;
        }
    }
    cout<<m<<endl;
    for(i=1;i<=m;i++)cout<<a[i][0]<<' '<<a[i][1]<<endl;
    system("pause");
    return 0;
} 
