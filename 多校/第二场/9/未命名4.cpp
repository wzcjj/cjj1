#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int main(){
    int i,j,m,n,x,y;
    while(cin>>n){
        if(n>=48){
            if(n%2==0){
                for(i=1;i<=24;i++){
                    printf("%d / %d\n",2*i-1,2*i);
                }
                for(i=25;i<=n/2;i++)printf("%d - %d\n",2*i-1,2*i);
                printf("%d + %d\n",n+1,n+2);
                for(i=n/2+2;i<n;i++)printf("%d + %d\n",i+n/2+1,i+n-1);
            }
            else{
                printf("1 + 2\n%d / 3\n",n+1);
                for(i=3;i<=24;i++)printf("%d / %d\n",2*i-2,2*i-1);
                for(i=25;i<=n/2+1;i++)printf("%d - %d\n",2*i-2,2*i-1);
                printf("%d + %d\n",n+2,n+3);
                for(i=n/2+3;i<n;i++)printf("%d + %d\n",i-n/2-3+n+4,n+i-1);
            }
        }
        else if(n>=25){
            if(n%2==0){
                printf("1 + 2\n%d / 3\n",n+1);
                if(n!=46)for(i=3;i<=n-24+2;i++)printf("%d / %d\n",2*i-1,2*i);
                else for(i=3;i<=n-24+1;i++)printf("%d / %d\n",2*i-1,2*i);
                for(i=n-24+3;i<=n/2;i++)printf("%d - %d\n",2*i-1,2*i);
                printf("%d - %d\n",4,n+2);
                for(i=n/2+2;i<n;i++)printf("%d - %d\n",n+i-1,i-n/2-2+n+3);
            }
            else{
                for(i=1;i<=n-24;i++){
                    printf("%d / %d\n",2*i-1,2*i);
                }
                for(i=n-24+1;i<=n/2;i++)printf("%d - %d\n",2*i-1,2*i);
                printf("%d - %d\n",n,n+1);
                for(i=n/2+2;i<n;i++)printf("%d - %d\n",n+i-1,i-n/2-2+n+2);
            }
        } 
        else if(n <= 3){
            puts("-1");
        }
        else if(n == 4){
            puts("1 * 2\n5 + 3\n6 + 4");
        }
        else if(n == 5) {
            puts("1 * 2\n3 * 6\n7 - 4\n8 / 5");
        }
        else if(n == 6) {
            puts("1 * 2\n3 + 4\n5 - 6\n7 - 8\n10 - 9");
        }
        else if(n == 7) {
            puts("1 + 2\n3 + 8\n9 / 4\n10 + 5\n11 + 6\n12 + 7");
        }
        else if(n == 8) {
            puts("1 + 2\n9 + 3\n4 - 5\n11 * 6\n12 * 7\n13 * 8\n14 + 10");//10 24 11 0
        }
        else if(n == 9) {
            puts("1 + 2\n3 + 10\n11 / 4\n5 - 12\n6 + 13\n7 + 14\n8 + 15\n16 - 9");
        }
        else if(n == 10) {
            puts("1 + 2\n3 + 4\n11 / 5\n12 / 6\n7 + 13\n14 * 15\n8 - 9\n17 * 10\n18 + 16");
        }
        else if(n == 11) {
            puts("1 + 2\n12 / 3\n4 + 5\n13 + 14\n15 + 6\n16 + 7\n17 + 8\n18 - 9\n19 - 10\n20 - 11");
        }
        else if(n == 12) {
            puts("1 + 2\n13 / 3\n14 * 4\n15 + 5\n16 + 6\n17 + 7\n18 + 8\n19 - 9\n20 - 10\n21 - 11\n22 - 12");
        }
        else if(n == 13) {
            puts("1 + 2");
            for(int i = 3;i <= 11;i++) {
                printf("%d + %d\n",i,i+11);
            }
            puts("23 / 12");// 24 11
            puts("24 + 13");
        }
        else if(n == 14) {
            puts("1 + 2");
            for(int i = 3;i <= 10;i++) {
                printf("%d + %d\n",i,i+12);
            }
            puts("23 / 11");// 24 10
            puts("24 + 12\n25 + 13\n26 - 14");
        }
        else if(n == 15) {
            puts("1 + 2");
            for(int i = 3;i <= 9;i++) {
                printf("%d + %d\n",i,i+13);
            }
            puts("23 / 10"); // 24 9
            puts("24 + 11\n25 + 12\n26 + 13\n27 - 14\n28 - 15");
        }
        else if(n == 16) {
            puts("1 + 2\n3 + 17\n4 + 18\n5 + 19\n6 + 20\n7 + 21\n8 + 22\n23 / 9\n24 + 10");
            puts("25 + 11\n26 + 12\n27 + 13\n28 - 14\n29 - 15\n30 - 16");
        }
        
        else if(n==24) {
            int tmp = n - 24;
            int cnt = n+1;
            for(int i = 2*tmp+1;i+2 <= n;i+=2) {
                printf("%d - %d\n",i,i+1);
                cnt++;
            }
            int pos = n+1;
            if((n & 1) == 0) {
                printf("%d * %d\n",n-1,n+1);
                cnt++;
                pos++;
            }
            for(int i = 1;i <= tmp;i++) {
                printf("%d / %d\n",i,i+tmp);
                cnt++;
            }
            printf("%d - %d\n",n,pos);
            for(int i = 1;i < cnt-pos;i++) {
                printf("%d - %d\n",cnt+i-1,pos+i);
            }
        }
        else if (n >= 17 && n <= 23){
            int tmp = 24 - n;
            int cnt = n+1;
            for(int i = 2*tmp + 1;i < n-1;i+=2) {
                printf("%d - %d\n",i,i+1);
                cnt ++;
            }
            for(int i = 1;i <= 2*tmp;i += 2) {
                printf("%d / %d\n",i,i+1);
                cnt ++;
            }
            int pos = n + 1;
            if((n & 1) == 0) {printf("%d * %d\n",n-1,n+1);cnt++;pos = n + 2;}
            printf("%d + %d\n",n,pos);
            for(int i = 1;i < cnt-pos;i++) {
                printf("%d + %d\n",cnt-1+i,pos+i);
            }
        }
    }
    return 0;
}
                
