#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
vector<int> a[100001];
int d[100001];
int n;
int main()
{
  scanf("%d",&n);
  int x,y;
  for (int i=1;i<n;i++)
  {
    scanf("%d%d",&x,&y);
    a[x].push_back(y);    
    a[y].push_back(x);
  }    
  deque<int> e;
  e.push_back(1); 
  memset(d,0,sizeof(d)); 
  d[1]=1;
  while (!e.empty())
  {
    int now=e.front();
    e.pop_front();
    for (int i=0;i<a[now].size();i++)
      if (!d[a[now].at(i)])
      {
        e.push_back(a[now].at(i));
        d[a[now].at(i)]=d[now]+1;                                      
      }
  }
  x=1;

  for (int i=1;i<=n;i++)
    if (d[x]<d[i]) x=i;
  e.push_back(x);
  memset(d,0,sizeof(d)); 
  d[x]=1;
  while (!e.empty())
  {
    int now=e.front();
    e.pop_front();
    for (int i=0;i<a[now].size();i++)
      if (!d[a[now].at(i)]&&a[now].at(i)!=x)
      {
        e.push_back(a[now].at(i));
        d[a[now].at(i)]=d[now]+1;                                      
      }
  }
  x=1;  
  for (int i=1;i<=n;i++)
    if (d[x]<d[i]) x=i;  
  printf("%d\n",d[x]-1);
  //system("pause");
  return 0; 
}
