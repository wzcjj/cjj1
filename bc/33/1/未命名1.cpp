#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
string s[105];
int add1(char a,char b){
    int x,y;
    if(a>='0'&&a<='9')x=a-'0';
    else x=a-'a'+10;
    if(b>='0'&&b<='9')y=b-'0';
    else y=b-'a'+10;
    int t=(x+y)%m;
    if(t>=10)return (t-10+'a');
    else return (t+'0');
}
int main(){
    int i,j;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)cin>>s[i];
        string st="";
        for(i=1;i<=205;i++)st+="0";
        for(i=1;i<=n;i++){
            for(j=s[i].length()-1;j>=0;j--){
                int tt=add1(st[s[i].length()-j-1],s[i][j]);
                st[s[i].length()-j-1]=tt;
            }
        }
        i=202;
        while(i>0&&st[i]=='0')i--;
        for(j=i;j>=0;j--)printf("%c",st[j]);
        cout<<endl;
    }
    return 0;
}
