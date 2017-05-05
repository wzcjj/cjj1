#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define is(X) cout << #X << " = " << X << endl
using namespace std;
typedef long long LL;
LL n,mi,mx;
struct S {
    LL p,r;
}pri[20];
LL cnt[100005];
int cntb;
LL ni[20];
LL quick_inverse(LL n, LL p) {
    LL ret = 1;
    int exponent = p - 2;
    n=n%p;
    for (int i = exponent; i; i >>= 1, n = n * n % p) {
        if (i & 1) {
            ret = ret * n % p;
        }
    }
    return ret;
}
bool vst[20];
LL fin(int x) {
    LL tmp = 1;
    memset(vst,false,sizeof vst);
    cntb = 0;
    for(int i = 0;i <= n;i++) {
        if((1<<i) & x) {
            vst[i] = true;
            cntb++;
            tmp *= pri[i].p;
        }
    }
    LL ret = 0;
    for(int i = 0;i <= n;i++) {
        if(vst[i]) {
            LL m = tmp / pri[i].p;
            //is(pri[i].p);is(m);is(quick_inverse(m,pri[i].p));is(pri[i].r);
            ret += pri[i].r * quick_inverse(m,pri[i].p) * m;
            //is(ret);
        }
    }
    ret = (tmp + (ret % tmp)) % tmp;
    //if(ret == 0) ret = tmp;
    //is(ret);is(tmp);
    LL mi2 = mi - (mi%tmp>ret? mi%tmp-ret : mi%tmp+tmp-ret) + 1;
    LL mx2 = mx - (mx%tmp>=ret? mx%tmp-ret : mx%tmp+tmp-ret);
    LL dif = mx2 - mi2 + 1;
    LL ans = dif / tmp;
    return ans;
}
int main()
{
    int t;cin >> t;
    int cc = 1;
    //is(quick_inverse(3,7));
    while(t--) {
        printf("Case #%d: ",cc++);
        scanf("%lld%lld%lld",&n,&mi,&mx);
        memset(pri,0,sizeof pri);
        pri[0].p = 7;pri[0].r = 0;ni[0] = -1;
        for(int i = 1;i <= n;i++) {
            scanf("%lld%lld",&pri[i].p,&pri[i].r);
            //ni[i] = -1;
        }
        memset(cnt,0,sizeof cnt);
        LL ans = 0;
        for(int i = 1;i < (1<<(1+n));i+=2) {
            cnt[i] = fin(i);
            //is(i);is(cnt[i]);
            if(cntb & 1) ans += cnt[i];
            else ans -= cnt[i];
        }
        cout << ans << endl;
    }
    return 0;
}