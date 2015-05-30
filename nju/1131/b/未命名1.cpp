#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
struct node{
    char color;
    int num;
}a[3];
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
void swap(node &x,node &y){
    node t=x;
    x=y;
    y=t;
}
int main(){
    int i,j;
    string s;
    int x,y,z;
    int ans=0;
    int now=0;
    cin>>x>>y>>z;
    cin>>s;
    if(x<y)swap(x,y);
    if(y<z)swap(y,z);
    if(x<y)swap(x,y);
    a[0].color='R';
    a[0].num=0;
    a[1].color='Y';
    a[1].num=0;
    a[2].color='B';
    a[2].num=0;
    for(i=0;i<s.size();i++){
        for(j=0;j<3;j++)if(a[j].color==s[i])a[j].num++;
        if(a[1].num<a[2].num)swap(a[1],a[2]);
        if(a[0].num<a[1].num)swap(a[0],a[1]);
        if(i-now+1>ans)ans=i-now+1;
        if(a[0].num-a[1].num==y&&a[1].num-a[2].num==z&&a[0].num-a[2].num==x||a[0].num-a[1].num==z&&a[1].num-a[2].num==y&&a[0].num-a[2].num==x){
            now=i+1;
            a[0].num=0;
            a[1].num=0;
            a[2].num=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
