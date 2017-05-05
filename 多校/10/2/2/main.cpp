//
//  main.cpp
//  2
//
//  Created by wzcjj on 16/8/18.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
#define PI 3.14159265
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
const double pi = 3.14159265358979323846;
const double eps = 0.0043045 + 0.00298058;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    double ans = (1-pi/4) - (1 - pi/4)/4 - 2*eps;
    ans *= 2;
    while(t--) {
        double n;cin >> n;
        double ret = n * n * ans;
        cout << fixed << setprecision(2) << ret << endl;
    }
    return 0;
}