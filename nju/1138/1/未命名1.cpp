#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    int v,c;
    node *p,*l,*r;
};
void lr(node *&a,node *x){
    node *y=(*x).r;
    (*x).r=(*y).l;
    if((*y).l!=0)(*(*y).l).p=x;
    (*y).p=(*x).p;
    if((*x).p==0)a=y;
    else if(x==(*(*x).p).l)(*(*x).p).l=y;
    else (*(*x).p).r=y;
    (*y).l=x;
    (*x).p=y;
}
void rr(node *&a,node *x){
    node *y=(*x).l;
    (*x).l=(*y).r;
    if((*y).r!=0)(*(*y).r).p=x;
    (*y).p=(*x).p;
    if((*x).p==0)a=y;
    else if(x==(*(*x).p).r)(*(*x).p).r=y;
    else (*(*x).p).l=y;
    (*y).r=x;
    (*x).p=y;
}
void fixup(node *&a,node *&z){
    while((*z).p!=0&&(*(*z).p).c==0){
        if((*z).p==(*(*(*z).p).p).l){
            node *y=(*(*(*z).p).p).r;
            if(y!=0&&(*y).c==0){
                (*(*z).p).c=1;
                (*y).c=1;
                (*(*(*z).p).p).c=0;
                z=(*(*z).p).p;
            }
            else{
                if(z==(*(*z).p).r){
                    z=(*z).p;
                    lr(a,z);
                }
                (*(*z).p).c=1;
                (*(*(*z).p).p).c=0;
                rr(a,(*(*z).p).p);
            }
        }
        else if((*z).p==(*(*(*z).p).p).r){
            node *y=(*(*(*z).p).p).l;
            if(y!=0&&(*y).c==0){
                (*(*z).p).c=1;
                (*y).c=1;
                (*(*(*z).p).p).c=0;
                z=(*(*z).p).p;
            }
            else{
                if(z==(*(*z).p).l){
                    z=(*z).p;
                    rr(a,z);
                }
                (*(*z).p).c=1;
                (*(*(*z).p).p).c=0;
                lr(a,(*(*z).p).p);
            }
        }
    }
    (*a).c=1;
}
void insert(node *&a,node *&z){
    node *y=0;
    node *x=a;
    while(x!=0){
        y=x;
        if((*z).v<(*x).v)x=(*x).l;
        else x=(*x).r;
    }
    (*z).p=y;
    if(y==0)a=z;
    else if((*z).v<(*y).v)(*y).l=z;
    else (*y).r=z;
    (*z).l=0;
    (*z).r=0;
    (*z).c=0;//red
    fixup(a,z);
}
void dfs(node *x){
    printf("%d:%s\n",(*x).v,(*x).c?"black":"red");
    if((*x).l!=0)dfs((*x).l);
    if((*x).r!=0)dfs((*x).r);
}
int search(node *x,int t){
    if(x==0)return 0;
    if(t==(*x).v)return 0;
    else if(t>(*x).v)return 1+search((*x).r,t);
    else return 1+search((*x).l,t);
}
int main(){
    int i,j,m,n;
    while(cin>>n>>m){
    node *a=0;
    for(i=1;i<=n;i++){
        node *t;
        t=new node;
        int x;
        scanf("%d",&x);
        ((*t).v)=x;
        insert(a,t);
    }
    dfs(a);
    for(i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        int ans=search(a,t);
        printf("%d\n",ans);
    }
    }
    return 0;
}
