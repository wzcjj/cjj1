#include<vector>
#include<set>
#include<iostream>
#include<queue>
#include<math.h>
#include<stdio.h>
using namespace std;
pair< vector<int>,vector<int> > a;
pair< vector<int>,vector<int> > get_input()
{
  pair< vector<int>,vector<int> > a;
  int x,y;
  scanf("%d%d",&x,&y);    
  while (x!=0||y!=0)
  {
    a.first.push_back(x);
    a.second.push_back(y);
    scanf("%d%d",&x,&y);      
  }
  return a;
}
int sqr(int &x)
{
 return x*x;   
}
void ins (int &x,int &y)
{
  a.first.push_back(x);
  a.second.push_back(y);
  int i=a.first.size()-1;
  while (i>0&&sqr(a.first.at(i))+sqr(a.second.at(i))
  <sqr(a.first.at((i+1)/2-1))+sqr(a.second.at((i+1)/2-1)))
  {
    int t=a.first.at(i);
    a.first.at(i)=a.first.at((i+1)/2-1);
    a.first.at((i+1)/2-1)=t;  
    t=a.second.at(i);
    a.second.at(i)=a.second.at((i+1)/2-1);
    a.second.at((i+1)/2-1)=t;    
    i=(i+1)/2-1;                                                  
  }
}
void down()
{
  int i=0;
  while ((i+1)*2-1<a.first.size())
  {
    int j=(i+1)*2-1;
    if ((j+1)<a.first.size()&&sqr(a.first.at(j))+sqr(a.second.at(j))
    >sqr(a.first.at(j+1))+sqr(a.second.at(j+1)))
    j++;
    if (sqr(a.first.at(i))+sqr(a.second.at(i))<
    sqr(a.first.at(j))+sqr(a.second.at(j))) return;
    int t=a.first.at(i);
    a.first.at(i)=a.first.at(j);
    a.first.at(j)=t;  
    t=a.second.at(i);
    a.second.at(i)=a.second.at(j);
    a.second.at(j)=t;    
    i=j;     
  }   
}
void heap_sort(pair< vector<int>,vector<int> > &p)
{
  for (int i=0;i<p.first.size();i++)
    ins(p.first.at(i),p.second.at(i));
  for (int i=p.first.size()-1;i>=0;i--)
  {
    printf("%d",sqr(a.first.front())+sqr(a.second.front()));
    if (i) printf(" ");
    else printf("\n");
    a.first.at(0)=a.first.back();
    a.second.at(0)=a.second.back();
    a.first.pop_back();
    a.second.pop_back();
    down();    
  }   
}
struct cmp1{
    bool operator() ( pair <int , int > a, pair <int ,int > b ){
       return sqr(a.first)+sqr(a.second)>sqr(b.first)+sqr(b.second);
       }
};
void priority_queue_sort(pair< vector<int>,vector<int> > &p)
{
  priority_queue < pair<int,int>,vector<pair < int , int > >, cmp1 >  a;
  pair<int , int > x;
  for (int i=0;i<p.first.size();i++)
  {
    x.first=p.first.at(i);
    x.second=p.second.at(i);
    a.push(x);    
  }
  for (int i=0;i<p.first.size();i++)
  {
    x=a.top();
    a.pop();
    printf("%d",sqr(x.first)+sqr(x.second));
    if (i<p.first.size()-1) printf(" ");
    else printf("\n");
  }
}
struct cmp2{
    bool operator() ( pair <int , int > a, pair <int ,int > b ){
       return sqr(a.first)+sqr(a.second)<sqr(b.first)+sqr(b.second);
       }
};
void set_sort(pair< vector<int>,vector<int> > &p)
{
 multiset<pair< int , int >,cmp2> a;
 pair <int ,int > x;
 for (int i=0;i<p.first.size();i++)
 {
   x.first=p.first.at(i);
   x.second=p.second.at(i);
   a.insert(x);
 } 
 for (int i=0;i<p.first.size();i++)
 {
   x=*a.begin();
   a.erase(a.begin());
    printf("%d",sqr(x.first)+sqr(x.second));
    if (i<p.first.size()-1) printf(" ");
    else printf("\n");   
 }
}     
int main(int argc, char *argv[]) {
//freopen("a.in","r",stdin);
//freopen("a.out","w",stdout); 
    pair< vector<int>,vector<int> > p;

    p=get_input();

    heap_sort(p);

    priority_queue_sort(p);

    set_sort(p);
    //system("pause");
    return 0;
}
