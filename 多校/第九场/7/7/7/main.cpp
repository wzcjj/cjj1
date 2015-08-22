#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 105
#define P 1000000007
#define INF 2100000000
using namespace std;

int a[maxn][maxn];
int main(int argc, const char * argv[]) {
    freopen("in.txt","r",stdin);
    int i,j,m,n,N;
    int ans;
    while (scanf("%d%d",&n,&m)!=EOF) {
        ans = 0;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++) {
            scanf("%d",&a[i][j]);
            ans += a[i][j];
        }
        if(n&1){
            printf("%d\n",ans);
            for(i=1;i<=n;i++){
                if(i&1){
                    for(j=1;j<m;j++)printf("R");
                    if(i!=n)printf("D");
                }
                else{
                    for(j=1;j<m;j++)printf("L");
                    printf("D");
                }
            }
            printf("\n");
        }
        else if(m&1){
            printf("%d\n",ans);
            for(i=1;i<=m;i++){
                if(i&1){
                    for(j=1;j<n;j++)printf("D");
                    if(i!=m)printf("R");
                }
                else{
                    for(j=1;j<n;j++)printf("U");
                    printf("R");
                }
            }
            printf("\n");
        }
        else{
            int mi = 1000000;
            int nowx = 0,nowy = 0;
            for(i = 1;i <= n;i++) for(j = 1;j <= m;j++) {
                if((i+j) & 1) {
                    if(mi > a[i][j]) {
                        mi = a[i][j];
                        nowx = i;nowy = j;
                    }
                }
            }
            printf("%d\n",ans-mi);
            if(nowy & 1) {
                //printf("%d %d %d %d %d\n",mi,nowx,nowy,n,m);
                for(i = 1;i < nowy;i+=2) {
                    for(j = 1;j < n;j++) printf("D");
                    printf("R");
                    for(j = 1;j < n;j++) printf("U");
                    printf("R");
                }
                if(nowx != n) {
                    for(i = nowy;i < m;i++) printf("R");
                    printf("D");
                    for(i = 2;i < nowx;i+=2) {
                        for(j = m;j > nowy;j--) printf("L");
                        printf("D");
                        for(j = nowy;j < m;j++) printf("R");
                        printf("D");
                    }
                    for(i = m;i > nowy+1;i--) printf("L");
                    for(i = nowx+1;i < n;i+=2)printf("DLDR");
                    for(i = nowy+1;i < m;i+=2) {
                        printf("R");
                        for(j = n;j > nowx+1;j--) printf("U");
                        printf("R");
                        for(j = n;j > nowx+1;j--) printf("D");
                    }
                }
                else {
                    for(i = 1;i+2 < n;i+=2) {
                        for(j = nowy;j < m;j++) printf("R");
                        printf("D");
                        for(j = nowy;j < m;j++) printf("L");
                        printf("D");
                    }
                    printf("RD");
                    for(i = nowy + 2;i < m;i+=2) printf("RURD");
                }
            }
            else if(nowx & 1) {
                for(i = 1;i < nowx;i+=2) {
                    for(j = 1;j < m;j++) printf("R");
                    printf("D");
                    for(j = 1;j < m;j++) printf("L");
                    printf("D");
                }
                if(nowy != m) {
                    for(i = nowx;i < n;i++) printf("D");
                    printf("R");
                    for(i = 2;i < nowy;i+=2) {
                        for(j = n;j > nowx;j--) printf("U");
                        printf("R");
                        for(j = nowx;j < n;j++) printf("D");
                        printf("R");
                    }
                    for(i = n;i > nowx+1;i--) printf("U");
                    for(i = nowy+1;i < m;i+=2)printf("RURD");
                    for(i = nowx+1;i < n;i+=2) {
                        printf("D");
                        for(j = m;j > nowy+1;j--) printf("L");
                        printf("D");
                        for(j = m;j > nowy+1;j--) printf("R");
                    }
                }
                else {
                    for(i = 1;i+2 < m;i+=2) {
                        for(j = nowx;j < n;j++) printf("D");
                        printf("R");
                        for(j = nowx;j < n;j++) printf("U");
                        printf("R");
                    }
                    printf("DR");
                    for(i = nowx + 2;i < n;i+=2) printf("DLDR");
                }
            }
            printf("\n");
        }
    }
    return 0;
}