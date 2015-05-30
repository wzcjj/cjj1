#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char c1,c2;
    while(scanf("%c %c\n",&c1,&c2)!=EOF)
    {
        if(c1=='P'&&c2=='P'||c1=='R'&&c2=='R'||c1=='S'&&c2=='S')printf("Nobody wins.\n");
        if(c1=='P'&&c2=='R')printf("User 1 wins(Paper covers rock).\n");
        if(c1=='P'&&c2=='S')printf("User 2 wins(Scissors cut paper).\n");
        if(c1=='R'&&c2=='P')printf("User 2 wins(Paper covers rock).\n");
        if(c1=='R'&&c2=='S')printf("User 1 wins(Rock breaks scissors).\n");
        if(c1=='S'&&c2=='P')printf("User 1 wins(Scissors cut paper).\n");
        if(c1=='S'&&c2=='R')printf("User 2 wins(Rock breaks scissors).\n");
    }
    return 0;
}
