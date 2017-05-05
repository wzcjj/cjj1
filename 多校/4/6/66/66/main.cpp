#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1e7+7;
const int maxm=1e5+3;
short f[maxn];
unsigned int hash1[maxn],p[maxm];
int cnt[maxm];
char s[maxm];
char t[2];

unsigned int seed=131;

unsigned int calc(int s,int e)
{
    return (hash1[e]-hash1[s-1]*p[e-s+1])%maxn;
}

int main()
{
    p[0]=1;
    for (int i=1;i<maxm;i++)
        p[i]=p[i-1]*seed;
    int mk=1;
    int ans;
    while (scanf("%s%s",t,s)==2)
    {
        ans=0;
        unsigned int tt=0;
        int l=strlen(s);
        char ts=t[0];
        int ct=0;
        cnt[0]=0;
        for (int i=0;i<l;i++)
        {
            tt=tt*seed+*(s+i);
            hash1[i+1]=tt;
            if (s[i]==ts) ct++;
            cnt[i+1]=ct;
        }
        //	cout<<ts<<endl;
        for (int i=1;i<=l;i++)
        {
            int ps=1,pe=i;
            if (cnt[i]!=cnt[0] && hash1[calc(1,i)]!=mk){
                while (ps!=pe)
                {
                    int m=(ps+pe)/2+1;
                    unsigned int hs=calc(m,i);
                    if (hash1[hs]!=mk && cnt[i]!=cnt[m-1]) ps=m;
                    else pe=m-1;
                }
                //cout<<i<< " "<<pe<<endl; 
                ans+=pe;
                for (int j=1;j<=pe;j++)
                {
                    hash1[calc(j,i)]=mk;
                }
            }
        }
        mk++;
        //if (cnt[l]!=0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}