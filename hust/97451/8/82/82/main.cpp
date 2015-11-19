//
//  main.cpp
//  82
//
//  Created by wzcjj on 15/10/30.
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
#define maxn 1005
#define P 1000000007
#define INF 2100000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
using namespace std;

int ans[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    ans[0]=4;
    ans[1]=5;
    ans[2]=6;
    ans[3]=3;
    ans[4]=6;
    ans[5]=3;
    ans[6]=7;
    ans[7]=4;
    ans[8]=7;
    ans[9]=8;
    ans[10]=4;
    ans[11]=5;
    ans[12]=4;
    ans[13]=5;
    ans[14]=4;
    ans[15]=1;
    ans[16]=6;
    ans[17]=3;
    ans[18]=7;
    ans[19]=4;
    ans[20]=7;
    ans[21]=4;
    ans[22]=10;
    ans[23]=7;
    ans[24]=8;
    ans[25]=8;
    ans[26]=7;
    ans[27]=5;
    ans[28]=7;
    ans[29]=5;
    ans[30]=7;
    ans[31]=4;
    ans[32]=7;
    ans[33]=8;
    ans[34]=4;
    ans[35]=5;
    ans[36]=8;
    ans[37]=8;
    ans[38]=7;
    ans[39]=5;
    ans[40]=8;
    ans[41]=10;
    ans[42]=5;
    ans[43]=6;
    ans[44]=8;
    ans[45]=8;
    ans[46]=5;
    ans[47]=5;
    ans[48]=4;
    ans[49]=5;
    ans[50]=4;
    ans[51]=1;
    ans[52]=7;
    ans[53]=5;
    ans[54]=7;
    ans[55]=4;
    ans[56]=8;
    ans[57]=8;
    ans[58]=5;
    ans[59]=5;
    ans[60]=5;
    ans[61]=7;
    ans[62]=6;
    ans[63]=4;
    ans[64]=7;
    ans[65]=8;
    ans[66]=8;
    ans[67]=8;
    ans[68]=4;
    ans[69]=5;
    ans[70]=7;
    ans[71]=5;
    ans[72]=8;
    ans[73]=10;
    ans[74]=8;
    ans[75]=8;
    ans[76]=5;
    ans[77]=6;
    ans[78]=5;
    ans[79]=5;
    ans[80]=4;
    ans[81]=5;
    ans[82]=7;
    ans[83]=5;
    ans[84]=4;
    ans[85]=1;
    ans[86]=7;
    ans[87]=4;
    ans[88]=8;
    ans[89]=8;
    ans[90]=5;
    ans[91]=7;
    ans[92]=5;
    ans[93]=5;
    ans[94]=6;
    ans[95]=4;
    ans[96]=8;
    ans[97]=10;
    ans[98]=8;
    ans[99]=8;
    ans[100]=8;
    ans[101]=8;
    ans[102]=5;
    ans[103]=7;
    ans[104]=11;
    ans[105]=12;
    ans[106]=8;
    ans[107]=10;
    ans[108]=8;
    ans[109]=10;
    ans[110]=8;
    ans[111]=8;
    ans[112]=5;
    ans[113]=6;
    ans[114]=5;
    ans[115]=5;
    ans[116]=5;
    ans[117]=5;
    ans[118]=6;
    ans[119]=4;
    ans[120]=8;
    ans[121]=10;
    ans[122]=8;
    ans[123]=8;
    ans[124]=8;
    ans[125]=8;
    ans[126]=8;
    ans[127]=7;
    ans[128]=8;
    ans[129]=9;
    ans[130]=9;
    ans[131]=9;
    ans[132]=9;
    ans[133]=9;
    ans[134]=10;
    ans[135]=9;
    ans[136]=5;
    ans[137]=7;
    ans[138]=6;
    ans[139]=6;
    ans[140]=6;
    ans[141]=6;
    ans[142]=7;
    ans[143]=6;
    ans[144]=9;
    ans[145]=9;
    ans[146]=10;
    ans[147]=9;
    ans[148]=10;
    ans[149]=9;
    ans[150]=11;
    ans[151]=10;
    ans[152]=7;
    ans[153]=6;
    ans[154]=7;
    ans[155]=7;
    ans[156]=7;
    ans[157]=7;
    ans[158]=10;
    ans[159]=7;
    ans[160]=5;
    ans[161]=7;
    ans[162]=6;
    ans[163]=6;
    ans[164]=7;
    ans[165]=6;
    ans[166]=7;
    ans[167]=7;
    ans[168]=5;
    ans[169]=6;
    ans[170]=2;
    ans[171]=3;
    ans[172]=6;
    ans[173]=6;
    ans[174]=4;
    ans[175]=3;
    ans[176]=6;
    ans[177]=6;
    ans[178]=7;
    ans[179]=6;
    ans[180]=7;
    ans[181]=7;
    ans[182]=10;
    ans[183]=7;
    ans[184]=6;
    ans[185]=6;
    ans[186]=4;
    ans[187]=3;
    ans[188]=7;
    ans[189]=7;
    ans[190]=7;
    ans[191]=6;
    ans[192]=5;
    ans[193]=7;
    ans[194]=7;
    ans[195]=6;
    ans[196]=6;
    ans[197]=6;
    ans[198]=7;
    ans[199]=7;
    ans[200]=5;
    ans[201]=6;
    ans[202]=6;
    ans[203]=6;
    ans[204]=2;
    ans[205]=3;
    ans[206]=4;
    ans[207]=3;
    ans[208]=6;
    ans[209]=6;
    ans[210]=7;
    ans[211]=7;
    ans[212]=7;
    ans[213]=6;
    ans[214]=10;
    ans[215]=7;
    ans[216]=6;
    ans[217]=6;
    ans[218]=7;
    ans[219]=7;
    ans[220]=4;
    ans[221]=3;
    ans[222]=7;
    ans[223]=6;
    ans[224]=5;
    ans[225]=6;
    ans[226]=6;
    ans[227]=6;
    ans[228]=6;
    ans[229]=6;
    ans[230]=7;
    ans[231]=7;
    ans[232]=8;
    ans[233]=9;
    ans[234]=5;
    ans[235]=6;
    ans[236]=5;
    ans[237]=6;
    ans[238]=2;
    ans[239]=5;
    ans[240]=2;
    ans[241]=3;
    ans[242]=4;
    ans[243]=3;
    ans[244]=4;
    ans[245]=3;
    ans[246]=7;
    ans[247]=6;
    ans[248]=5;
    ans[249]=6;
    ans[250]=2;
    ans[251]=5;
    ans[252]=2;
    ans[253]=5;
    ans[254]=4;
    ans[255]=3;
    while (N--) {
        char s[10];
        scanf("%s",s);
        int tmp= 0;
        for(i=0;i<=7;i++){
            tmp+=(s[i]-'0')<<(7-i);
        }
        cout<<ans[tmp]<<endl;
    }
    return 0;
}
