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
#define MAX
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int main()
{
    //freopen("in.txt","r",stdin);
    int ans[82][82];
    for(int i = 1;i <= 81;i++) {
        for(int j = 1;j <= 81;j++) {
            int x1 = (i-1)%9 + 1;
            int x2 = (j-1)%9 + 1;
            int y1 = (i-1)/9 + 1;
            int y2 = (j-1)/9 + 1;
            ans[i][j] = pow((x1-x2),2) + pow((y1-y2),2);
        }
    }
    //for(int i = 1;i <= 81;i++) for(int j = 1;j <= 81;j++) printf("%d\t",ans[i][j]);printf("\n");
    /*for(int i = 1;i <= 81;i++) {
        for(int j = i+1;j <= 81;j++) {
            for(int k = j+1;k <= 81;k++) {
                for(int p = k+1;p <= 81;p++) {
                    if(ans[i][j] == ans[j][p] && ans[j][p] == ans[k][p] && ans[k][p] == ans[k][i]) {
                        printf("%d %d %d %d\n",i,j,k,p);
                    }
                    else if (ans[i][j] == ans[i][k] && ans[i][k] == ans[k][p] && ans[k][p] == ans[k][i]) {
                        printf("%d %d %d %d\n",i,j,k,p);
                    }
                }
            }
        }
    }*/
    for(int i1 = 1;i1 <= 81;i1++) for(int i2 = i1+1;i2 <= 81;i2++) for(int i3 = i2+1;i3 <= 81;i3++) for(int i4 = i3+1;i4 <= 81;i4++) for(int i5 = i4+1;i5 <= 81;i5++) for(int i6 = i5+1;i6 <= 81;i6++) {
        if(ans[i1][i2] == ans[i2][i4] && ans[i2][i4] == ans[i4][i6] && ans[i4][i6] == ans[i6][i5] && ans[i6][i5] == ans[i5][i3] && ans[i3][i1] == ans[i5][i3]) {
            printf("%d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6);
        }
        else if(ans[i1][i2] == ans[i1][i3] && ans[i1][i3] == ans[i3][i5] && ans[i3][i5] == ans[i6][i5] && ans[i6][i5] == ans[i6][i4] && ans[i6][i4] == ans[i4][i1]) {
            printf("%d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6);
        }
        else if(ans[i1][i2] == ans[i2][i4] && ans[i2][i4] == ans[i4][i6] && ans[i4][i6] == ans[i6][i5] && ans[i6][i5] == ans[i5][i3] && ans[i5][i3] == ans[i3][i1]) {
            printf("%d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6);
        }
    }
    return 0;
}