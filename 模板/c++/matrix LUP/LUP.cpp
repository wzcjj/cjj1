//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/10/25.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
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
#define maxn 205
#define INF 2100000000
#define eps 0.000001
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;
#define DATA_TYPE double
class Matrix{
public:
    DATA_TYPE L[maxn][maxn], U[maxn][maxn], PA[maxn][maxn], A[maxn][maxn], temp[maxn][maxn], INV[maxn][maxn], Y[maxn], B[maxn], X[maxn];
    int size, Pi[maxn], sign;
    
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
Matrix a;
int main(int argc, const char * argv[]) {
    int i,j,n,N;
    N=1;
    while (scanf("%d",&n)!=EOF) {
        a.scan(n);
        a.inverse();
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                //cout<<a.INV[i][j];
                cout<<((a.INV[i][j]>0)?(long long)(a.INV[i][j]+0.1):(long long)(a.INV[i][j]-0.1));
                if(j<n)cout<<' ';
                else cout<<endl;
            }
        }
    }
    return 0;
}
