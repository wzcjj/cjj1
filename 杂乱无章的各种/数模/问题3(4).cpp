#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#define maxn 10
using namespace std;
int b[maxn][3];
struct node{
    int x,y;
};
vector< vector<node> > c[1000];
int pow(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++)ans*=x;
    return ans;
}
int n,m,ansl=1000;
vector<int> sum[maxn][3];
vector<node> t;
void dfs(int x){
    if(x>=m){
        int sum1=0;
        for(int i=0;i<t.size();i++)sum1+=b[t[i].x][t[i].y];
        if(sum1<=n)c[sum1].push_back(t);
        return;
    }
    for(int j=1;j<=2;j++){
        node t1;
        t1.x=x;
        t1.y=j;
        t.push_back(t1);
        dfs(x+1);
        t.pop_back();
    }
    dfs(x+1);
}
void calc(int x){
    if(x>n){
        int maxx=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<=2;j++){
                if(sum[i][j].size()>maxx)maxx=sum[i][j].size();
            }
        }
        if(maxx<ansl){
            freopen("a.out","w",stdout);
            ansl=maxx;
            for(int i=0;i<m;i++){
                for(int j=1;j<=2;j++){
                    for(int k=0;k<sum[i][j].size();k++){
                        printf("%d ",sum[i][j][k]);
                    }
                    printf("           %d",sum[i][j].size()); 
                    printf("\n");
                }
                printf("\n\n");
            }
            printf("%d\n",ansl);
            //printf("aa");
            fclose(stdout);
            freopen("CON","w",stdout);
            //printf("bb");
        }
        return;
    }
    for(int i=0;i<c[x].size();i++){
        i=rand()%c[x].size();
        for(int j=0;j<c[x][i].size();j++){
            sum[c[x][i][j].x][c[x][i][j].y].push_back(x);
        }
        calc(x+1);
        for(int j=0;j<c[x][i].size();j++){
            sum[c[x][i][j].x][c[x][i][j].y].pop_back();
        }
        break;
    }
}
int main(){
    srand(unsigned(time(0)));
    freopen("a.in","r",stdin);
    int i,j,k,t,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
    cin>>n>>i1>>i2>>i3>>i4>>i5>>i6>>i7>>i8>>i9>>i10;
    for(i=0;pow(3,i)<=n;i++);
    m=i;
        b[0][1]=i1;
        b[0][2]=i2;
        b[1][1]=i3;
        b[1][2]=i4;
        b[2][1]=i5;
        b[2][2]=i6;
        b[3][1]=i7;
        b[3][2]=i8;
        b[4][1]=i9;
        b[4][2]=i10;
        for(i=0;i<=n;i++)c[i].clear();
        for(i=0;i<m;i++)for(j=1;j<=2;j++)sum[i][j].clear();
        dfs(0);
        bool flag=false;
        for(j=1;j<=n;j++)if(c[j].size()==0){
            flag=true;
            break;
        }
        if(flag)return 0;
        for(i=0;i<m;i++){
            for(j=1;j<=2;j++){
                c[b[i][j]].clear();
                node t1;
                vector<node> t2;
                t1.x=i;
                t1.y=j;
                t2.push_back(t1);
                c[b[i][j]].push_back(t2);
            }
        }
        freopen("b.out","w",stdout);
        for(i=1;i<=n;i++){
            printf("%d\n",i);
            for(j=0;j<c[i].size();j++){
                for(k=0;k<c[i][j].size();k++)printf("%d ",b[c[i][j][k].x][c[i][j][k].y]);
                printf("\n");
            }
            printf("\n\n");
        }
        fclose(stdout);
        while(true)calc(1);
    return 0;
}
