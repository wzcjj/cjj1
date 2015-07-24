#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
string s1,s2;
bool ch(int x1,int y1,int x2,int y2){
    for(int i=0;i<=y1-x1;i++)if(s1[x1+i]!=s2[x2+i])return false;
    return true;
}
bool check(int x1,int y1,int x2,int y2){
    if(ch(x1,y1,x2,y2))return true;
    if((y1-x1+1)%2==1)return false;
    return check(x1,(x1+y1)>>1,x2,(x2+y2)>>1)&&check(((x1+y1)>>1)+1,y1,((x2+y2)>>1)+1,y2)||check(x1,(x1+y1)>>1,((x2+y2)>>1)+1,y2)&&check(((x1+y1)>>1)+1,y1,x2,(x2+y2)>>1);
}
int main(){
    int i,j,m,n;
    cin>>s1>>s2;
    bool ans=check(0,s1.length()-1,0,s2.length()-1);
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
