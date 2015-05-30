#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
set< int > a;
set< int >::iterator it;
int main(){
    int i,j,t;
    a.clear();
    i=1;
    while(scanf("%d",&t)!=EOF){
        a.insert(t);
        it=a.find(i);
        if(it!=a.end()){
            for(j=i;it!=a.end();j++)it=a.find(j);
            j--;
            for(int k=i;k<j-1;k++){
                printf("%d,",k);
                a.erase(k);
            }
            printf("%d\n",j-1);
            a.erase(j-1);
            i=j;
        }
    }
    return 0;
}
