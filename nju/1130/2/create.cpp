#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    freopen("a.in","w",stdout);
    srand(unsigned(time(0)));
    for(int k=1;k<=10;k++){
        for(int i=1;i<5;i++){
            for(int j=1;j<=5;j++)cout<<rand()%2;
            cout<<' ';}
        for(int j=1;j<=5;j++)cout<<rand()%2;
        cout<<endl;
        for(int j=1;j<=5;j++)cout<<rand()%10;
        cout<<endl;}
    return 0;
}
