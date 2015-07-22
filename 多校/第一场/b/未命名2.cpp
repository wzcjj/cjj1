#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#define P 1000000007
using namespace std;
int a[100005];
multiset<int> s;
int main(){
    int i,j,N,m,n;
    cin>>N;
    for(int I=1;I<=N;I++){
        cin>>n>>m;
        s.clear();
        long long ans=0;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        int j=1;
        for(i=1;i<=n;i++){
            s.insert(a[i]);
            while(*(s.rbegin())-*(s.begin())>=m){
                s.erase(s.find(a[j]));
                j++;
            }
            ans+=i-j+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
