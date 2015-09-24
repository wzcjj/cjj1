#include <iostream>
#include<cstring>
#include<string>
using namespace std;
#define maxN 101000
int a[maxN];
int b[maxN],c[maxN],ans[maxN];
int main(int argc, const char * argv[]) {
    long long  s1,s2,n,s,i,k;
    s2=0;
    int index;
    cin>>n>>s;
    memset(b,0,sizeof b);
    memset(ans,0,sizeof ans);
    for (i=1;i<=n;++i)cin>>a[i];
    k=1;//记录下当前指针到第几个数
    index=1;//记录下当前可以向后几个数
    s1=0;
    a[0]=0;
    for (i=1;i<=n;++i)
    {
        s1-=a[i-1];
        index--;
        while (k<=n)
        {
            if (s1+a[k]<=s)
            {
                s1+=a[k];
                k++;
                index++;
            }
            else break;
        }
        b[i]=index;
    }
    
    a[n+1]=0;
    k=n;
    int k_index=1;
    for(i=n;i>=1;--i)
    {
        s2-=a[i+1];
        k_index--;
        while(k>=1)
        {
            if(s2+a[k]<=s)
            {
                s2+=a[k];
                k--;
                k_index++;
            }
            else break;
        }
        c[i]=k_index;
    }
     for (i=1;i<=n;++i) cout<<b[i]<<' ';
      cout<<endl;
    for (i=1;i<=n;++i) cout<<c[i]<<' ';
    
    for(i=1;i<=n;++i)
        if(b[i]>(c[i-1])) ans[i-c[i-1]]=2*c[i-1];
        else  ans[i-b[i]]=2*b[i];
    //   for(i=1;i<=n;++i) cout<<ans[i]<<' ';
    
    for(i=1;i<=n-1;++i)
        if (ans[i]==0&&ans[i-1]>0) ans[i]=ans[i-1]-2;
        else if(ans[i]==0&&(ans[i-1]==0))ans[i]=0;
    ans[n]=0;
    for(i=1;i<=n;++i) cout<<ans[i]<<endl;
    //std::cout << "Hello, World!\n";
    return 0;
}