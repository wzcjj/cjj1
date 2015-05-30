#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int a[60];
    int i,j,m,n;
    n=0;
    while(scanf("%d",&a[n++])!=EOF);
    n--;
    sort(a,a+n,cmp);
    printf("N    Count\n");
    printf("%d    ",a[0]);
    m=1;
    for(i=1;i<n;i++)if(a[i]==a[i-1])m++;
    else
    {
        printf("%d\n%d    ",m,a[i]);
        m=1;
    }
    printf("%d\n",m);
    system("pause");
    return 0;
}
    
        
    
