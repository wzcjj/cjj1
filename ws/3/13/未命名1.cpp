#include<cstdio>
#include<ctime>
#include<cstdlib>
int main()
{
    srand((unsigned)time(NULL));
    double sd=0,oc=0;
    int i,j;
    for(i=1;i<=10000;i++)
    {
        j=rand()%3;
        if(j)sd+=1;
        else oc+=1;
    }
    printf("original choice: %lf\nswitching doors: %lf",oc,sd);
    scanf("%d",&i);
    return 0;
}
