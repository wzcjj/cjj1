#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[50005],b[50005],c[50005];
int main(){
    int i,j,m,n,h;
    while(cin>>n>>m>>h){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)c[i]=a[i];
        int sum=0;
        for(i=1;i<=n;i++)sum+=a[i];
        if(sum<m*h){
            cout<<-1<<endl;
            continue;
        }
        int t=0;
        int start=n,end=0;
        memset(b,0,sizeof(b));
        for(i=n;i>=1;i--)if(a[i]>h){
            while(end+n-start-1<m&&h-b[end]<a[i]-h){
                a[i]-=h-b[end];
                t+=h-b[end];
                b[end]=h;
                end++;
            }
            b[end]+=a[i]-h;
            a[i]=h;
            if(b[end]==h)end++;
            start--;
        }
        else if(a[i]==h)start--;
        else break;
        int ans=(m-(end+n-start-1))*h-b[end]+t;
        for(i=1;i<=n;i++)a[i]=c[n-i+1];
        t=0;
        start=n,end=0;
        memset(b,0,sizeof(b));
        for(i=n;i>=1;i--)if(a[i]>h){
            while(end+n-start-1<m&&h-b[end]>a[i]-h){
                a[i]-=h-b[end];
                t+=h-b[end];
                b[end]=h;
                end++;
            }
            b[end]+=a[i]-h;
            a[i]=h;
            if(b[end]==h)end++;
            start--;
        }
        else if(a[i]==h)start--;
        else break;
        if(ans>(m-(end+n-start-1))*h-b[end]+t)ans=(m-(end+n-start-1))*h-b[end]+t;
        cout<<ans<<endl;
    }
    return 0;
}
    
