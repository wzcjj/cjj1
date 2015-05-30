#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 30
bool flag,vst[MAX];
int n,m,q,cnt,ans;
int gra[10][10];
inline int row(int x) {return x/n;}
inline int col(int x) {return x-row(x)*n;}
void pr() {
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("%d\t",gra[i][j]);
        }
        puts("");
    }   
}
bool check(int r,int c,int a[],int& t) {
    t = 0;
    for(int i = 0;i < n;i++) {
        if(i == c) continue;
        int flag = 0;
        for(int j = i+1;j < n;j++) {
            if(!flag && gra[r][j] != 0) flag++;
            if(flag == 1 && gra[r][j] == 1) {flag++;break;}
            if(flag == 1 && gra[r][j] == -1) break;
        }
        if(flag == 2 && !vst[r*n+i]) {
            if(gra[r][i] == 1) return false;
            a[t++] = r*n+i;
            continue;
        }
        flag = 0;
        for(int j = i-1;j >= 0;j--) {
            if(!flag && gra[r][j] != 0) flag++;
            if(flag == 1 && gra[r][j] == 1) {flag++;break;}
            if(flag == 1 && gra[r][j] == -1) break;
        }
        if(flag == 2 && !vst[r*n+i]) {
            if(gra[r][i] == 1) return false;
            a[t++] = r*n+i;
        }
    }   
    for(int i = 0;i < n;i++) {
        if(i == r) continue;
        int flag = 0;
        for(int j = i+1;j < n;j++) {
            if(!flag && gra[j][c] != 0) flag++;
            if(flag == 1 && gra[j][c] == 1) {flag++;break;}
            if(flag == 1 && gra[j][c] == -1) break;
        }
        if(flag == 2 && !vst[i*n+c]) {
            if(gra[i][c] == 1) return false;
            a[t++] = i*n+c;
            continue;
        }
        flag = 0;
        for(int j = i-1;j >= 0;j--) {
            if(!flag && gra[j][c] != 0) flag++;
            if(flag == 1 && gra[j][c] == 1) {flag++;break;}
            if(flag == 1 && gra[j][c] == -1) break;
        }
        if(flag == 2&& !vst[i*n+c]) {
            a[t++] = i*n+c;
            if(gra[i][c] == 1)
                return false;
        }
    }   
    return true;
}
void dfs(int x,int now,int left) {
    printf("dfs%d,%d,%d\n",x,now,left);
    pr();
    //system("pause");
    if(left + now < ans) return;
    if(x >= n*m) {
        ans = max(ans,now);
        return;
    }
    int r = row(x),c = col(x);
    if(gra[r][c] == -1 || vst[x] == true) 
        dfs(x+1,now,left-1);
    else {
        vst[x] = true;
        dfs(x+1,now,left-1);
        int a[10],t = 0;
        if(check(r,c,a,t)) {
            gra[r][c] = 1;
            for(int i = 0;i < t;i++) 
                vst[a[i]] = true;
            dfs(x+1,now+1,left-1);
            for(int i = 0;i < t;i++)
                vst[a[i]] = false;
            gra[r][c] = 0;
        }
        vst[x] = false;
    }
}
int main(){
    while(cin >> n >> m >> q) {
        memset(gra,0,sizeof gra);
        cnt = q;ans = 0;
        for(int i = 0;i < q;i++) {
            int x,y;cin >> x >> y;
            gra[x][y] = -1;
        }
        memset(vst,false,sizeof vst);
        dfs(0,0,n*m-q);
        cout << ans << endl;
    }
    return 0;
}
