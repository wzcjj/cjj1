#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 10050
#define NIL
#define MOD 1000000007
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
LL b,q,a,d,n,m;
LL ni[MAX];
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//*********求逆元素*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t,cnt = 0;
    cin >> t;
    for(int i = 1;i <= 10000;i++) {
        ni[i] = mod_reverse(i,MOD);
    }
    while(t--) {
        printf("Case #%d: ",++cnt);
        scanf("%lld%lld%lld%lld%lld%lld",&b,&q,&a,&d,&n,&m);
        LL ans = 0;
        LL tmp = 1;
        for(int i = 1;i <= m;i++) {
            tmp *= n+m-i;
            tmp = ((tmp % MOD) + MOD) % MOD;
            tmp *= ni[i];
            tmp = ((tmp % MOD) + MOD) % MOD;
        }
        ans = tmp * a;
        ans = ((ans % MOD) + MOD) % MOD;
        cout << ans << " ";
        LL tmp2 = tmp;
        tmp2 *= n-1;
        tmp2 = ((tmp2 % MOD) + MOD)% MOD;
        tmp2 *= ni[m+1];
        tmp2 = ((tmp2 % MOD) + MOD)% MOD;
        ans += tmp2 * d;
        ans = ((ans % MOD) + MOD) % MOD;
        cout << ans << " ";
        LL qq = 1;
        for(int i = 1;i <= m;i++) {
            qq *= q;
            qq = ((qq % MOD) + MOD) % MOD;
            tmp *= m-i+1;
            tmp *= ni[n+m-i];
            tmp = ((tmp % MOD) + MOD) % MOD;
            LL tmp3 = tmp * qq;
            tmp3 = ((tmp3 % MOD) + MOD)% MOD;
            tmp3 *= b;
            tmp3 = ((tmp3 % MOD) + MOD)% MOD;
            ans += tmp3;
            ans = ((ans % MOD) + MOD) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}