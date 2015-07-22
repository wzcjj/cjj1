//
//  main.cpp
//  1041c
//
//  Created by mac on 15-7-7.
//  Copyright (c) 2015Äê mac. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;
#define max1 2000
bool a[max1][max1];
int n;
int t;
int c[max1],p[max1],d[max1],f[max1];
queue<int> q1;
void dfs(int x)
{
    int i;
    d[x]=t;
    c[x]=1;
    for (i=0;i<n;++i)
        if (a[x][i]==1&&c[i]==0)
        {
            p[i]=x;
            t++;
            dfs(i);
        }
    t++;
    f[x]=t;
}
int main(int argc, const char * argv[]) {
    int s,i,j;
    while(cin>>n>>s)
    {
        for (i=0;i<n;++i)
            for (j=0;j<n;++j)
            {
                cin>>a[i][j];
                
            }
        for (i=0;i<n;++i)
             {
                 c[i]=0;
                 p[i]=-1;
                 d[i]=9999;
             }
        c[s]=1;
        d[s]=0;
     
        q1.push(s);
    
        while(!q1.empty())
        {
            i=q1.front();
            q1.pop();
            for(j=0;j<n;++j)
                if (a[i][j]==1&&c[j]==0&&i!=j)
                {
                    c[j]=1;
                    d[j]=d[i]+1;
                    p[j]=i;
                    q1.push(j);
                }
        }
    
        for (i=0;i<n;++i)
                cout<<i<<' '<<d[i]<<' '<<p[i]<<endl;
        for (i=0;i<n;++i)
        {
            c[i]=0;
            f[i]=0;
            d[i]=0;
        }
        t=1;
        for (i=0;i<n;++i)
            if (c[i]==0)dfs(i);
        for (i=0;i<n;++i)
            cout<<i<<' '<<d[i]<<' '<<f[i]<<endl;
    }
    return 0;
}
