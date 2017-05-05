#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
struct node{
    int x,y;
};
node a[maxn];
int b[maxn];
int main(){
    int i,j,m,n,ans=0,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)if(i!=j){
            b[j]=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
        }
        sort(b+1,b+n);
        for(j=1;j<n;j++){
            for(k=j;k<n;k++){
                if(b[k]!=b[k+1])break;
            }
            ans+=(k-j)*(k-j+1)/2;
            j=k+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
