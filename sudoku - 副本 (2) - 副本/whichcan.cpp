#include<iostream>
#include<cmath>
using namespace std;
int whichcan(int sudoku[][10],int x,int y)//made by ���� 
{
	int ok[10],p=0;//ok[10]��ǰ������״̬��pΪ���շ��صĿ����Խ�� 
	for(int i=1;i<=9;i++)ok[i]=1;//��ʼ�� 
	int c=0;//c����������ǰָ����������ֵ
	for(int m=1;m<10;++m)//�鿴��ǰ���뵱ǰ�в��ų� 
	{
		c=sudoku[m][y];
		if(c!=0&&ok[c]!=0)ok[c]=0;
		c=sudoku[x][m];
		if(c!=0&&ok[c]!=0)ok[c]=0;
	}
	if(x<=3&&y<=3)//�ҵ���Ӧ�Ź����ų� 
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
	for(int m=1;m<10;++m)//������ת��Ϊ����Ҫ������ 
	{
		p+=ok[m]*(1<<(m-1));
	}
	return p;
}
