#include<iostream>
using namespace std;
int a[20],b[20];
void make(int x){
    a[x]=x;
    b[x]=0;
}
int find(int x){
    if(x!=a[x])a[x]=find(a[x]);
    return a[x];
}
void lin(int x,int y){
    if(b[x]>b[y])a[y]=x;
    else{
        a[x]=y;
        if(b[x]==b[y])b[y]++;
    }
}
void un(int x,int y){
    lin(find(x),find(y));
}

int main(){
    int i,j,m,n;
    for(i=1;i<=16;i++)make(i);
    for(i=1;i<=15;i+=2)un(i,i+1);
    for(i=1;i<=13;i+=4)un(i,i+2);
    un(1,5);
    un(11,13);
    un(1,10);
    cout<<find(2)<<endl;
    cout<<find(9)<<endl;
    cout<<endl;
    for(i=1;i<=16;i++)cout<<a[i]<<endl;
    system("pause");
    return 0;
}
     
