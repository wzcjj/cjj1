//
//  main.cpp
//  trie
//
//  Created by wzcjj on 15/8/3.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#define range 26
#define maxlen 20
#define maxn 10
using namespace std;

template <typename T = int > class Trie{
    const char base = 'a';
    struct node{
        node * son[range];
        int num=0,sons=0;
        multiset<T> info;
        node(){
            for (int i=0; i<range; i++) {
                son[i]=nullptr;
            }
        }
        ~node(){
            for (int i=0; i<range; i++) if(son[i]!=nullptr) delete son[i];
        }
    };
    node * root = nullptr;
    public: Trie (){
        root = new node;
    }
    void insert(char * s,int size,T info){
        node * t = root;
        for (int i=0; i<size; i++) {
            if (t->son[s[i]-base] == nullptr) {
                t->son[s[i]-base] = new node;
            }
            t->sons++;
            t = t->son[s[i]-base];
        }
        t->num++;
        t->info.insert(info);
    }
    void erase(char * s, int size,T info){
        node * t = root;
        for (int i=0; i<size; i++) {
            t->sons--;
            t = t->son[s[i]-base];
        }
        t->num--;
        t->info.erase(info);
    }
    T search(char * s, int size){
        node * t = root;
        for (int i=0; i<size; i++) {
            if (t->son[s[i]-base]==nullptr) {
                return -1;
            }
            t = t->son[s[i]-base];
        }
        if (t->num) {
            return *(t->info.begin());
        }
        else {
            return -1;
        }
    }
    const char * operator[](int x){
        node * t = root;
        char * s = new char[maxlen];
        int size = 0;
        while(true){
            for (int i=0; i<range; i++) {
                if (t->son[i]!=nullptr) {
                    if (t->son[i]->num+t->son[i]->sons>x) {
                        t=t->son[i];
                        x-=t->num;
                        s[size+1]=s[size];
                        s[size]=base+i;
                        size++;
                        if (x<0) {
                            return s;
                        }
                        break;
                    }
                    else {
                        x-=t->son[i]->num+t->son[i]->sons;
                    }
                }
            }
        }
    }
};
char s[maxn][maxlen];
Trie<> a;
int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,m,n;
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%s",s[i]);
        a.insert(s[i], strlen(s[i]), i);
    }
    for (i=0; i<n; i++) {
        printf("%s\n",a[i]);
    }
    return 0;
}
