#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void output(int sudoku[][10])//made by 徐寅 
{
    int m=0;
	for(int i=1;i<10;i++)for(int j=1;j<10;j++)
    {
		cout<<sudoku[i][j];
        m++;
   	    if(m%9!=0)cout<<"\t";
   	    else cout<<endl;
	}
}
int whichcan(int sudoku[][10],int x,int y)//made by 徐寅 
{
	int ok[10];//ok[10]当前可能性状态，p为最终返回的可能性结果 
	int p;
	p=0;
	for(int i=1;i<=9;i++)ok[i]=1;//初始化 
	int c=0;//c缓存数独当前指向格子里的数值
	for(int m=1;m<10;++m)//查看当前行与当前列并排除 
	{
		c=sudoku[m][y];
		if(c!=0&&ok[c]!=0)ok[c]=0;
		c=sudoku[x][m];
		if(c!=0&&ok[c]!=0)ok[c]=0;
	}
		for(int m=(x-1)/3*3+1;m<=(x-1)/3*3+3;m++)for(int n=(y-1)/3*3+1;n<=(y-1)/3*3+3;n++)//找到对应九宫格并排除
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	for(int m=1;m<10;++m)//将数组转化为所需要的整数 
	{
		p+=ok[m]*(1<<(m-1));
	}
	return p;
}
bool solve(int sudoku[][10])//made by 陈继劲 
{
    while(1)
    { 
        int min=10,haveone=0,x,y,i,j,k;//min最少有几种可能，haveone是否存在只有一种可能的格子 
        int minwhich[10];//记录最少可能的哪几个数可以 
        for(i=1;i<=9;i++)for(j=1;j<=9;j++)if(sudoku[i][j]==0)
        {
            int t=whichcan(sudoku,i,j);//求出当前格子有哪几种可能，i可能则第i位为1，比如1、3、4可能则返回1101 
            if(t==0)return false;//此路不通 
            int number=0;
            int which[10];//存放哪几个数可以 
            memset(which,0,sizeof(which));//初始化 
            for(k=1;k<=9;k++)//将t展开 
            {
                if(t%2)
                {
                    number++;
                    which[k]=1;
                }
                t/=2;
            }
            if(number==1)//若这个格子只有一种可能，则直接填入 
            {
                haveone=1;
                for(k=1;k<=9;k++)if(which[k])sudoku[i][j]=k;
            }
            if(number<min)//计算哪个格子可能数最少 
            {
                min=number;
                x=i;
                y=j;
                for(k=1;k<=9;k++)minwhich[k]=which[k];
            }
        }
        if(min==10)//没有空格子了 
        {
            output(sudoku);//输出表格sudoku 
            return true;
        }
        if(haveone==0)//没有只有一种可能的格子 
        {
            int a[10][10];//记录当前的sudoku
            for(i=1;i<=9;i++)for(j=1;j<=9;j++)a[i][j]=sudoku[i][j];
            for(k=1;k<=9;k++)if(minwhich[k])
            {
                sudoku[x][y]=k;
                if(solve(sudoku))return true;//有解 
                for(i=1;i<=9;i++)for(j=1;j<=9;j++)sudoku[i][j]=a[i][j];//还原 
            }
            return false;//此路不通 
        }
    }
}
int main()//made by 陈继劲 
{
    int sudoku[10][10];//存放数独表 
    int i,j,m,n; 
    freopen("sudokuin.tsv","r",stdin);
    freopen("sudokuout.tsv","w",stdout); 
    for(i=1;i<=9;i++)for(j=1;j<=9;j++)cin>>sudoku[i][j];//输入 
    solve(sudoku);//调用solve函数，解数独 
    return 0;
} 
