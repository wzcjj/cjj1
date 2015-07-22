//
//  main.cpp
//  poj2373
//
//  Created by mac on 15-7-22.
//  Copyright (c) 2015Äê mac. All rights reserved.
//

#include <iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define infinite 1<<30
#define maxn 100
int A,B,N,L;
bool h[maxn];
int ff[maxn];
struct step
{
    int f;
    int x;
};
priority_queue<step> fx;

int main(int argc, const char * argv[]) {
    cin>>N>>L;
    cin>>A>>B;
    for (int i=1;i<=N;++i)
    {
        int a,b;
        cin>>a>>b;
        if (b-a>0)
            for (int j=a+1;j<b;++j) h[j]=true;
                
    }
    memset(ff,0,sizeof(ff));
    for (int i=A;i<=B;++i)
        if (!h[i])
        {
            ff[i]=1;
            if (i<B-A+2)
            {
                step index;
                index.x=i;
                index.f=1;
            }
        }
    for (int i=B+2;i<L;i+=2)
    {
        
    
        while (fx.size())
       {
       
           step index;
           index=fx.top();
           if (index.x<i-A) break;
           else  fx.pop();
       }
        if (fx.size())
        {
            ff[i]=index.f;
        }
        if(ff[i-A+2]!=infinite)
        {
            step tmp;
            tmp.x=i-A+2;
            tmp.f=ff[i-A+2];
            fx.push(tmp);
        }
    } 
    std::cout << "Hello, World!\n";
    return 0;
}
