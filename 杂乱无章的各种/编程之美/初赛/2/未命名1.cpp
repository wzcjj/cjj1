#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include <iomanip>

using namespace std;
struct node{
    int x,y,w;
}a[1005];
int main()
{
    int i,j,m,n,I,N,k;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n;
        double ans=0;
        for(i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        for(i=0;i<(1<<n);i++){
            double now=0;
            for(j=0;j<n;j++)if(i&(1<<j)){
                now+=a[j+1].w;
                now-=a[j+1].y*a[j+1].y;
            }
            for(j=0;j<n;j++)for(k=j+1;k<n;k++)if((a[j+1].y+a[k+1].y)/2.0-abs(a[j+1].x-a[k+1].x)>0)now+=((a[j+1].y+a[k+1].y)/2.0-abs(a[j+1].x-a[k+1].x))*((a[j+1].y+a[k+1].y)/2.0-abs(a[j+1].x-a[k+1].x))/4.0;
            if(now>ans)ans=now;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
