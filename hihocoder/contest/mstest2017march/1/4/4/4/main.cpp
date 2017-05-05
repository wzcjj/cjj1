#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 1005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

bool a[maxn];
int dp[maxn][maxn],b[maxn];
void calc(char*s,int &x,int &y){
    int n,m,i,j;
    n=strlen(s);
    m=0;
    for(i=0;i<n;i++)if(s[i]=='(')m++;
    //else m--;
    if(m*2==n){
        x=0;
        y=1;
        //printf("0 1\n");
        return;
    }
    int cnt=0,now=0,sum=0;
    memset(dp,0,sizeof(dp));
    if(m*2>n){
        for(i=n-1;i>=0;i--){
            if(s[i]==')'){
                cnt++;
            }
            else {
                if(cnt){
                    cnt--;
                    a[++now]=0;
                }
                else {
                    a[++now]=1;
                    b[++sum]=now;
                }
            }
        }
    }
    else {
        for(i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else {
                if(cnt){
                    cnt--;
                    a[++now]=0;
                }
                else {
                    a[++now]=1;
                    b[++sum]=now;
                }
            }
        }
        m=n-m;
    }
    for(i=0;i<=m;i++)dp[0][i]=1;
    for(i=1;i<=sum;i++){
        for(j=1;j<=b[i];j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%P;
        }
        for(j=b[i]+1;j<=m;j++)dp[i][j]=dp[i][j-1];
    }
    x=2*m-n;
    y=dp[sum][b[sum]];
}
char s[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    scanf("%s",s);
    n=strlen(s);
    m=0;
    int minm=0,mini=n-1;
    for(i=0;i<n;i++){
        if(s[i]=='(')m++;
        else {
            m--;
            if(m<minm){
                minm=m;
                mini=i;
            }
        }
    }
    int x1,y1,x2,y2;
    char t=s[mini+1];
    s[mini+1]=0;
    calc(s,x1,y1);
    s[mini+1]=t;
    calc(s+mini+1,x2,y2);
    //printf("%d %d %d %d %d\n",x1,y1,x2,y2,mini);
    printf("%d %d\n",x1+x2,(int)(((long long)y1)*y2%P));
    //printf("%d %d\n",2*m-n,dp[sum][b[sum]]);
    return 0;
}
