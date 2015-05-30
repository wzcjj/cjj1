#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
long long n,m;
bool vst[10];
int main()
{
    long long cnit = 0;
    while(cin >> n >> m) {
        for(int  i = 0;i < 10;i++) vst[i] = false;
        printf("Case %d: ",++cnit);
        for(int i = 0;i < m;i++) {
            long long tmp;cin >> tmp;
            vst[tmp] = true;
        }
        long long t = n,cnt = 1;
        while(t) {t/=10;cnt*=10;}
        cnt*=10;
        long long temp = 0;
        bool flag;
        for(int i = 1;i <= (vst[0]?cnt:100000000);i++) {
            temp += n;
            long long tttt = temp;
            flag = true;
            while(tttt) {
                if(vst[tttt%10]) {flag = false;break;}
                tttt /= 10;   
            }
            if(flag) break;
        }
        if(flag) printf("%d\n",temp);
        else printf("-1\n");
    }
    return 0;
}
