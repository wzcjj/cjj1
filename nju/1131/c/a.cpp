#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(int argc,char* argv[]){
    int i,j,m,n;
    srand(unsigned(time(0)));
    if(argc==1){
        cin>>n;
        cout<<n<<endl;
    }
    else if(argc==2&&strcmp(argv[1],"test")==0){
        int a[10];
        memset(a,0,sizeof(a));
        cin>>n;
        for(i=1;i<=3*n;i++)a[rand()%6+1]++;
        for(i=1;i<=6;i++)printf("the number %d: %d\n",i,a[i]);
    }else {
        cout<<"wrong input"<<endl;
        cout<<argc<<endl;
        for(i=0;i<argc;i++)cout<<argv[i]<<endl;
    }
    system("pause");
    return 0;
}
