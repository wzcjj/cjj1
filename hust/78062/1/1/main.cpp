#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
int D[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n;
int a[1001][1001][2];
bool tr (int &x,int &y,int &d,int i)
{
    int x1,y1;
    x1=x;
    y1=y;
    x1+=D[d][0];
    y1+=D[d][1];
    if (x1>=0 && x1<n && y1>=0 && y1<n  && a[x1][y1][i]==0)
    {
        a[x1][y1][i]=1;
        x=x1;
        y=y1;
        return true;
    }
    else
    {
        if (i==0) d=(d+1+4)%4;
        else d=(d-1+4)%4;
        x1=x;
        y1=y;
        x1+=D[d][0];
        y1+=D[d][1];
        if (x1>=0 && x1<n && y1>=0 && y1<n  && a[x1][y1][i]==0)
        {
            a[x1][y1][i]=1;
            x=x1;
            y=y1;
            return true;
        }
        return false;
    }

}
int main()
{


    int x1,y1,x2,y2,d1,d2;
    bool f,f1,f3,f4;
    scanf("%d",&n);
    while (n!=0)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&d1,&x2,&y2,&d2);
        f=false;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                a[i][j][0]=0;
                a[i][j][1]=0;
            }
        }
        a[x1][y1][0]=1;
        a[x2][y2][1]=1;
        f3=true;f4=true;
        while (true)
        {
            if (x1==x2 && y1==y2)
            {
                f=true;
                break;
            }
            else
            {
                //printf("%d %d %d %d--\n",x1,y1,x2,y2);
                if (f3) f3=tr (x1,y1,d1,0);
                if (f4) f4=tr(x2,y2,d2,1);
                if (!f3 && !f4)
                {
                    f=false;
                    break;
                }
            }
        }
        if (f) printf("%d %d\n",x1,y1);
        else
        printf("-1\n");
        scanf("%d",&n);
    }
    return 0;
}
