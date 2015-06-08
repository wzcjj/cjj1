#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int x1,y1,x2,y2;
}a[50],b[50];
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
bool cmpa(node x,node y){
    return x.x1<y.x1;
}
bool cmpb(node x,node y){
    return x.y1<y.y1;
}
int main(){
    int i,j,m,n,N,k,l;
    cin>>N;
    int I=0;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        cin>>n;
        int as=0,bs=0,ans=0;
        for(i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){
                if(y1>y2)swap(y1,y2);
                a[++as].x1=x1;
                a[as].x2=x2;
                a[as].y1=y1;
                a[as].y2=y2;
            }
            else{
                if(x1>x2)swap(x1,x2);
                b[++bs].x1=x1;
                b[bs].x2=x2;
                b[bs].y1=y1;
                b[bs].y2=y2;
            }
        }
        sort(a+1,a+as+1,cmpa);
        sort(b+1,b+bs+1,cmpb);
        for(i=1;i<as;i++){
            for(j=i+1;j<=as;j++){
                for(k=1;k<bs;k++){
                    for(l=k+1;l<=bs;l++){
                        if(a[i].x1>b[k].x1&&a[i].x1>b[l].x1&&a[j].x1<b[k].x2&&a[j].x1<b[l].x2&&b[k].y1>a[i].y1&&b[k].y1>a[j].y1&&b[l].y1<a[i].y2&&b[l].y1<a[j].y2)ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
} 
