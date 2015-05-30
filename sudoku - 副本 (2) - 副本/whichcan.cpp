#include<iostream>
#include<cmath>
using namespace std;
int whichcan(int sudoku[][10],int x,int y)//made by 徐寅 
{
	int ok[10],p=0;//ok[10]当前可能性状态，p为最终返回的可能性结果 
	for(int i=1;i<=9;i++)ok[i]=1;//初始化 
	int c=0;//c缓存数独当前指向格子里的数值
	for(int m=1;m<10;++m)//查看当前行与当前列并排除 
	{
		c=sudoku[m][y];
		if(c!=0&&ok[c]!=0)ok[c]=0;
		c=sudoku[x][m];
		if(c!=0&&ok[c]!=0)ok[c]=0;
	}
	if(x<=3&&y<=3)//找到对应九宫格并排除 
	{
		for(int m=1;m<=3;m++)for(int n=1;n<=3;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(x<=3&&y<=6)
	{
		for(int m=1;m<=3;m++)for(int n=4;n<=6;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(x<=3)
	{
		for(int m=1;m<=3;m++)for(int n=7;n<=9;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(x<=6&&y<=3)
	{
		for(int m=4;m<=6;m++)for(int n=1;n<=3;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(x<=6&&y<=6)
	{
		for(int m=4;m<=6;m++)for(int n=4;n<=6;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(x<=6)
	{
		for(int m=4;m<=6;m++)for(int n=7;n<=9;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(y<=3)
	{
		for(int m=7;m<=9;m++)for(int n=1;n<=3;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else if(y<=6)
	{
		for(int m=7;m<=9;m++)for(int n=4;n<=6;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	else
	{
		for(int m=7;m<=9;m++)for(int n=7;n<=9;n++)
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	}
	for(int m=1;m<10;++m)//将数组转化为所需要的整数 
	{
		p+=ok[m]*(1<<(m-1));
	}
	return p;
}
