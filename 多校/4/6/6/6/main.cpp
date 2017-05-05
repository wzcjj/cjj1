//
//  main.cpp
//  6
//
//  Created by wzcjj on 16/7/28.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

char s[maxn],c;
struct State
{
    State *pre,*go[26];
    int step;
    void clear()
    {
        pre=0;
        step=0;
        memset(go,0,sizeof(go));
    }
    int calc()
    {
        if(pre==0) return 0;
        return step-pre->step;
    }
}*root,*last;

State statePool[maxn*2],*cur;

void init()
{
    cur=statePool;
    root=last=cur++;
    root->clear();
}

long long tot;
void Insert(int w)
{
    State *p=last;
    State *np=cur++;
    np->clear();
    np->step=p->step+1;
    while(p&&!p->go[w])
        p->go[w]=np,p=p->pre;
    if(p==0)
    {
        np->pre=root;
        tot+=np->calc();
    }
    else
    {
        State *q=p->go[w];
        if(p->step+1==q->step)
        {
            np->pre=q;
            tot+=np->calc();
        }
        else
        {
            State *nq=cur++;
            nq->clear();
            memcpy(nq->go,q->go,sizeof(q->go));
            tot-=p->calc()+q->calc();
            nq->step=p->step+1;
            nq->pre=q->pre;
            q->pre=nq;
            np->pre=nq;
            tot+=p->calc()+q->calc()+np->calc()+nq->calc();
            while(p&&p->go[w]==q)
                p->go[w]=nq, p=p->pre;
        }
    }
    last=np;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        I++;
        scanf("\n%c",&c);
        scanf("%s",s);
        n=strlen(s);
        tot=0;
        init();
        for(i=0;i<n;i++){
            Insert(s[i]-'a');
        }
        int now=-1;
        for(i=0;i<n;i++)if(s[i]==c){
            tot-=(i-now)*(i-now-1)/2;
            now=i;
        }
        tot-=(n-now)*(n-now-1)/2;
        printf("Case #%d: %lld\n",I,tot);
    }
    return 0;
}
