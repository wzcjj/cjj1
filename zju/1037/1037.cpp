#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int N,i,m,n;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>m>>n;
        printf("Scenario #%d:\n",i);
        cout<<m*n;
        if(m%2==1&&n%2==1)cout<<".41"<<endl;
        else cout<<".00"<<endl;
        cout<<endl;
    }
    return 0;
}
