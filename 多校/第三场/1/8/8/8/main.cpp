#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int ans;
void dfs(int l,int r){
    if(ans!=-1&&r>=ans)return;
    if(l==0){
        ans=r;
        return;
    }
    if(r-l+1>l)return;
    dfs(l-r+l-1,r);
    dfs(l-r+l-2,r);
    dfs(l,r+r-l);
    dfs(l,r+r-l+1);
}
int main()
{
    int l,r;
    while(cin>>l>>r) {
        ans=-1;
        dfs(l,r);
        cout<<ans<<endl;
    }
    return 0;
}