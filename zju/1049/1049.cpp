#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    float pi=3.14159265358979323846;
    int i,j,N;
    float m,n;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>m>>n;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<(int)ceil((m*m+n*n)*pi/100)<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
    return 0;
}
