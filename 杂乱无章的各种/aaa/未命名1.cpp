#include<iostream> 
#include<math.h> 
using namespace std; 
int main() 
{ 
    char a[20]={'0'},b[20]={'0'}; 
    char next; 
    cin.get(next); 
    int number1(0),number2(0); 
    while(next!=' ') 
    { 
        a[number1]=next; 
        number1++; 
        cin.get(next); 
    } 
    cin.get(next); 
    while(next!=' '&&next!='\n') 
    { 
        b[number2]=next; 
        number2++; 
        cin.get(next); 
    } 
      
    int c[20]={0},d[20]={0}; 
    for(int j=0;j<number1;j++) 
    { 
        c[j]=a[j]-'0'; 
    } 
    for(int m=0;m<number2;m++) 
    { 
        d[m]=b[m]-'0'; 
    } 
    int e[20]={0},f[20]={0}; 
    for(int w=0;w<number1;w++) 
    { 
        e[w]=c[number1-w-1]; 
    } 
    for(int s=0;s<number2;s++) 
    { 
        f[s]=d[number2-s-1]; 
    } 
    int g[20]={0}; 
    int jinwei(0); 
    for(int q=0;q<20;q++) 
    { 
        g[q]=e[q]+f[q]+jinwei; 
        if(g[q]>=10 && q!=19) 
        { 
            g[q]=g[q]%10; 
            jinwei=1; 
        } 
        else
            jinwei=0; 
    } 
    if(g[19]>=10) 
    { 
        cout<<"integer overflow"; 
    } 
    else
    { 
        int jinwei(0); 
        for(int w=19;w>=0;w--) 
        { 
            if(jinwei==1) 
            { 
                cout<<g[w]; 
            } 
            else 
            { 
                if(g[w]!=0) 
                { 
                    cout<<g[w]; 
                    jinwei=1; 
                } 
            } 
		} 
	} 
    system("pause"); 
    return 0; 
} 
