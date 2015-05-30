#include <iostream> 
using namespace std; 
int size(0); 
void purm(char a[10],int i,int n,int& k); 
void swap(int *a,int *b); 
int main() 
{ 
    int k(0); 
      
    char a[30]; 
    char x; 
    while(cin>>x) 
    { 
        a[size]=x; 
        size++; 
    } 
    purm(a,0,size,k); 
      
    return 0; 
} 
void swap(int& a,int& b) 
{ 
    int term; 
    term=a; 
    a=b; 
    b=term; 
} 
void purm(char a[],int i,int n,int& k) 
{ 
    char* copy=new char[n]; 
    if(i==n) 
    { 
      
         
        for(int j=0;j<n;j++) 
        { 
            cout<<a[j]; 
            if(j==n-1) 
            { 
                cout<<endl; 
            } 
  
        } 
    } 
    else
    { 
        for(int s=0;s<n;s++) 
        { 
            copy[s]=a[s]; 
        } 
        int number(0); 
        char* b=new char[n]; 
        for(int r=i;r<n;r++) 
        { 
            int chongfu(0); 
            for(int t=0;t<=number;t++) 
            { 
                if(number==0) 
                { 
                    b[0]=a[i]; 
                    number++; 
                    break; 
                } 
                else
                { 
                    if(b[t]==a[r]) 
                    { 
                        chongfu=1; 
                        break; 
                    } 
                } 
            } 
            if(chongfu==0) 
            {    
                number++; 
                b[number]=a[r]; 
                swap(a[i],a[r]); 
                purm(a,i+1,n,k); 
                for(int s=0;s<n;s++) 
                { 
                    a[s]=copy[s]; 
                } 
            } 
        } 
    } 
} 
