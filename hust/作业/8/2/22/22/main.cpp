#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define Maxn 40005
#define LL unsigned long long

const int x = 123;
char str[Maxn];
LL H[Maxn],xp[Maxn];
LL hash1[Maxn];
int rank1[Maxn];

int n,m;
//起始位置最大值
int pos = 0;

bool cmp(int a,int b)
{
    return hash1[a] < hash1[b] || (hash1[a] == hash1[b] && a < b);
}
void init()
{
    n = strlen(str);
    H[n] = 0;
    for(int i=n-1; i>=0; i--) H[i] = H[i+1]*x + (str[i] - 'a');
    xp[0] = 1;
    for(int i=1; i<=n; i++) xp[i] = xp[i-1] * x;
    
}
bool possible(int L)
{
    pos = -1;
    for(int i=0; i<n-L+1; i++)
    {
        rank1[i] = i;
        hash1[i] = H[i] - H[i+L]*xp[L];
    }
    sort(rank1,rank1 + n - L + 1,cmp);
    
    int c = 1;
    for(int i=0; i<n-L+1-1; i++)
    {
        if(hash1[rank1[i]] == hash1[rank1[i+1]]) c++;
        else
        {
            if(c>=m)
            {
                pos = max(pos,rank1[i]);
            }
            c = 1;
        }
    }
    if(c>=m)
    {
        pos = max(pos,rank1[n-L]);
    }
    if(pos == -1) return false;
    return true;
}
int binarySearch()
{
    
    int ans;
    if(!possible(1))
    {
        puts("none");
        return 0;
    }
    int l = 1,r = n;
    int mid;
    ans = l;
    //二分枚举长度
    while(l<r)
    {
        mid = (l + r + 1)>>1;
        if(possible(mid))
        {
            ans = mid;
            l = mid;
        }
        else r = mid-1;
    }
    //别忘了再进行一次
    possible(ans);
    printf("%d %d\n",ans,pos);
    return 0;
}
int main()
{
    while(scanf(" %d",&m)!=EOF && m!=0)
    {
        scanf(" %s",str);
        init();
        binarySearch();
    }
    return 0;
}
