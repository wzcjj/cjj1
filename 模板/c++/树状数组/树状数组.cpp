//
//  main.cpp
//  1
//
//  Created by wzcjj on 15/7/30.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 10005
#define P 1000000007
#define INF 2100000000
using namespace std;

class BIT{
public:
	int bit[maxn],size;
	BIT(int size){
		this->size = size;
		memset(bit,0,sizeof(bit));
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int v){
		while(x<=size){
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int query(int x){
		int sum=0;
		while(x>0){
			sum+=bit[x];
			x-=lowbit(x);
		}
		return sum;
	}
};
int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        BIT bi(n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)bi.add(i,a[i]);
    }
    return 0;
}
