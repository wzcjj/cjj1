#include<iostream>
#include<cstdio>
using namespace std;
void output()
{
    int m=0;
	for(int i=1;i<10;i++)for(int j=1;j<10;j++)//调用solve函数，解数独 
    {
		cout<<sudoku[i][j];
        m++;
   	    if(m%9!=0)cout<<" ";
   	    else cout<<endl;
	}
}
