//
//  main.cpp
//  matrix
//
//  Created by wzcjj on 2016/12/1.
//  Copyright © 2016年 wzcjj. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 15
#define P 1000000007
#define INF 1000000000
#define DATA_TYPE long double
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

class Matrix{
public:
    DATA_TYPE L[maxn][maxn], U[maxn][maxn], PA[maxn][maxn], A[maxn][maxn], temp[maxn][maxn], INV[maxn][maxn], Y[maxn], B[maxn], X[maxn];
    int size, Pi[maxn], sign;
    
    void init1(){
        size++;
        DATA_TYPE x = 1;
        for(int i = 1; i <= size; i ++){
            DATA_TYPE sum=0,y=1;
            for(int j = 1; j <= size; j ++){
                A[i][j]=y;
                sum+=A[i][j];
                y*=x;
            }
            B[i]=sum;
            x+=0.2;
        }
    }
    
    void init2(){
        size++;
        for(int i = 1; i <= size; i ++){
            DATA_TYPE sum=0;
            for(int j = 1; j <= size; j ++){
                A[i][j]=1.0/(i+j-1);
                sum+=A[i][j];
            }
            B[i]=sum;
        }
    }
    
    void scan(int size){
        sign = 0;
        this->size = size;
        for(int i = 1; i <= size; i ++){
            for(int j = 1; j <= size; j ++){
                cin >> A[i][j];
            }
        }
    }
    
    void LUP(){
        for(int i = 1; i <= size; i ++){
            for(int j = 1; j <= size; j ++){
                PA[i][j] = A[i][j];
            }
        }
        for(int i = 1; i <= size; i ++)Pi[i] = i;
        for(int i = 1; i <= size; i ++){
            DATA_TYPE tem = 0;
            int j1 = -1;
            for(int j = i; j <= size; j ++){
                //if(PA[j][i].abs() > tem){
                //  tem = PA[j][i].abs();
                if(fabs(PA[j][i]) > tem){
                    tem = fabs(PA[j][i]);
                    j1 = j;
                }
            }
            swap1(i, j1);
            L[i][i] = 1;
            U[i][i] = PA[i][i];
            for(int j = i + 1; j <= size; j ++){
                PA[j][i] = PA[j][i] / PA[i][i];
                for(int k = i + 1; k <= size; k ++){
                    PA[j][k] = PA[j][k] - PA[j][i] * PA[i][k];
                }
            }
            for(int j = 1; j <= size; j ++){
                for(int k = 1; k <= size; k ++){
                    if(k >= j){
                        U[j][k] = PA[j][k];
                    }
                    else {
                        L[j][k] = PA[j][k];
                    }
                }
            }
        }
    }
    
    void swap1(int i,int j){
        if(i == j)return;
        for(int k = 1; k <= size; k ++){
            DATA_TYPE t = PA[i][k];
            PA[i][k] = PA[j][k];
            PA[j][k] = t;
        }
        int t = Pi[i];
        Pi[i] = Pi[j];
        Pi[j] = t;
        sign = !sign;
    }
    
    void solve(){
        for(int i = 1; i <= size; i ++){
            Y[i] = B[Pi[i]];
            for(int j = 1; j < i; j ++){
                Y[i] = Y[i] - (L[i][j] * Y[j]);
            }
        }
        for(int i = size; i >= 1; i --){
            X[i] = Y[i];
            for(int j = i + 1; j <= size; j ++){
                X[i] = X[i] - (U[i][j] * X[j]);
            }
            X[i] = X[i] / U[i][i];
        }
    }
    
    void inverse(){
        LUP();
        for(int i = 1; i <= size; i ++){
            B[i] = 0;
        }
        for(int i = 1; i <= size; i ++){
            B[i] = 1;
            B[i - 1] = 0;
            solve();
            for(int j = 1; j <= size; j ++){
                INV[j][i] = X[j];
            }
        }
    }
};
Matrix A,B;
int main(int argc, const char * argv[]) {
    int i,j,m,n=6,N=1;
    //cin>>N;
    while (N--) {
        scanf("%d",&A.size);
        scanf("%d",&B.size);
        A.init1();B.init2();
        A.A[2][2]+=1e-12;A.A[6][6]+=1e-12;//1.3
        B.A[2][2]+=1e-7;B.A[6][6]+=1e-7;//1.4
        B.B[6]+=1e-4;//1.4
        A.LUP();  B.LUP();
        A.solve();B.solve();
        for(i=1;i<=A.size;i++)cout<<A.X[i]<<' ';cout<<endl;
        for(i=1;i<=B.size;i++)cout<<B.X[i]<<' ';cout<<endl;
        long double maxx=0;
        for(i=1;i<=n;i++){
            if(maxx<fabs(A.X[i]-1))maxx=fabs(A.X[i]-1);
        }
        cout<<maxx<<endl;
        maxx=0;
        for(i=1;i<=n;i++){
            if(maxx<fabs(B.X[i]-1))maxx=fabs(B.X[i]-1);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
