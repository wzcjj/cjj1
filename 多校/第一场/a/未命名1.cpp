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
set<int>b[10005];
vector<int>c[10005];
int main(){
    int i,j,m,n;
    for(i=1;i<=10000;i++){
        for(j=1;j*i<=10000;j++){
            c[i*j].push_back(i);
        }
    }
    while(cin>>n){
        int ans=0;
        for(i=1;i<=10000;i++){
            b[i].clear();
            b[i].insert(0);
            b[i].insert(n+1);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]].insert(i);
        }
        for(i=1;i<=n;i++){
            int r=100001,l=0;
            for(j=0;j<c[a[i]].size();j++){
                set<int>::iterator it=b[c[a[i]][j]].upper_bound(i),it1;
                if(r>(*it))r=*it;
                it1=it;
                it1--;
                if((*it1)==i)it1--;
                if(l<(*it1))l=*it1;
            }
            ans=(ans+((r)-i)*(i-(l)))%P;
        }
        cout<<ans<<endl;
    }
    return 0;
}
        
