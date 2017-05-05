//
//  main.cpp
//  1
//
//  Created by wzcjj on 16/9/24.
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
struct B {
    char str[105];
    int next[55];
    bool isbook;
    bool isc;
    friend bool operator == (B b1, B b2) {
        if(strcmp(b1.str,b2.str) == 0) return true;
        return false;
    }
};
//&& ((b1.isc && b2.isc) || (b1.isbook && b2.isbook))
B b[1555];
int cntb;
bool cmp(pair<char*,int> p1,pair<char*,int> p2) {
    return strcmp(p1.AA,p2.AA) < 0;
}
void dfs(int x,int ind,bool isbook = false) {
    for(int i = 0;i < ind;i++) printf(" ");
    printf("%s\n",b[x].str);
    if(isbook) return;
    vector<pair<char*,int> > v;
    v.clear();
    for(int i = 1;i <= b[x].next[0];i++) {
        int son = b[x].next[i];
        if(b[son].next[0] != 0) v.push_back(MP(b[son].str,son));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < v.size();i++)
        dfs(v[i].BB,ind+4);
    v.clear();
    for(int i = 1;i <= b[x].next[0];i++) {
        int son = b[x].next[i];
        if(b[son].isbook) v.push_back(MP(b[son].str,son));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < v.size();i++)
        dfs(v[i].BB,ind+4,true);
}
void work() {
    int x = 0;
    vector<pair<char*,int> > v;
    v.clear();
    for(int i = 1;i <= b[x].next[0];i++) {
        int son = b[x].next[i];
        if(b[son].next[0] != 0) v.push_back(MP(b[son].str,son));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < v.size();i++)
        dfs(v[i].BB,0);
    v.clear();
    for(int i = 1;i <= b[x].next[0];i++) {
        int son = b[x].next[i];
        if(b[son].isbook) v.push_back(MP(b[son].str,son));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < v.size();i++)
        dfs(v[i].BB,0,true);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cc = 0;
    while(1) {
        for(int i = 0;i <= 1500;i++) {
            strcpy(b[i].str,"");
            b[i].next[0] = 0;
            b[i].isbook = false;
        }
        char tmp[105] = "";
        cntb = 0;
        while(1) {
            gets(tmp);
            if(tmp[0] == '0' || strlen(tmp) == 1) break;
            int bnow = 0;
            int i = 0;
            bool fst = true;
            while(fst || tmp[i] == '/') {
                char str[105] = "";
                if(!fst) i++;
                fst = false;
                int now = 0;
                for(;tmp[i] != '/' && tmp[i] != '\0';) {
                    str[now++] = tmp[i++];
                }
                str[now] = '\0';
                
                for(int i = 1;i <= b[bnow].next[0]+1;i++) {
                    if(i == b[bnow].next[0] + 1) {
                        b[bnow].next[0]++;cntb++;
                        b[bnow].next[i] = cntb;
                        strcpy(b[cntb].str,str);
                        b[cntb].next[0] = 0;bnow = cntb;
                        break;
                    }
                    int son = b[bnow].next[i];
                    if(strcmp(b[son].str,str) == 0) {
                        bnow = son;break;
                    }
                }
            }
            b[bnow].isbook = true;
        }
        printf("Case %d:\n",++cc);
        work();
    }
    return 0;
}
/*
 B/A
 B/A
 B/B
 0
 A1/B1/B32/B7
 A1/B/B2/B4/C5
 A1/B1/B2/B6/C5
 A1/B1/B2/B5
 A1/B3/B2/B1
 A1/B3/B2
 A3/B1
 A0/A1
 0
 */