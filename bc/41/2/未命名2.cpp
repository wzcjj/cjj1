#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s[20005];
bool b[10][20];
int main(){
    int i,j,m,n,I,N;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n;
        for(i=1;i<=n;i++)cin>>s[i];
        sort(s+1,s+n+1);
        int cnt=0,a1=0,a2=0;
        for(i=1;i<=n-1;i++)if(s[i]==s[i+1]){
            int aa=0;
            for(j=i+1;j<=n;j++)if(s[i]==s[j])aa++;
            else break;
            cnt+=aa*(aa+1)/2;
            i=j-1;
        }
        for(i=1;i<=n;i++)if(s[i].length()%2==0)a2++;
        else a1++;
        int fenzi=a2*(a2-1)/2+a1*(a1-1)/2;
        fenzi-=cnt;
        int fenmu=n*(n-1)/2;
        for(i=2;i<=fenzi;i++)while(fenzi%i==0&&fenmu%i==0){
            fenzi/=i;
            fenmu/=i;
        }
        printf("%d/%d\n",fenmu-fenzi,fenmu);
    }
    return 0;
}
