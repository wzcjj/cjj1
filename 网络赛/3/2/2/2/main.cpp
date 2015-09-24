//
//  main.cpp
//  2
//
//  Created by wzcjj on 15/9/20.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <list>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 10050
#define NIL
typedef long long LL;
typedef list<char>::iterator IT;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int n;
char str[MAX];
char b[MAX];
list<char> lc;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--) {
        cin >> n;
        scanf("%s",str);
        lc.clear();
        IT it,tt;
        IT clp,clp2,clp1;
        IT tmp1,tmp2;
        int cnt = 0,cnt2 = 0;
        int mode = 0;
        int cop = 0;
        it = lc.begin();
        int len = strlen(str);
        for(int i = 0;i < len;i++) {
            switch(str[i]) {
                case 'L':
                    if(it != lc.begin()) {
                        if(cop) cnt--;
                        it--;
                    }
                    break;
                case 'R':
                    if(it != lc.end()) {
                        if(cop) cnt++;
                        it++;
                    }
                    break;
                case 'C':
                    if(!cop) {
                        cnt = 0;
                        clp = it;
                        cop = 1;
                    }
                    else {
                        int ii = 0;
                        IT q = (cnt > 0) ? clp : it;
                        IT q2 = (cnt <= 0) ? clp : it;
                        for(;q != q2;q++) {
                            b[ii++] = *q;
                        }
                        cnt2 = ii;
                    }
                    break;
                case 'D':
                    if(!cop) {
                        if(it != lc.end())
                            it = lc.erase(it);
                    }
                    else {
                        if(cnt > 0) {
                            it = lc.erase(clp,it);
                            cop = 0;
                        }
                        else if(cnt < 0) {
                            it = lc.erase(it,clp);
                            cop = 0;
                        }
                    }
                    break;
                case 'B':
                    tt = it;
                    if(tt != lc.begin()) {
                        tt--;
                        lc.erase(tt);
                    }
                    if(cop) cop = 0;
                    break;
                case 'V':
                    if(!mode && abs(cnt2) + lc.size() <= n) {
                        for(int ii = 0;ii < cnt2;ii++) {
                            lc.insert(it,b[ii]);
                        }
                    }
                    else if(mode) {
                        IT tmptmp = it;
                        int cc = 0;
                        for(;tmptmp != lc.end();tmptmp++) {
                            cc++;
                        }
                        if(lc.size()-cc+cnt2 <= n) {
                            for(int ii = 1;ii <= cnt2 && it != lc.end();ii++) {
                                it = lc.erase(it);
                            }
                            for(int ii = 0;ii < cnt2;ii++) {
                                lc.insert(it,b[ii]);
                            }
                        }
                    }
                    if(cop) cop = 0;
                    break;
                case 'S':
                    mode = mode ? 0 : 1;
                    if(cop) cop = 0;
                    break;
                default :
                    if(!mode) {
                        if(lc.size() < n)
                            lc.insert(it,str[i]);
                    }
                    else {
                        (*it) = str[i];
                        it++;
                    }
                    if(cop) cop = 0;
            }
        }
        if(!lc.empty()) {
            for(list<char>::iterator tmp = lc.begin();tmp != lc.end();tmp++) {
                printf("%c",*tmp);
            }printf("\n");
        }
        else {
            puts("NOTHING");
        }
        //puts("");
    }
    return 0;
}