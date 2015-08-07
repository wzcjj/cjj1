#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 1000050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int ql,qr;
int p[MAX];
VI v[8];
int c(int l,int r,int i) {
    int posl,posr;
    int tmpl = 0;
    int tmpr = v[i].size()-1;
    if(v[i][tmpr] < l) return 0;
    tmpr++;
    while(tmpl < tmpr) {
        int m = (tmpl + tmpr) / 2;
        if(v[i][m] < l) tmpl = m+1;
        else if(v[i][m] > l) tmpr = m;
        else {
            posl = m;break;
        }
    }
    if(tmpl == tmpr) posl = tmpl;
    tmpl = 0;
    tmpr = v[i].size()-1;
    tmpr++;
    while(tmpl < tmpr) {
        int m = (tmpl + tmpr) / 2;
        if(v[i][m] < r) tmpl = m+1;
        else if(v[i][m] > r) tmpr = m;
        else {
            posr = m;break;
        }
    }
    if(tmpl == tmpr) posr = tmpl;
    int ret = posr - posl;
    if(v[i][posr] == r) ret ++;
    return ret;
}
int main()
{
    memset(p,0,sizeof p);
    p[1] = 1;
    for(int i = 2;i <= 1000000;i++) {
        if(!p[i]) for(int j = i;j <= 1000000;j += i) p[j] ++;
    }
    for(int i = 1;i <= 7;i++) v[i].clear();
    for(int i = 1;i <= 1000000;i++) {
        if(p[i] > 1) v[p[i]].push_back(i);
    }
    int t;cin >> t;
    while(t--) {
        scanf("%d%d",&ql,&qr);
        int ans[8];
        bool flag[8];
        for(int i = 2;i <= 7;i++) {
            ans[i] = c(ql,qr,i);
            if(ans[i] >= 1) flag[i] = true;
            else flag[i] = false;
        }
        if(ans[7] >= 2) {puts("7");continue;}
        if(ans[6] >= 2) {puts("6");continue;}
        if(ans[5] >= 2) {puts("5");continue;}
        if(ans[4] >= 2) {puts("4");continue;}
        if((ans[3] >= 2) || (flag[3] && flag[6])) {puts("3");continue;}
        if((ans[2] >= 2) || (flag[2] && flag[4]) || (flag[2] && flag[6]) || (flag[4] && flag[6])) {puts("2");continue;}
        puts("1");
    }
    return 0;
}