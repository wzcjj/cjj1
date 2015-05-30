#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int i,j,m,n;
    cin>>n;
    while(n)
    {
        printf("Number %d is",n);
        int n1=n;
        int z=0;
        for(i=2;i<=16;i++)
        {
            m=0;
            n=n1;
            while(n)
            {
                a[++m]=n%i;
                n/=i;
            }
            int z1=0;
            for(j=1;j<=m/2;j++)if(a[j]!=a[m-j+1])z1=1;
            if(z1==0)
            {
                if(z==0)cout<<" palindrom in basis";
                cout<<" "<<i;
                z=1;
            }
        }
        if(z==0)cout<<" not a palindrom";
        cout<<endl;
        cin>>n;
    }
    return 0;
}
