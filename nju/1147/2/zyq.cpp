//
//  main.cpp
//  1167b
//
//  Created by mac on 15-7-10.
//  Copyright (c) 2015年 mac. All rights reserved.
//

#include <iostream>//根据所有直径一定相交，先找出过直径的点
#include<vector>
using namespace std;
#define maxn 15000
int point,dia;
int m[maxn];
 vector<int>v[maxn];
void dfs(int x, int px)
{

    m[x]=m[px]+1;
    if(m[x]>dia)
    {
        point=x;
        dia=m[x];
    }
    for (int i=0; i<v[x].size(); ++i)
        if (v[x][i] != px)
        {
            dfs(v[x][i],x);
        }

 
}


int main(int argc, const char * argv[]) {
    int i,n,x,y;
    while(cin>>n)
    {
    while(cin>>x>>y)
    {
        if(x==0)break;
        v[x].push_back(y);
        v[y].push_back(x);
    }
        for(i=0;i<=n;++i) m[i]=0;
       dia=0;
    dfs(1,0);
    dia=0;
    dfs(point,0);
    cout<<dia-1<<endl;
    }
    return 0;
}
