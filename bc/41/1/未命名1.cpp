#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[10];
bool b[10][20];
int main(){
    int i,j,m,n,I,N;
    cin>>N;
    for(I=1;I<=N;I++){
        memset(b,0,sizeof(b));
        for(i=1;i<=5;i++){
            char c;
            int t;
            scanf("%c",&c);
            while(c>'D'||c<'A')scanf("%c",&c);
            scanf("%d",&t);
            b[c-'A'][t]=true;
        }
        int ans=0;
        for(i=0;i<=3;i++){
            for(j=1;j<=10;j++){
                int cnt=0;
                for(int k=0;k<5;k++)if(b[i][(j+k-1)%13+1]==true)cnt++;
                if(cnt>ans)ans=cnt;
            }
        }
        cout<<5-ans<<endl;
    }
    return 0;
}
                
         
