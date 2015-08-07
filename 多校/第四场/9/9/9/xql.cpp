#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")

const int maxn=1010;
int map[maxn][maxn];
int ans[2*maxn+1];int al;
int T,n,m;
int visited[maxn][maxn];
int list[maxn*maxn][4];int li,ci,lp;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int maxp;
bool dfs(int i,int j,int m1) //0 test //1 real
{
    int t1,t2;
    //printf("--%d %d\n",i,j);
    if (i+j>maxp) maxp=i+j;
    if (m1==0 || (m1==1 && i+j==maxp))
    {
        list[li][0]=i;
        list[li][1]=j;
        list[li][2]=-1;
        list[li][3]=1;
        li++;
    }
    visited[i][j]=1;
    if (map[i][j]==1) return 0;
    for (int i1=0;i1<4;i1++)
    {
        t1=i+dir[i1][0];
        t2=j+dir[i1][1];
        if (t1>=1 && t2>=1 && t1<=n &&t2<=m &&map[t1][t2]==0 && !visited[t1][t2] )
        {
            dfs(t1,t2,m1);
        }
    }
    return true;
}
int main()
{
    bool f1;
    scanf("%d",&T);
    char s[maxn];
    for (int i=0;i<T;i++)
    {
        scanf("%d%d",&n,&m);
        li=0;
        ci=1;
        lp=0;
        for (int i1=0;i1<=n;i1++)
            for (int j1=0;j1<=m;j1++)
                visited[i1][j1]=0;
        for (int i1=1;i1<=n;i1++)
        {
            scanf("%s",s);
            for (int j1=1;j1<=m;j1++)
            {
                map[i1][j1]=s[j1-1]-'0';
            }
        }
        maxp=0;
        dfs(1,1,0);
        for (int i1=0;i1<li;i1++)
        {
            visited[list[i1][0]][list[i1][1]]=0;
        }
        li=0;
        dfs(1,1,1);
        //printf("**%d\n",li);
        while (lp<li)
        {
            int cc=lp;
            int t1,t2;
            int f=1;
            while (list[cc][3]==ci && f==1 && cc<li)
            {
                for (int i1=0;i1<2;i1++)
                {
                    t1=list[cc][0]+dir[i1][0];
                    t2=list[cc][1]+dir[i1][1];
                    if (t1>=1 && t2>=1 && t1<=n &&t2<=m &&map[t1][t2]==0 && !visited[t1][t2])
                    {
                        f=0;
                        break;
                    }
                }
                cc++;
            }
            cc=lp;
            f1=true;
            while (cc<li && list[cc][3]==ci &&  f1)
            {
                //printf("--*%d %d %d\n",list[cc][0],list[cc][1],f);
                for (int i1=0;i1<2;i1++)
                {
                    t1=list[cc][0]+dir[i1][0];
                    t2=list[cc][1]+dir[i1][1];
                    if ((t1==n && t2==m) || (t1>=1 && t2>=1 && t1<=n &&t2<=m &&map[t1][t2]==f && !visited[t1][t2]))
                    {
                        visited[t1][t2]=1;
                        list[li][0]=t1;
                        list[li][1]=t2;
                        list[li][2]=cc;
                        list[li][3]=list[cc][3]+1;
                        if (t1==n && t2==m)
                        {
                            f1=false;
                            break;
                        }
                        li++;
                    }
                }
                cc++;
            }
            if (!f1) 
            {
                //	printf("enter %d\n");
                al=0;
                int ll=li;
                while (ll!=-1)
                {
                    ans[al]=map[list[ll][0]][list[ll][1]];
                    //printf("(%d %d %d\n",list[ll][0],list[ll][1],ans[al]);
                    al++;
                    ll=list[ll][2];
                    
                }
                al--;
                while (al>0 && ans[al]==0)
                {
                    al--;
                }
                for (int i1=al;i1>=0;i1--)
                {
                    printf("%d",ans[i1]);
                }
                printf("\n");
                break;
            }
            lp=cc;
            ci++;
        }
        if (f1) printf("%d\n",map[n][m]);
    }
    return 0;
}