//
//  main.cpp
//  kmp
//
//  Created by wzcjj on 15/8/2.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int nex[100];
void getNext(string W){
    nex[0]=-1;
    int j=-1;
    for(int i=1;i<W.length();i++,j++){
        while(j>-1&&W[j+1]!=W[i])j=nex[j];
        if(W[j+1]==W[i])j++;
        nex[i]=j;
    }
}
int KMP(string W,string T){
    int i,j=-1;
    for(i=0;i<T.size();i++){
        while(j>-1&&W[j+1]!=T[i])j=nex[j];
        if(W[j+1]==T[i])j++;
        if(j==W.size()-1){
            return i-j;
            //ans++;
            //j=nex[j];
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string w,t;
    cin>>w>>t;
    getNext(w);
    cout<<KMP(w,t);
    //std::cout << "Hello, World!\n";
    return 0;
}
