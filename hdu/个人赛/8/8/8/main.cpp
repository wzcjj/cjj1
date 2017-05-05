//
//  main.cpp
//  7
//
//  Created by wzcjj on 15/12/26.
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

#define MP make_pair
#define AA first
#define BB second
using namespace std;

struct C{
    char* s;
    int c;
    friend bool operator <(C c1,C c2) {
        if(c1.c != c2.c)
            return(c1.c > c2.c);
        else
            return strcmp(c1.s,c2.s) <= 0;
    }
}wo[1000005];
int TOP;
struct Node {
    int cnt;
    Node* next[26];
};
struct Trie {
    static const int MAXN = 26;
    
    int top;
    Node* Root;
    Trie() : top(0) {Root = createNode();}
    void init() {
        top = 0;
        Root = createNode();
    }
    
    Node* createNode() {
        Node* tmp = new Node;
        tmp -> cnt = 0;
        for(int i = 0;i < MAXN;i++) tmp->next[i] = NULL;
        return tmp;
    }
    
    void Insert(char* str,Node* root) {
        Node* tmp = root;
        int i = 0,k;
        while(str[i]) {
            k = str[i] - 'a';
            if(tmp->next[k] == NULL) {
                tmp->next[k] = createNode();
            }
            if(i == strlen(str) - 1) tmp->next[k]->cnt++;
            tmp = tmp->next[k];
            i++;
        }
    }
    
    int Search(char* str,Node* root) {
        if(root == NULL) return 0;
        Node* tmp = root;
        int i = 0,k;
        while(str[i]) {
            k = str[i] - 'a';
            if(!tmp->next[k]) return 0;
            tmp = tmp->next[k];
            i++;
        }
        return tmp->cnt;
    }
};
Trie tr;
Trie t2;
char strin[100];
char e[100] = "</oldwords>";
char e2[100] = "</article>";
bool isWord(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
void work(char str[]) {
    int len = strlen(str);
    char w[105];
    memset(w,0,sizeof w);
    int top;
    for(int i = 0;i < len;i++) {
        top = 0;
        while(!isWord(str[i])) ++i;
        while(isWord(str[i]) && i < len){
            w[top++] = tolower(str[i++]);
        }
        w[top] = '\0';
        if(!tr.Search(w,tr.Root)) {
            t2.Insert(w,t2.Root);
        }
    }
}
void dfs(Node* x,char s[]) {
    if(x->cnt != 0) {
        wo[TOP].s = new char[101];
        strcpy(wo[TOP].s,s);
        wo[TOP++].c = x->cnt;
    }
    int len = strlen(s);
    for(int i = 0;i < 26;i++) {
        if(x->next[i]) {
            s[len] = 'a' + i;
            s[len+1] = '\0';
            dfs(x->next[i],s);
        }
    }
    s[len] = '\0';
}
int main()
{
    int t;cin >> t;
    while(t--) {
        tr.init();
        t2.init();
        TOP = 0;
        scanf("%*s");
        while(1) {
            scanf("%s",strin);
            if(strcmp(strin,e)==0) break;
            int len = strlen(strin);
            for(int i = 0;i < len;i++) strin[i] = tolower(strin[i]);
            tr.Insert(strin,tr.Root);
        }
        scanf("%*s");
        while(1) {
            scanf("%s",strin);
            if(strcmp(strin,e2) == 0) break;
            work(strin);
        }
        char s[105] = "";
        Node* tmp = t2.Root;
        dfs(tmp,s);
        sort(wo,wo+TOP);
        for(int i = 0;i < min(10,TOP);i++) {
            puts(wo[i].s);
        }
        puts("");
    }
    return 0;
}
