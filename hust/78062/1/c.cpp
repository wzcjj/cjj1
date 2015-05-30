#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    char b[]="desu";
    bool f;
    int T,t1,t2;
    char a[200];
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        scanf("%s",a);
        f=true;
        t1=strlen(a)-strlen(b);
        for (int j=0;j<strlen(b);j++)
        {
            if (a[t1+j]!=b[j]) {
                f=false;
                break;
            }
        }
        if (f)
        {
            a[t1]='\0';
        } 
        printf("Case #%d: %s%s\n",i+1,a,"nanodesu");
    }
    return 0;
}
