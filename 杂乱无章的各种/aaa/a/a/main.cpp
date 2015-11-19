#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
    srand(unsigned (time(0)));
    double a[10];
    memset(a,0,sizeof(a));
    long long sum=0;
    for(int I=1;I<=100;I++){
        int t = rand()%(int)pow(10,6);
        double now = 1;
        double po = (rand()%1000+1)/1000.0+1;
        while(now<t){
            long long s = (int) now;
            int j=0;
            while(s){
                j=s%10;
                s/=10;
            }
            a[j]++;
            sum++;
            now*=po;
        }
    }
    for(int i=1;i<=9;i++)cout<<a[i]/sum<<endl;
    return 0;
}