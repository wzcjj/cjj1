#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int> a;
int main(int argc,char* argv[]){
    int i,j,m,n;
    srand(unsigned(time(0)));
    if(argc==1){
        n=0;
        while(scanf("%d",&i)!=EOF)n++;
        cout<<n<<endl;
    }
    else if(argc==2&&strcmp(argv[1],"test")==0){
        
        n=0;
        while(scanf("%d",&i)!=EOF){
            n++;
            a.push_back(i);
        }
        for(i=0;i<n;i++){
            j=rand()%(n-i)+i;
            int t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
        for(i=0;i<n;i++){
            printf("%d",a[i]);
            if(i<n-1)printf(" ");
            else printf("\n");
        }
    }else {
        cout<<"wrong input"<<endl;
        cout<<argc<<endl;
        for(i=0;i<argc;i++)cout<<argv[i]<<endl;
    }
    system("pause");
    return 0;
}
