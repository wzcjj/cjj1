#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

stack<int> s;

const int maxn=1000005;
const int maxm=4*maxn;

int a[maxn],f[maxn][2],dp[maxn][2],d[maxn];
int et[maxm],ef[maxm];
bool v[maxn],vc[maxn];
int c[maxn];
int tot,num;
bool flag;
int ne[maxn];

void add(int x,int y)
{
    
    d[x]++;
    tot++;ef[tot]=a[x];
    a[x]=tot;et[tot]=y;
}

void dfs(int t,int fa)
{
    v[t]=true;
    s.push(t);
    for(int i=a[t];i;i=ef[i])
    {
        if((i^fa)==1)continue;
        int x=et[i];
        if(v[x])
        {
            int y;
            do
            {
                y=s.top();
                s.pop();
                c[++num]=y;
                vc[y]=true;
            }while(y!=x);
            while(!s.empty())s.pop();
            flag=true;
            break;
        }
        dfs(x,i);
        if(flag)break;
    }
    if(!s.empty())s.pop();
}

int g(int t,int s,int fa)
{
    if(f[t][s]!=-1)return f[t][s];
    if(d[t]==1)
    {
        f[t][s]=0;
        return 0;
    }
    f[t][s]=0;
    int z=0;
    for(int i=a[t];i;i=ef[i])
    {
        int x=et[i];
        if(vc[x]||x==fa)continue;
        z+=g(x,1,t);
    }
    if(s==0)
    {
        f[t][s]=z;
    }else
    {
        for(int i=a[t];i;i=ef[i])
        {
            int x=et[i];
            if(vc[x]||x==fa)continue;
            f[t][s]=max(f[t][s],z-g(x,1,t)+g(x,0,t)+1);
        }
    }
    return f[t][s];
}

int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        tot=1;
        memset(ef,0,sizeof ef);
        memset(a,0,sizeof a);
        memset(v,0,sizeof v);
        memset(vc,0,sizeof vc);
        memset(f,-1,sizeof f);
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            ne[i]=x;
            add(i,x);add(x,i);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(!v[i])
            {
                int tmp=-n;
                flag=false;
                num=0;
                dfs(i,0);
                if(ne[2]==ne[1])
                {
                    for(int j=1;j<=num/2;++j)
                    {
                        int t=c[j];
                        c[j]=c[num-j+1];
                        c[num-j+1]=t;
                    }
                }
                dp[1][0]=max(g(c[1],0,0),g(c[1],1,0));dp[1][1]=-n;
                for(int j=2;j<=num;++j)
                {
                    dp[j][0]=max(dp[j-1][1],dp[j-1][0])+g(c[j],0,0);
                    dp[j][1]=max(dp[j-1][1]+g(c[j],1,0),dp[j-1][0]+max(g(c[j],0,0)+1,g(c[j],0,1)));
                }
                tmp=max(dp[num][0],dp[num][1]);
                dp[1][0]=-n;dp[1][1]=g(c[1],0,0)+1;
                for(int j=2;j<=num;++j)
                {
                    dp[j][0]=max(dp[j-1][1],dp[j-1][0])+g(c[j],0,0);
                    dp[j][1]=max(dp[j-1][1]+g(c[j],1,0),dp[j-1][0]+max(g(c[j],0,0)+1,g(c[j],0,1)));
                }
                tmp=max(tmp,dp[num][0]);
                ans+=tmp;
            }
        }
        printf("%d\n",ans);
    }
}