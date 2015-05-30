#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    long long v;
    int i;
}b[1000005];
int a[1000005];
bool cmp(node x,node y){
    return x.v<y.v;
}
int main(){
    int i,j,m,n,T,I;
    scanf("%d",&T);
    for(I=1;I<=T;I++){
        cin>>n>>m;
        b[0].v=0;
        b[0].i=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i].v=b[i-1].v+a[i];
            if(!(i^((i>>1)<<1)))a[i]=-a[i];
            b[i].i=i;
        }
        sort(b+1,b+1+n,cmp);
        j=1;
        int z=0;
        for(i=1;i<=n;i++){
            while(abs(b[j].v-b[i].v)<abs(m))j++;
            if(abs(b[j].v-b[i].v)==abs(m)){
                if(b[i].i<=b[j].i){
                    if(b[i].i%2){
                        if(-b[j].v+b[i].v==m){
                            printf("Case #%d: Yes.\n",I);
                            z=1;
                            break;
                        }
                    }
                    else{
                        if(b[j].v-b[i].v==m){
                            printf("Case #%d: Yes.\n",I);
                            z=1;
                            break;
                        }
                    }
                }
                else{
                    if(b[i].i%2){
                        if(b[j].v-b[i].v==m){
                            printf("Case #%d: Yes.\n",I);
                            z=1;
                            break;
                        }
                    }
                    else{
                        if(-b[j].v+b[i].v==m){
                            printf("Case #%d: Yes.\n",I);
                            z=1;
                            break;
                        }
                    }
                }
            }
        }
            if(z==0)printf("Case #%d: No.\n",I);
    }
    return 0;
}
        
                
