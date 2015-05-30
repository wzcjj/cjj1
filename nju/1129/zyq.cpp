#include <iostream>
#include<cstdlib>
using std::cin;
using std::cout;
using std:: endl;

void minus(int **n1,int**n2,int**n3,int m1)
{
    int i,j;
    for (i=1;i<=m1;++i)
        for (j=1;j<=m1;++j)
            n3[i][j]=n1[i][j]-n2[i][j];
    return;
}
void plus(int **n1,int**n2,int**n3,int m1)
{
    int i,j;
        for (i=1;i<=m1;++i)
        for (j=1;j<=m1;++j)
        {
            n3[i][j]=n1[i][j]+n2[i][j];
        }
    return;
}
void multi(int **p,int**q,int**qq,int m)
{
    if (m==1)
    {
        qq[1][1]=p[1][1]*q[1][1];
        return;
    }
    else
    {
        m=m/2;
        int k=m+1;
        int i,j;
        int **a=new int *[k];
        for (i=1;i<=m;++i)
        {
            a[i]=new int [k];
            for (j=1;j<=m;++j)
                a[i][j]=p[i][j];
        }
        int **b=new int *[k];
        for (i=1;i<=m;++i)
        {
            b[i]=new int [k];
            for (j=1;j<=m;++j)
                b[i][j]=p[i][j+m];
        }
        int **c=new int *[k];
        for (i=1;i<=m;++i)
        {
            c[i]=new int [k];
            for (j=1;j<=m;++j)
                c[i][j]=p[i+m][j];
        }
        int **d=new int *[k];
        for (i=1;i<=m;++i)
        {
            d[i]=new int [k];
            for (j=1;j<=m;++j)
                d[i][j]=p[i+m][j+m];
        }
        int **e=new int *[k];
        for (i=1;i<=m;++i)
        {
            e[i]=new int [k];
            for (j=1;j<=m;++j)
                e[i][j]=q[i][j];
        }
        int **f=new int *[k];
        for (i=1;i<=m;++i)
        {
            f[i]=new int [k];
            for (j=1;j<=m;++j)
            {
               // cout<<q[i][j+m]<<endl;
                f[i][j]=q[i][j+m];
            //cout<<f[i][j]<<endl;
            }
        }
        int **g=new int *[k];
        for (i=1;i<=m;++i)
        {
            g[i]=new int [k];
            for (j=1;j<=m;++j)
                g[i][j]=q[i+m][j];
        }
        int **h=new int *[k];
        for (i=1;i<=m;++i)
        {
            h[i]=new int [k];
            for (j=1;j<=m;++j)
                h[i][j]=q[i+m][j+m];
        }
int **mi=new int *[k];
        for (i=1;i<=m;++i) mi[i]=new int [k];
        int **p1=new int *[k];
        for (i=1;i<=m;++i) p1[i]=new int [k];
        int **pl=new int *[k];
        for (i=1;i<=m;++i) pl[i]=new int [k];
        minus(f,h,mi,m);
        multi(a,mi,p1,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) mi[i][j]=0;
        int **p2=new int *[k];
        for (i=1;i<=m;++i) p2[i]=new int [k];
        plus(a,b,pl,m);
        multi(pl,h,p2,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        int **p3=new int *[k];
        for (i=1;i<=m;++i) p3[i]=new int [k];
        plus(c,d,pl,m);
        multi(pl,e,p3,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        int **p4=new int *[k];
        for (i=1;i<=m;++i) p4[i]=new int [k];
        minus(g,e,mi,m);
        multi(d,mi,p4,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) mi[i][j]=0;
        int **p5=new int *[k];
        for (i=1;i<=m;++i) p5[i]=new int [k];
        plus(a,d,pl,m);
        int **p0=new int*[k];
        for(i=1;i<=m;++i) p0[i]=new int[k];
        plus(e,h,p0,m);
        multi(pl,p0,p5,m);
        delete[]p0;
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        int **p6=new int *[k];
        for (i=1;i<=m;++i) p6[i]=new int [k];
        minus(b,d,mi,m);
        plus(g,h,pl,m);
        multi(mi,pl,p6,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        int **p7=new int *[k];
        for (i=1;i<=m;++i) p7[i]=new int [k];
        minus(a,c,mi,m);
        plus(e,f,pl,m);
        multi(mi,pl,p7,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) mi[i][j]=0;
        plus(p5,p4,pl,m);
        minus(p6,p2,mi,m);//delete p4p2
        int **r=new int *[k];
        for (i=1;i<=m;++i) r[i]=new int [k];
        int **s=new int *[k];
        for (i=1;i<=m;++i) s[i]=new int [k];
        int **t=new int *[k];
        for (i=1;i<=m;++i) t[i]=new int [k];
        int **u=new int *[k];
        for (i=1;i<=m;++i) u[i]=new int [k];

        plus(pl,mi,r,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) mi[i][j]=0;
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        plus(p1,p2,s,m);
        plus(p3,p4,t,m);
        plus(p5,p1,pl,m);
        minus(pl,p3,mi,m);
        for (i=1;i<=m;++i)
            for (j=1;j<=m;++j) pl[i][j]=0;
        minus(mi,p7,u,m);
        for (i=1;i<=m;++i)
          for (j=1;j<=m;++j)
                      {
                          qq[i][j]=r[i][j];
                          qq[i][j+m]=s[i][j];
                          qq[i+m][j]=t[i][j];
                          qq[i+m][j+m]=u[i][j];
                      }
        delete[]a;
        delete[]b;
        delete[]c;
        delete[]d;
        delete[]e;
        delete[]f;
        delete[]p1;
        delete[]p2;
        delete[]p3;
        delete[]p4;
        delete[]p5;
        delete[]p6;
        delete[]p7;
        delete[]mi;
        delete[]pl;
        delete[]r;
        delete[]s;
        delete[]t;
        delete[]u;
        return;
        
}
}

int main(int argc, const char * argv[]) {
    int n,s,i,j;
    cin>> n;
    s=1;
    for (i=1;i<=n/2;++i) s*=2;
    int **p=new int *[s+1];
    for (i=1;i<=s;++i)
    {
        p[i]=new int [s+1];
        for (j=1;j<=s;++j)
            cin>>p[i][j];
    }
    int **q=new int *[s+1];
    for (i=1;i<=s;++i)
    {
        q[i]=new int [s+1];
        for (j=1;j<=s;++j)
            cin>>q[i][j];
    }
    int **tt=new int*[s+1];
    for (i=1;i<=s;++i) tt[i]=new int[s+1];
    multi(p,q,tt,s);
    for (i=1;i<=s;++i)
    {
        for(j=1;j<s;++j) cout<<tt[i][j]<<' ';
        cout<<tt[i][s];
        cout<<endl;
    }
    multi(q,p,tt,s);
    for (i=1;i<=s;++i)
    {
        for (j=1;j<s;++j) cout<<tt[i][j]<<' ';
        cout<<tt[i][s];
        cout<<endl;
    }
    system("pause"); 
    return 0;
}
