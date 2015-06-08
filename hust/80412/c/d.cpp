#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define N 2000
#define MN 100
int nl=0,n,m;
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

int a[12][MN*MN][2];
int al[12];
int dp[12][MN*MN];

int mapp[MN][MN];
int map[MN][MN];
bool visited[MN][MN];
int list[MN*MN][2];int ll;

int s[6][2];int sl;

int tr(int x1,int y1,int x2,int y2)
{
    int s=0;
    ll=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            visited[i][j]=true;
    int t1,t2,t3;
    list[0][0]=x1;
    list[0][1]=y1;
    mapp[x1][y1]=0;
    visited[x1][y1]=false;
    while (s<ll)
    {
       //printf("(%d,%d)\n", list[s][0],list[s][1]);
        for (int i=0;i<4;i++)
        {
            t1=list[s][0]+dir[i][0];
            t2=list[s][1]+dir[i][1];
            
            if (t1>=0 && t1<n && t2>=0 && t2<n && visited[t1][t2]==true && map[t1][t2]!=-1) 
            {
                list[ll][0]=t1;
                list[ll][1]=t2;
                visited[t1][t2]=false;
                mapp[t1][t2]=mapp[list[s][0]][list[s][1]]+1;
                if (t1==x2 && t2==y2) {
                    s=ll+2;
                    break;
                }
                ll++;
            }
        }
        s++;
    }
    if (visited[x2][y2]) return 20000;
    else return mapp[t1][t2];
}                
    
    
    
int main()
{
    char s1[MN];
    scanf("%d %d",&n,&m);
    int t1,t2,t3,t4,ma,t5;
    while (n!=0 || m!=0)
    {
        sl=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",s1);
            for (int j=0;j<n;j++)
            {
                switch( s1[j])
                {
                    case '.':
                        map[i][j]=-3;
                        break;
                    case '#':
                        map[i][j]=-1;
                        break;
                    case 'S':
                        s[sl][0]=i;
                        s[sl][1]=j;
                        sl++;            
                        map[i][j]=-2;
                        break;
                    case 'K':
                        a[0][0][0]=i;
                        a[0][0][1]=j;
                        al[0]=1;
                        map[i][j]=0;
                        break;
                    case 'T':
                        map[i][j]=m+1;
                        break;
                    default:
                        map[i][j]=s1[j]-'0';
                }
            }
        }
     /*               printf("~~~~~\n");
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                  printf("%d  ",map[i][j]);
                printf("\n");
            }
       while (true)
        {
            scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
            printf("%d\n",tr(t1,t2,t3,t4));
        }*/
        dp[0][0]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                mapp[i][j]=map[i][j];
        ma=20000;
        for (int i=0;i<(1<<sl);i++)
        {
            t1=i;
            t5=0;
            for (int j=0;j<sl;j++)
            {
                t2=t1%2;
                if (t2==1) {map[s[j][0]][s[j][1]]=-3;t5++;}
                else map[s[j][0]][s[j][1]]=-1;
                t1/=2;
            }
                  //  printf("~~~~~\n");
           /* for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                  printf("%d  ",map[i][j]);
                printf("\n");
            }*/
            
            for (int i=0;i<=m;i++)
            {
                al[i+1]=0;
                for (int k1=0;k1<n;k1++)
                    for (int k2=0;k2<n;k2++)
                    {
                        if (map[k1][k2]==i+1)
                        {
                            dp[i+1][al[i+1]]=20000;
                            for (int j=0;j<al[i];j++)
                            {
                                dp[i+1][al[i+1]]=min(dp[i+1][al[i+1]],tr(a[i][j][0],a[i][j][1],k1,k2)+dp[i][j]);
                               // printf("---%d %d %d %d\n",dp[i+1][al[i+1]],tr(a[i][j][0],a[i][j][1],k1,k2),k1,k2);
                                a[i+1][al[i+1]][0]=k1;
                                a[i+1][al[i+1]][1]=k2;
                                
                            }
                           // printf("*%d %d %d\n",dp[i+1][al[i+1]],a[i+1][al[i+1]][0],a[i+1][al[i+1]][0]);
                            al[i+1]++;
                        }
        
                    }
            }
            ma=min(ma,dp[m+1][0]+t5);
        }
            
            if (ma<20000) printf("%d\n",ma);
                else printf("impossible\n");
            scanf("%d %d",&n,&m);
    }
    return 0;
}
