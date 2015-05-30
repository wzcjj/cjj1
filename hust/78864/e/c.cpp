#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 205
int n;
bool gra[MAX][MAX];
struct P {
    int x,y;
    friend bool operator == (P p1,P p2) {return (p1.x==p2.x)&&(p1.y==p2.y);}
}p[MAX];
bool OK(int x1,int y1,int x2,int y2) {
    if(p[x1]==p[y1] || p[x2]==p[y2]) return false;
    if(!gra[p[y1].x][p[x1].y] || !gra[p[x1].x][p[y1].y] || !gra[p[y2].x][p[x2].y] || !gra[p[x2].x][p[y2].y]) return false;
    if(p[x1].x == p[y1].x || p[x1].y == p[y1].y || p[x2].x == p[y2].x || p[x2].y == p[y2].y) return false;
    int tmpx1 = p[x2].x,tmpx2 = p[y2].x;
    int tmpy1 = p[x2].y,tmpy2 = p[y2].y;
    if(tmpx1 > tmpx2) swap(tmpx1,tmpx2);
    if(tmpy1 > tmpy2) swap(tmpy1,tmpy2);
    if(p[x1].x >= tmpx1 && p[x1].x <= tmpx2 && p[x1].y >= tmpy1 && p[x1].y <= tmpy2) return false;
    if(p[y1].x >= tmpx1 && p[y1].x <= tmpx2 && p[y1].y >= tmpy1 && p[y1].y <= tmpy2) return false;
    if(p[x1].x >= tmpx1 && p[x1].x <= tmpx2 && p[y1].y >= tmpy1 && p[y1].y <= tmpy2) return false;
    if(p[y1].x >= tmpx1 && p[y1].x <= tmpx2 && p[x1].y >= tmpy1 && p[x1].y <= tmpy2) return false;
    tmpx1 = p[x1].x,tmpx2 = p[y1].x;
    tmpy1 = p[x1].y,tmpy2 = p[y1].y;
    if(tmpx1 > tmpx2) swap(tmpx1,tmpx2);
    if(tmpy1 > tmpy2) swap(tmpy1,tmpy2);
    if(p[x2].x >= tmpx1 && p[x2].x <= tmpx2 && p[x2].y >= tmpy1 && p[x2].y <= tmpy2) return false;
    if(p[y2].x >= tmpx1 && p[y2].x <= tmpx2 && p[y2].y >= tmpy1 && p[y2].y <= tmpy2) return false;
    if(p[x2].x >= tmpx1 && p[x2].x <= tmpx2 && p[y2].y >= tmpy1 && p[y2].y <= tmpy2) return false;
    if(p[y2].x >= tmpx1 && p[y2].x <= tmpx2 && p[x2].y >= tmpy1 && p[x2].y <= tmpy2) return false;
    printf("%d,%d,%d,%d\n",x1,y1,x2,y2);
    return true;
}
int calc(int x1,int y1,int x2,int y2) {
    int s1 = abs(p[x1].x-p[y1].x)*abs(p[x1].y-p[y1].y);   
    int s2 = abs(p[x2].x-p[y2].x)*abs(p[x2].y-p[y2].y);
    return s1+s2;
}
int main() {
    while(cin >> n && n) {
        memset(gra, false,sizeof gra);
        for(int i = 1;i <= n;i++) {
            cin >> p[i].x >> p[i].y;
            gra[p[i].x][p[i].y] = true;
        }       
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = i;j <= n;j++) {
                for(int x = j;x <= n;x++) {
                    for(int y = x;y <= n;y++) {
                        if(OK(i,j,x,y)) ans = max(ans,calc(i,j,x,y));
                        //else puts("!!!");
                    }
                }    
            }
        }
        printf((!ans)?"imp\n":"%d\n",ans);
    }   
    return 0;
} 
