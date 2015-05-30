#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cstddef>
using namespace std;
typedef string* stringarray;
int main(){
    int i,j,m,n;
    stringarray a[4];
    int size[4]={5,6,4,3};
    for(i=0;i<4;i++)a[i]=new string[size[i]];
    for(i=0;i<4;i++)for(j=0;j<size[i];j++)a[i][j]="";
    string s;
    while(cin>>s){
        if(s=="login"){
            string st;
            int x,y;
            cin>>st>>x>>y;
            a[y-1][x-1]=st;
        }
        else if(s=="logoff"){
            int x,y;
            a[y-1][x-1]="";
        }
        else if(s=="query"){
            string st;
            cin>>st;
            for(i=0;i<4;i++)for(j=0;j<size[i];j++)if(a[i][j]==st)cout<<"Lab:"<<i+1<<" Station:"<<j+1<<endl;
        }
    }
    for(i=0;i<4;i++)delete [] a[i];
    return 0;
}
