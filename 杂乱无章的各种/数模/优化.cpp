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
    if(x>=m)return;
    for(int j=1;j<=2;j++){
        node t1;
        t1.x=x;
        t1.y=j;
        t.push_back(t1);
        int sum1=0;
        for(int i=0;i<t.size();i++)sum1+=b[t[i].x][t[i].y];
        if(sum1<=n)c[sum1].push_back(t);
        dfs(x+1);
        t.pop_back();
    }
    int sum1=0;
    for(int i=0;i<t.size();i++)sum1+=b[t[i].x][t[i].y];
    if(sum1<=n)c[sum1].push_back(t);
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
    int i,j,k,t,i4,i5,i6,i7,i8,i9,i10;
    cin>>n;
    for(i=0;pow(3,i)<=n;i++);
    m=i;
    b[0][1]=1;
    b[0][2]=2;
    b[1][1]=3;
    while(true){
        //printf("aa");
    //for(i4=4;i4<=6;i4++)
//    for(i5=i4+2;i5<=9;i5++)
//    for(i6=i5+3;i6<=18;i6++)
//    for(i7=max(i6+4,13);i7<=27;i7++)
//    for(i8=max(i7+5,27);i8<=53;i8++)
//    for(i9=max(i8+6,40);i9<=60;i9++)
//    for(i10=70;i10<=76;i10++){
        i4=rand()%3+4;
        i5=rand()%(9-i4)+i4+1;
        i6=rand()%(18-i5)+i5+1;
        i7=rand()%(27-i6)+i6+1;
        i8=rand()%(53-i7)+i7+1;
        i9=rand()%(60-i8)+i8+1;
        i10=rand()%(77-i9)+i9+1;
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
        //for(i=1;i<=100;i++)cout<<c[i].size()<<endl;
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
        for(j=1;j<=n;j++)calc(1);
    //}
    }
    return 0;
}
