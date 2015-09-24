//
//  main.cpp
//  fenxi
//
//  Created by wzcjj on 15/9/11.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 50
int a[maxn][2];
char filename[10000][20];
bool fl[maxn];
long long va[maxn],co[maxn];
int fenbu[maxn][105][105],fenbu1[maxn][105][105];
int pingjun[105][105];
int sum[105][105],sum1[105][105];
float ma_ea,mi_ea,ma_we,mi_we;
float ea,we;
int main(int argc, const char * argv[]) {
    memset(a,0,sizeof(a));
    memset(va, 0, sizeof(va));
    memset(sum,0,sizeof(sum));
    memset(pingjun, 0, sizeof(pingjun));
    int con=0;
    freopen("filename.txt","r",stdin);
    ma_ea=ma_we=0;
    mi_ea=mi_we=200;
    int n=0,i;
    while(scanf("%s",filename[n])!=EOF)n++;
    for(int j=0;j<n;j++){
        freopen(filename[j],"r",stdin);
        char s[1000];
        scanf("%s",s);
        int flag=0,lh=23,lasth=25;
        while(scanf("%s",s)!=EOF){
            int h,m,sec,status,v,ang;
            int n=strlen(s);
            int d=atoi(s+n-2)-18;
            scanf("%d:%d:%d,%f,%f,%d,%d,%d,",&h,&m,&sec,&ea,&we,&status,&v,&ang);
            //cout<<ea<<' '<<we<<endl;
            //cout<<ma_ea<<' '<<mi_ea<<' '<<ma_we<<' '<<mi_we<<endl;
            if(status>1)continue;
            if(ea<114.35)ma_ea=max(ma_ea,ea);else continue;
            if(ea>113.76)mi_ea=min(mi_ea,ea);else continue;
            if(we<22.65)ma_we=max(ma_we,we);else continue;
            if(we>22.45)mi_we=min(mi_we,we);else continue;
            
            if(h==17&&status==0){
                con++;
                fenbu[d][int((ea-113.75)/0.006)][int((we-22.45)/0.002)]++;
                co[d]++;
                pingjun[int((ea-113.75)/0.006)][int((we-22.45)/0.002)]+=v;
            }
            else if(h==18&&status==0){
                fenbu1[d][int((ea-113.75)/0.006)][int((we-22.45)/0.002)]++;
            }
            if(h!=lasth){
                fl[h]=0;
                if(fl[lasth]==0)a[lasth][0]++;
            }
            if(status&&!flag){
                a[h][1]++;
                lh=h;
                fl[h]=1;
            }
            lasth=h;
            flag=status;
            va[h]+=v;
            //co[h]++;
        }
    }
    freopen("a.out","w",stdout);
    printf("%d\n",con);
    for(i=0;i<=8;i++){
        //printf("%lld\n",co[i]);
        for(int k=0;k<100;k++){
            for(int l=0;l<100;l++){
                sum[k][l]+=fenbu[i][k][l];
                sum1[k][l]+=fenbu1[i][k][l];
            }//if(l!=99)printf("%d ",fenbu[i][k][l]);else printf("%d;",fenbu[i][k][l]);
            //printf("\n");
        }
    }
    for(int k=0;k<100;k++){
        for(int l=0;l<100;l++)if(l<99)if(sum[k][l]!=0)printf("%d ",(sum1[k][l]-sum[k][l])/sum[k][l]);else printf("0 ");else if(sum[k][l]!=0)printf("%d;\n",(sum1[k][l]-sum[k][l])/sum[k][l]);else printf("0;\n");
    }
    fclose(stdout);
    return 0;
}
