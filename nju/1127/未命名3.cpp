#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cstddef>
using namespace std;
typedef string* stringarray;
string* addEntry(string *dynamicArray, int &size, string newEntry);
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
int main(){
    int i,j,m,n;
    stringarray a;
    a = new string[5];
    int size=5;
    for(i=0;i<=4;i++)cin>>a[i];
    while(cin>>n){
        if(n==1){
            string s;
            cin>>s;
            a=addEntry(a,size,s);
            for(i=0;i<size-1;i++)cout<<a[i]<<' ';
            cout<<a[size-1]<<endl;
        }
        else{
            string s;
            cin>>s;
            a=deleteEntry(a,size,s);
            for(i=0;i<size-1;i++)cout<<a[i]<<' ';
            cout<<a[size-1]<<endl;
        }
    }
    delete [] a;
    return 0;
}
string* addEntry(string *dynamicArray, int &size, string newEntry){
    stringarray a;
    a=new string[size+1];
    for(int i=0;i<size;i++)a[i]=dynamicArray[i];
    a[size++]=newEntry;
    delete [] dynamicArray; 
    return a;
}
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete){
    int i;
    for(i=0;i<size;i++)if(dynamicArray[i]==entryToDelete)break;
    if(i!=size){
        stringarray a;
        a=new string[size-1];
        int j;
        for(j=0;j<i;j++)a[j]=dynamicArray[j];
        for(j=i+1;j<size;j++)a[j-1]=dynamicArray[j];
        size--;
        delete [] dynamicArray; 
        return a;
    }
    else return dynamicArray;
}

