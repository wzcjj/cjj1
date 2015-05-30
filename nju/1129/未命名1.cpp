#include<cstdio>
#include<iostream>
typedef int* int1;
typedef int1* int2;
using namespace std;
struct node{
    int2 sq;
};
node sm(node a,int x,int y,int size){
    node c;
    int i;
    c.sq=new int1[size/2+1];
    for(i=1;i<=size/2;i++)c.sq[i]=new int[size/2+1];
    if(x==1)x=0;
    else x=size/2;
    if(y==1)y=0;
    else y=size/2;
    for(i=x+1;i<=x+size/2;i++)for(int j=y+1;j<=y+size/2;j++)c.sq[i-x][j-y]=a.sq[i][j];
    return c;
}
node pl(node a,node b,int pos,int size){
    node c;
    int i;
    c.sq=new int1[size+1];
    for(i=1;i<=size;i++)c.sq[i]=new int[size+1];
    if(pos==1)for(i=1;i<=size;i++)for(int j=1;j<=size;j++)c.sq[i][j]=a.sq[i][j]+b.sq[i][j];
    else for(i=1;i<=size;i++)for(int j=1;j<=size;j++)c.sq[i][j]=a.sq[i][j]-b.sq[i][j];
    return c;
}
node c[3][3];
node mul(node a,node b,int size){
    if(size==1){
        node d;
        d.sq=new int1[size+1];
        for(int i=1;i<=size;i++)d.sq[i]=new int[size+1];
        d.sq[1][1]=a.sq[1][1]*b.sq[1][1];
        return d;
    }
    node s[11];
    s[1]=pl(sm(b,1,2,size),sm(b,2,2,size),-1,size/2);
    s[2]=pl(sm(a,1,1,size),sm(a,1,2,size),1,size/2);
    s[3]=pl(sm(a,2,1,size),sm(a,2,2,size),1,size/2);
    s[4]=pl(sm(b,2,1,size),sm(b,1,1,size),-1,size/2);
    s[5]=pl(sm(a,1,1,size),sm(a,2,2,size),1,size/2);
    s[6]=pl(sm(b,1,1,size),sm(b,2,2,size),1,size/2);
    s[7]=pl(sm(a,1,2,size),sm(a,2,2,size),-1,size/2);
    s[8]=pl(sm(b,2,1,size),sm(b,2,2,size),1,size/2);
    s[9]=pl(sm(a,1,1,size),sm(a,2,1,size),-1,size/2);
    s[10]=pl(sm(b,1,1,size),sm(b,1,2,size),1,size/2);
    node p[8];
    p[1]=mul(sm(a,1,1,size),s[1],size/2);
    p[2]=mul(s[2],sm(b,2,2,size),size/2);
    p[3]=mul(s[3],sm(b,1,1,size),size/2);
    p[4]=mul(sm(a,2,2,size),s[4],size/2);
    p[5]=mul(s[5],s[6],size/2);
    p[6]=mul(s[7],s[8],size/2);
    p[7]=mul(s[9],s[10],size/2);
    c[1][1]=pl(pl(p[5],p[4],1,size/2),pl(p[6],p[2],-1,size/2),1,size/2);
    c[1][2]=pl(p[1],p[2],1,size/2);
    c[2][1]=pl(p[3],p[4],1,size/2);
    c[2][2]=pl(pl(p[5],p[1],1,size/2),pl(p[3],p[7],1,size/2),-1,size/2);
    int i,j;
    node d;
    d.sq=new int1[size+1];
    for(i=1;i<=size;i++)d.sq[i]=new int[size+1];
    for(i=1;i<=size/2;i++)for(j=1;j<=size/2;j++)d.sq[i][j]=c[1][1].sq[i][j];
    for(i=1;i<=size/2;i++)for(j=1+size/2;j<=size;j++)d.sq[i][j]=c[1][2].sq[i][j-size/2];
    for(i=1+size/2;i<=size;i++)for(j=1;j<=size/2;j++)d.sq[i][j]=c[2][1].sq[i-size/2][j];
    for(i=1+size/2;i<=size;i++)for(j=1+size/2;j<=size;j++)d.sq[i][j]=c[2][2].sq[i-size/2][j-size/2];
    for(i=1;i<=10;i++)delete []s[i].sq;
    for(i=1;i<=7;i++)delete []p[i].sq;
    for(i=1;i<=2;i++)for(j=1;j<=2;j++)delete []c[i][j].sq;
    return d;
}
void out(node d,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++)cout<<d.sq[i][j]<<' ';
        cout<<d.sq[i][n]<<endl;
    }
}
int main(){
    int i,j,n;
    node a,b;
    cin>>n;
    a.sq=new int1[n+1];
    for(i=1;i<=n;i++)a.sq[i]=new int[n+1];
    b.sq=new int1[n+1];
    for(i=1;i<=n;i++)b.sq[i]=new int[n+1];
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>a.sq[i][j];
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>b.sq[i][j];
    node d;
    d=mul(a,b,n);
    out(d,n);
    delete []d.sq;
    d=mul(b,a,n);
    out(d,n);
    system("pause");
    return 0;
}
