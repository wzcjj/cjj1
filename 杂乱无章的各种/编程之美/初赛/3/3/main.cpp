#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> qwe;
bool asd[500005];
bool a[1005][1005];
int b[1005],n;
bool que(int x){
    int l=-1,r=qwe.size();
    while(l<r-1){
        int mid=(l+r)>>1;
        if(x==qwe[mid])return true;
        else if(x<qwe[mid])r=mid;
        else l=mid;
    }
    return false;
}
bool quer(int x){
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i][j]&&(x&(1<<(i-1)))==0&&(x&(1<<(j-1)))==0)return false;
    return true;
}
int main()
{
    int i,j,I,N,ans;
    memset(asd,false,sizeof(asd));
    memset(a,false,sizeof(a));
    for(i=2;i<=500000;i++)if(!asd[i]){
        for(j=2;j*i<=500000;j++)asd[i*j]=true;
    }
    for(i=2;i<=500000;i++)if(!asd[i])qwe.push_back(i);
    /*cout<<qwe.size()<<endl;
    cout<<que(2)<<endl;
    for(i=0;i<20;i++)cout<<qwe[i]<<endl;*/
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if((b[i]%b[j]==0&&que(b[i]/b[j]))||(b[j]%b[i]==0&&que(b[j]/b[i]))){
            a[i][j]=a[j][i]=true;
        }
        ans=10000;
        /*for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)cout<<a[i][j]<<' ';
            cout<<endl;
        }*/
        for(i=0;i<(1<<n);i++)if(quer(i)){
            int t=0;
            //cout<<i<<endl;
            for(j=0;j<n;j++)if(i&(1<<j))t++;
            if(t<ans)ans=t;
        }
        printf("Case #%d: %d\n",I,n-ans);
    }
    return 0;
}
