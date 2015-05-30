#include<cstdio>
#include<iostream>
#include<string>
#include<map> 
using namespace std;
map<string,int> a;
struct node{
    int y,m,d;
    bool operator<(node &x){
        if(y<x.y||y==x.y&&m<x.m||y==x.y&&m==x.m&&d<x.d)return true;
        else return false;
    }
};
int main(){
    int i,j,m,n;
    a["January"]=1;
    a["February"]=2;
    a["March"]=3;
    a["April"]=4;
    a["May"]=5;
    a["June"]=6;
    a["July"]=7;
    a["August"]=8;
    a["September"]=9;
    a["October"]=10;
    a["November"]=11;
    a["December"]=12;
    cin>>n;
    for(i=1;i<=n;i++){
        string s;
        node b;
        cin>>s;
        scanf("%d, %d",&b.d,&b.y);
        b.m=a[s];
        node c;
        cin>>s;
        scanf("%d, %d",&c.d,&c.y);
        c.m=a[s];
        int ans=(c.y-1)/4-b.y/4-((c.y-1)/100-b.y/100)+(c.y-1)/400-b.y/400;
        node d;
        d.y=b.y;
        d.m=2;
        d.d=29;
        if((b.y%400==0||(!(b.y%100==0)&&b.y%4==0))&&(!(d<b)))ans++;
        d.y=c.y;
        if((c.y%400==0||(!(c.y%100==0)&&c.y%4==0))&&(!(c<d)))ans++;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
    
