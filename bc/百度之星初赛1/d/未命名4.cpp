#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
using namespace std;

set<int>a;
queue<int>b;
int main(){
    int i,j,m,n,N;
    int I=0;
    while(cin>>n){
        I++;
        printf("Case #%d:\n",I);
        set<int>::iterator t;
        a.clear();
        int now=0,l=0,r=0;
        while(!b.empty())b.pop();
        for(i=1;i<=n;i++){
            string s;
            cin>>s;
            if(s=="in"){
                int x;
                scanf("%d",&x);
                a.insert(x);
                b.push(x);
                if(now!=0){
                    if(x<(*t)){
                        l++;
                        now++;
                    }
                    else r++;
                }
            }
            else if(s=="out"){
                int x=b.front();
                if(now!=0){
                    if(x==(*t)){
                        if(a.size()>3)t++;
                        else now=l=r=0;
                    }
                    else if(x<(*t)){
                        l--;
                        now--;
                    }
                    else r--;
                }
                a.erase(x);
                b.pop();
            }
            else{
                if(now==0){
                    t=a.begin();
                    for(j=1;j<=a.size()/2;j++)t++;
                    now=a.size()/2+1;
                }
                else{
                    if(a.size()/2+1>now){
                        for(j=now;j<=a.size()/2;j++)t++;
                        now=a.size()/2+1;
                    }
                    else if(a.size()/2+1<now){
                        for(j=now;j>=a.size()/2+2;j--)t--;
                        now=a.size()/2+1;
                    }
                }
                printf("%d\n",(*t));
            }
        }
    }
    return 0;
}
