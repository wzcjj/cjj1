//
//  main.cpp
//  calc
//
//  Created by wzcjj on 15/9/12.
//  Copyright (c) 2015年 wzcjj. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    for(int i=0;i<=23;i++){
        int j,k;
        scanf("%d:%d",&j,&k);
        cout<<1-(double)k*15/7460/60/9<<endl;
    }
    return 0;
}
