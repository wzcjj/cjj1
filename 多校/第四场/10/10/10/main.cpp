#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
//#include <map1>
#include <set>
#include <queue>

using namespace std;
const int maxn=110;
int map1[maxn][maxn][2];
int mark[maxn][2];
int wd[maxn];
int ans[maxn];
int ex[maxn][2];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int r,c,T,n;
struct drop{
public:
    int x,y,t;
    //int op;//0 break; 1 plus
    friend bool operator<(const drop& a,const drop& b) //const
    {
        return a.t>b.t;
    }
    /*friend bool operator()(const drop& a,const drop& b) //const
     {
     return a.t<b.t;
     }*/
};
int main()
{
    int t1,t2,t3;
    drop t4,t5;
    memset(map1,0,sizeof(map1));
    while (scanf("%d%d%d%d",&r,&c,&n,&T))
    {
        memset(ex,0,sizeof(ex));
        priority_queue<drop> l;
        for (int i=1;i<=n;i++)
        {
            
            scanf("%d%d%d",&t1,&t2,&t3);
            map1[t1][t2][0]=t3;
            ex[t1][0]=1;
            ex[t2][1]=1;
            mark[i][0]=t1;
            mark[i][1]=t2;
            map1[t1][t2][1]=i;
        }
        scanf("%d%d",&t1,&t2);
        map1[t1][t2][1]=n+1;
        t4.x=t1;
        t4.y=t2;
        t4.t=0;
        //t4.op=0;
        l.push(t4);
        while (!l.empty())
        {
            t4=l.top();
            l.pop();
            //printf("op==%d %d %d %d\n",t4.op,t4.x,t4.y,t4.t);
            
            for (int i=0;i<4;i++)
                if ((i/2==0 && ex[t4.x][0]==1) ||(i/2==1 && ex[t4.y][1]==1))
                {
                    int x1=t4.x;
                    int y1=t4.y;
                    int t1=t4.t;
                    bool f=true;
                    while (f)
                    {
                        x1+=dir[i][0];
                        y1+=dir[i][1];
                        t1+=1;
                        if (x1<=r && x1>=1 && y1>=1 &&y1<=c)
                        {
                            if (map1[x1][y1][0]>0)
                            {
                                map1[x1][y1][0]++;
                                if (map1[x1][y1][0]>4)
                                {
                                    map1[x1][y1][0]=-1;
                                    t5.x=x1;
                                    t5.y=y1;
                                    t5.t=t1;
                                    l.push(t5);
                                    ans[map1[x1][y1][1]]=t1;
                                    //map1[x1][t4.y][0]=-1;
                                }
                                //printf("%d %d %d\n",t5.x,t5.y,t5.t);
                                f=false;
                            }
                        }
                        else
                            f=false;
                    }
                }
            
        }
        for (int i=1;i<=n;i++)
        {
            int x=mark[i][0];
            int y=mark[i][1];
            if (map1[x][y][0]>0)
                printf("1 %d\n",map1[x][y][0]);
            else
                printf("0 %d\n",ans[i]);
            map1[x][y][0]=0;
        }
    }
    return 0;
}