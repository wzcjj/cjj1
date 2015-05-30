#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std; 
vector<int> a;
bool prime[105];
unsigned long long number,answer;
unsigned long long m;
void dfs(int p,unsigned long long num,unsigned long long ans)
{
    if(ans>m)return;
    if(num>number){
        number=num;
        answer=ans;
    }
    else if(num==number&&ans<answer)answer=ans;
    for(unsigned long long i=1;i<63;i++){
        if(ans>m/a[p])break;
        ans*=a[p];
        dfs(p+1,num*(i+1),ans);
    }
}
int main()
{
    int i,j,n;
    for(i=2;i<=100;i++)prime[i]=true;
    for(i=2;i<=100;i++)if(prime[i])
    {
        a.push_back(i);
        for(j=2;j<=100/i;j++)prime[i*j]=false;
    }
    cin>>n;
    for(int I=1;I<=n;I++)
    {
        number=answer=0;
        cin>>m;
        dfs(0,1,1);
        cout<<answer<<' '<<number<<endl;
    }
    system("pause");
    return 0;
}
