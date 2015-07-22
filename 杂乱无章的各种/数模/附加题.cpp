#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 100
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
int pro[maxm][200],aft[maxm][200];
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
int randnum(){
    int maxx=0,i,sum=0;
    for(i=0;i<maxm;i++)if(maxx<pro[i][0])maxx=pro[i][0];
    maxx++;
    int aa[maxm];
    for(i=0;i<maxm;i++)sum+=aa[i]=maxx-pro[i][0];
    int t=rand()%sum;
    for(i=0;i<maxm;i++){
        t-=aa[i];
        if(t<0)return i;
    }
    return 0;
}
int main(){
    srand(unsigned(time(0)));
    freopen("a.in","r",stdin);
    int i,j,k,t,l;
    cin>>n;
    for(i=0;pow(3,i)<=n;i++);
    m=i;
    while(true){
        int now=0;
        for(i=0;i<m;i++)for(j=1;j<=2;j++){
            b[i][j]=rand()%(pow(3,i)*j)+1;
            now=b[i][j];
        }
        b[0][1]=1;
        b[0][2]=2;
        b[0][3]=3;
        for(i=0;i<=n;i++)c[i].clear();
        for(i=0;i<m;i++)for(j=1;j<=2;j++)sum[i][j].clear();
        dfs(0);
        bool flag=false;
        for(j=1;j<=n;j++)if(c[j].size()==0){
            flag=true;
            break;
        }
        if(flag)continue;
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
        for(i=0;i<maxm;i++){
            for(j=1;j<=n;j++){
                pro[i][j]=rand()%c[j].size();
            }
        }
        for(int I=1;I<=50;I++){
            for(i=0;i<maxm;i++){
                for(j=0;j<m;j++)for(k=1;k<=2;k++)sum[j][k].clear();
                for(j=1;j<=n;j++){
                    for(k=0;k<c[j][pro[i][j]].size();k++)sum[c[j][pro[i][j]][k].x][c[j][pro[i][j]][k].y].push_back(j);
                }
                int maxx=0;
                for(j=0;j<m;j++){
                    for(k=1;k<=2;k++){
                        if(maxx<sum[j][k].size())maxx=sum[j][k].size();
                    }
                }
                if(maxx<ansl){
                    freopen("a.out","w",stdout);
                    for(j=0;j<m;j++){
                        for(k=1;k<=2;k++){
                            for(l=0;l<sum[j][k].size();l++)printf("%d ",sum[j][k][l]);
                            printf("      %d",sum[j][k].size());
                            printf("\n");
                        }
                        printf("\n\n");
                    }
                    ansl=maxx;
                    printf("%d\n",ansl);
                    fclose(stdout);
                }
                pro[i][0]=maxx;
            }
            for(i=0;i<maxm;i++){
                int t=randnum();
                for(j=1;j<=n;j++)aft[i][j]=pro[t][j];
            }
            for(i=0;i*2<maxm;i++){
                int t=rand()%(n-1);
                for(j=t+1;j<=n;j++)swap(aft[i*2][j],aft[i*2+1][j]);
            }
            for(k=1;k<=10;k++){
                i=rand()%maxm;
                j=rand()%n+1;
                aft[i][j]=rand()%c[j].size();
            }
            for(i=0;i<maxm;i++){
                for(j=1;j<=n;j++)pro[i][j]=aft[i][j];
            }
        }
    }
    return 0;
}
