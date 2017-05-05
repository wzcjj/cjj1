//
//  main.cpp
//  11
//
//  Created by wzcjj on 16/7/31.
//  Copyright (c) 2016年 wzcjj. All rights reserved.
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
#define eps 1e-9
#define maxn 10005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

struct point3{
    double x,y,z;
    point3(){}
    point3(double x,double y,double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

struct vec3{
    double x,y,z;
    vec3(){}
    vec3(point3 a){
        x=a.x;
        y=a.y;
        z=a.z;
    }
    vec3(double x,double y,double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    friend vec3 operator+(vec3 a,vec3 b){
        return vec3(a.x+b.x,a.y+b.y,a.z+b.z);
    }
    friend vec3 operator-(vec3 a,vec3 b){
        return vec3(a.x-b.x,a.y-b.y,a.z-b.z);
    }
    friend double operator*(vec3 a,vec3 b){
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }
    friend vec3 operator*(vec3 a,double c){
        return vec3(a.x*c,a.y*c,a.z*c);
    }
    friend vec3 operator/(vec3 a,double c){
        return vec3(a.x/c,a.y/c,a.z/c);
    }
    double len(){
        return sqrt(x*x+y*y+z*z);
    }
    friend double angle(vec3 a,vec3 b){
        return a*b/a.len()/b.len();
    }
    friend vec3 operator%(vec3 a,vec3 b){
        return vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
    }
};

vec3 operator-(point3 a,point3 b){
    return vec3(a.x-b.x,a.y-b.y,a.z-b.z);
}

struct plane{
    point3 p0;
    vec3 n;
    plane(){}
    plane(point3 p,vec3 a){
        p0=p;
        n=a/a.len();
    }
    plane(point3 a,point3 b,point3 c){
        vec3 nn=(b-a)%(c-a);
        n=nn/nn.len();
        p0=a;
    }
};
point3 a,b,c,d;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z,&c.x,&c.y,&c.z,&d.x,&d.y,&d.z)!=EOF) {
        if(abs((d-a)*((b-a)%(c-a)))<eps){
            printf("O O O O\n");
            continue;
        }
        vec3 t=((vec3)d*((b-a)%(c-a)).len()+(vec3)c*((b-a)%(d-a)).len()+(vec3)b*((d-a)%(c-a)).len()+(vec3)a*((c-b)%(d-b)).len())/(((b-a)%(c-a)).len()+((b-a)%(d-a)).len()+((d-a)%(c-a)).len()+((c-b)%(d-b)).len());
        double r=(a.x*(b.y*(c.z-d.z)+b.z*(d.y-c.y)+c.y*d.z-c.z*d.y)-a.y*(b.z*(d.x-c.x)+b.x*(c.z-d.z)+c.x*d.z-c.z*d.x)+a.z*(b.x*(c.y-d.y)+b.y*(d.x-c.x)+c.x*d.y-c.y*d.x)-b.x*(c.y*d.z-c.z*d.y)-b.y*(c.z*d.x-c.x*d.z)-b.z*(c.x*d.y-c.y*d.x))/(((b-a)%(c-a)).len()+((b-a)%(d-a)).len()+((d-a)%(c-a)).len()+((c-b)%(d-b)).len());
        r=abs(r);
        printf("%.4lf %.4lf %.4lf %.4lf\n",t.x,t.y,t.z,r);
    }
    return 0;
}
