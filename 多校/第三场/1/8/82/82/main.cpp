# include <iostream>
# include <cstdio>
using namespace std;
long long l,r,n;
bool flag;
void dfs(long long ll,long long rr,int depth)
{
    if (flag&&rr>=n)return;
    if (ll==0){
        if (!flag)n=rr;
        else if (n>rr)n=rr;
        flag=1;
        return;
    }
    if (rr-ll+1>ll+1)return;
    if (depth==11)return;
    dfs((ll-1)*2-rr,rr,depth+1);
    dfs(2*ll-rr-1,rr,depth+1);
    dfs(ll,2*rr-ll,depth+1);
    dfs(ll,2*rr-ll+1,depth+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    while (scanf("%I64d %I64d",&l,&r)!=EOF) {
        if (l!=0){
            flag=0;n=r;dfs(l,r,0);
            if (flag)printf("%I64d\n",n);
            else printf("-1\n");
        }
        else printf("%I64d\n",r);
    }
    return 0;
}