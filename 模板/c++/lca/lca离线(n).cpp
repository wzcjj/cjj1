// POJ 1330 
// Use Tarjan to solve LCA problem

#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int parent[MAX];
int rank[MAX];
int ancestor[MAX];
int indegree[MAX];
int visit[MAX];   // record 
vector<int> Tree[MAX], Ques[MAX];

// 加入初始化为多次运行清理环境 
int Init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
                     parent[i]=0;
                     rank[i]=0;
                     ancestor[i]=0;
                     indegree[i]=0;
                     visit[i]=0;
                     Tree[i].clear();
                     Ques[i].clear();
    }
    
    return 0;
} 

int MakeSet(int i)
{
    parent[i]=i;
    rank[i]=1;
    //ancestor[i]=i;
    
    return 0;
}

int Find(int i)
{
    if(parent[i]==i)
        return i;
    else
        parent[i]=Find(parent[i]);    
    return parent[i];
}

int Union(int x, int y)
{
    // 寻找集合的根
    int a=Find(x);
    int b=Find(y); 
    
    if(a==b)
        return 0;
    else if(rank[a]>rank[b])
    {
                       parent[b]=a;
                       rank[a]+=rank[b];
    }
    else
    {
         parent[a]=b;
         rank[b]+=rank[a];
    }
    /*
    else if(a!=b)
    {
         parent[b]=a;
         rank[a]+=1;
    }
    */
       
    return 0;
}


int LCA(int u)
{
    MakeSet(u);
    ancestor[u]=u;
    
    int size=Tree[u].size(); //
    for(int i=0;i<size;i++)
    {
            LCA(Tree[u][i]);
            //Union(u,i);
            Union(u, Tree[u][i]);
            ancestor[Find(u)]=u;
    }
    visit[u]=1;
    
    size=Ques[u].size(); // 统计与u相关的查询的个数 
    for(int i=0;i<size;i++)
    {
                       if(visit[Ques[u][i]]==1)
                       {
                           //cout<<ancestor[find(u)]<<endl;
                           cout<<ancestor[Find(Ques[u][i])]<<endl;
                           return 0;
                       }
    }
    
    return 0;
}

int main()
{
    int cnt; // number of Test cases need to be sloved
    int n;   // number of nodes in a tree
    cin>>cnt;
    while(cnt--)
    {
                int s, t, i;
                cin>>n;
                //for(int i=0;i<n;i++)
                Init(n);
                for(i=0;i<n-1;i++)  // N nodes then N-1 edges  此处i只为计数没有实际意义 
                {
                        cin>>s>>t;
                        Tree[s].push_back(t);
                        indegree[t]++;
                }

                cin>>s>>t;
                Ques[s].push_back(t);
                Ques[t].push_back(s); // 离线算法，两次询问
                
                //for(int i=0;i<n;i++) // nodes start at 1  此处i为节点 
                for(i=1;i<=n;i++)
                {
                        if(indegree[i]==0)
                        {
                                          LCA(i);
                                          break;
                        }
                } 
    }
    
    return 0;    
} 
 
