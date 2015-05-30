#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
  
const int N = 101000;
const int Sqrt = 333;
int ll[N],rr[N],kk[N],idx[N],n,m,a[N],freq[N],cnt[N],ans[N];
  
bool cmp(int a,int b) {
        if (ll[a]/Sqrt == ll[b]/Sqrt) {
                return rr[a]<rr[b];
        }
        return ll[a] < ll[b];
}
  
int query(int k) {
        int l = 1,r = 100000;
        while (l<=r) {
                int mid = l+r>>1;
                if (freq[mid]>=k) {
                        l = mid+1;
                } else {
                        r = mid-1;
                }
        }
        return l-1;
}
  
int main() {
   //     freopen("in.txt","r",stdin);
   //     freopen("out.txt","w",stdout);
        int cas;
        scanf("%d",&cas);
        while (cas--) {
                scanf("%d%d",&n,&m);
                for (int i = 0; i < n; i ++) {
                        scanf("%d",a+i);
                }
                for (int i = 0; i < m; i ++) {
                        scanf("%d%d%d",ll+i,rr+i,kk+i); ll[i] --; rr[i] --;
                        idx[i] = i;
                }
                sort(idx,idx+m,cmp);
                memset(freq,0,sizeof(freq));
                memset(cnt,0,sizeof(cnt));
                int cl = 0,cr = -1;
                for (int i = 0; i < m; i ++) {
                        int l = ll[idx[i]];
                        int r = rr[idx[i]];
                        int k = kk[idx[i]];
                        while (cr<r) { freq[++cnt[a[++cr]]] ++; }
                        while (l<cl) { freq[++cnt[a[--cl]]] ++; }
                        while (r<cr) { freq[cnt[a[cr--]]--] --; }
                        while (cl<l) { freq[cnt[a[cl++]]--] --; }
                        ans[idx[i]] = query(k);
                }
                for (int i = 0; i < m; i ++) {
                        printf("%d\n",ans[i]);
                }
        }
        return 0;
}
