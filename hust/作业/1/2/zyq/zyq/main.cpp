#include <iostream>
#include<cstring>
#include<string>
using namespace std;
#define maxn 11000;
struct node
{
    int v;
    int left;
    int right;
    int  p;
};
node q [11000];
void  print(int x)
{
    if(q[x].left) print(q[x].left);
    if(q[x].right) print(q[x].right);
    if(x!=1)cout<<q[x].v<<' ';
}
void insert(int now,int x)
{
    if (q[now].v>q[x].v)
        if (q[now].left) insert(q[now].left,x);
        else q[now].left=x;
    else
        if(q[now].right)insert(q[now].right,x);
        else q[now].right=x;
}
int main(int argc, const char * argv[]) {
    int i,x;
    i=2;
    cin>>x;
    q[1].v=x;
    q[1].left=0;
    q[1].right=0;
    while (cin>>x)
    {
        if (x==-1) break;
        q[i].v=x;
        q[i].left=0;
        q[i].right=0;
        insert(1,i);
        i++;
    }
    print(1);
    cout<<q[1].v<<endl;
    return 0;
}