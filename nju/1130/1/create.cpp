#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    freopen("a.in","w",stdout);
    srand(unsigned(time(0)));
    int i=0;
    while(i==0)i=rand()%1001-1000;
    cout<<i<<' ';
    i=0;
    while(i==0)i=rand()%1001-1000;
    cout<<i<<' ';
    i=0;
    while(i==0)i=rand()%1001-1000;
    cout<<i<<' ';
    i=0;
    while(i==0)i=rand()%1001-1000;
    cout<<i<<endl;
    return 0;
}
