#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

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
            //output(sudoku);//输出表格sudoku 
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

bool fill(int sudoku[][10],int i,int j)//生成数独上所有的数字i 
{
	
	if(j==9)return true;
	int x,y;

		int w=rand()%9;
		//cout<<"depth="<<j+1<<endl;//test
		//int realdone=0;//test
		for(int e=0;e<9;++e)
		{
			x=w/3+1+j/3*3;
		    y=w%3+1+j%3*3;
		    w=(w+1)%9;
			//realdone++;//test
		    //cout<<"realdone="<<realdone<<endl;//test
			if(sudoku[x][y]!=0)continue;
		    
			int t=whichcan(sudoku,x,y);
		    int which[10];
		    memset(which,0,sizeof(which));
		    for(int k=1;k<=i+1;k++)//将t展开 
            {
                if(t%2)
                {
                    which[k]=1;
                }
                t/=2;
            }
            //if(which[i+1]==0)return false;
			if(which[i+1]!=0)
            {
            	int a[10][10];//记录当前的sudoku
                for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];
				sudoku[x][y]=i+1;
            	if(fill(sudoku,i,j+1))return true;
            	for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];//还原 
            }
            
		}
	    return false; 
}


bool cut(int sudoku[][10],int real[][10])
{
	int h=rand()%9,j=rand()%9;//随机生成数独上一个位置 
	while(sudoku[h+1][j+1]==0)//确保该位置非空 
	{
		h=rand()%9;
		j=rand()%9;
	}
	int v=sudoku[h+1][j+1];//v缓存该位置数值 
	//检查挖去当前格后是否仍具有唯一解，方法为将该位置换填其他所有数字，
	//如果能产生有效解，则挖去当前格后没有唯一解，即到达了极限状态 
	for(int l=1;l<10;++l)if(l!=v)
	{
		int a[10][10];
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];//a[10][10]缓存当前数独状态，以备还原 
		sudoku[h+1][j+1]=l;//改变当前格数值 
		if(solve(sudoku))
		{
			int r=0; 
			for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)
			{
				if(sudoku[p][q]!=real[p][q])
				{
					r++;
				}
			}//检测是否为真解，如果非真解（即将错就错），则r=1，若为真解，则r必远大于1 
			if(r>1)
			{
				for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
			    return true;
			}//若为真解，则恢复原有状态并返回true 
		}
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
	} 
	sudoku[h+1][j+1]=0; 
	if(cut(sudoku,real))return true;
}

int create(int sudoku[][10])
{
    int NO=0;
	do
	{
		NO=0;
		for(int i=1;i<10;++i)for(int j=1;j<10;++j)sudoku[i][j]=0;
		for(int i=0;i<9;++i)
	    {
		    int f=fill(sudoku,i,0);
		    if(f==0)
		    {
		    	NO++;
		    	break;
		    }
	    }
	}while(NO!=0);//生成一个数组完全解 
	int real[10][10];
	for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)real[p][q]=sudoku[p][q];
	//
	int sum=0;
	if(cut(sudoku,real))
	{
		int a=0;
        for(int i=1;i<10;++i)for(int j=1;j<10;++j)
	    {
	        if(sudoku[i][j]==0)sum++;
			
			cout<<sudoku[i][j];
	        a++;
	        if(a%9!=0)cout<<"\t";
	        else cout<<endl;
        }
        //cout<<sum<<endl;
	}
	
	return sum;
}
int main()
{
	int sudoku[10][10];//存放数独 
	srand((unsigned int)time(NULL));//随机数
	int sum[1000];
	memset(sum,0,sizeof(sum));
	int suma=0;
	int numm=0;
	int numh=0;
	int max=0;
	for(int wo=0;wo<1000;++wo)
	{
		for(int i=1;i<10;++i)for(int j=1;j<10;++j)sudoku[i][j]=0;//初始化 
		sum[wo]=create(sudoku);
		cout<<wo<<"\t"<<sum[wo]<<endl;
		suma+=sum[wo];
		if(sum[wo]>=40)numm++;
		if(sum[wo]>=50)numh++;
		if(sum[wo]>max)max=sum[wo];
	}
	cout<<suma<<"\t"<<numm<<"\t"<<numh<<"\t"<<max<<endl;
	return 0;
}
