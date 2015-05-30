#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void output(int sudoku[][10])//made by ���� 
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
int whichcan(int sudoku[][10],int x,int y)//made by ���� 
{
	int ok[10];//ok[10]��ǰ������״̬��pΪ���շ��صĿ����Խ�� 
	int p;
	p=0;
	for(int i=1;i<=9;i++)ok[i]=1;//��ʼ�� 
	int c=0;//c����������ǰָ����������ֵ
	for(int m=1;m<10;++m)//�鿴��ǰ���뵱ǰ�в��ų� 
	{
		c=sudoku[m][y];
		if(c!=0&&ok[c]!=0)ok[c]=0;
		c=sudoku[x][m];
		if(c!=0&&ok[c]!=0)ok[c]=0;
	}
		for(int m=(x-1)/3*3+1;m<=(x-1)/3*3+3;m++)for(int n=(y-1)/3*3+1;n<=(y-1)/3*3+3;n++)//�ҵ���Ӧ�Ź����ų�
		{
			if(m==x||n==y)continue;
			c=sudoku[m][n];
			if(c!=0&&ok[c]!=0)ok[c]=0;
		}
	for(int m=1;m<10;++m)//������ת��Ϊ����Ҫ������ 
	{
		p+=ok[m]*(1<<(m-1));
	}
	return p;
}
bool solve(int sudoku[][10])//made by �¼̾� 
{
    while(1)
    { 
        int min=10,haveone=0,x,y,i,j,k;//min�����м��ֿ��ܣ�haveone�Ƿ����ֻ��һ�ֿ��ܵĸ��� 
        int minwhich[10];//��¼���ٿ��ܵ��ļ��������� 
        for(i=1;i<=9;i++)for(j=1;j<=9;j++)if(sudoku[i][j]==0)
        {
            int t=whichcan(sudoku,i,j);//�����ǰ�������ļ��ֿ��ܣ�i�������iλΪ1������1��3��4�����򷵻�1101 
            if(t==0)return false;//��·��ͨ 
            int number=0;
            int which[10];//����ļ��������� 
            memset(which,0,sizeof(which));//��ʼ�� 
            for(k=1;k<=9;k++)//��tչ�� 
            {
                if(t%2)
                {
                    number++;
                    which[k]=1;
                }
                t/=2;
            }
            if(number==1)//���������ֻ��һ�ֿ��ܣ���ֱ������ 
            {
                haveone=1;
                for(k=1;k<=9;k++)if(which[k])sudoku[i][j]=k;
            }
            if(number<min)//�����ĸ����ӿ��������� 
            {
                min=number;
                x=i;
                y=j;
                for(k=1;k<=9;k++)minwhich[k]=which[k];
            }
        }
        if(min==10)//û�пո����� 
        {
            output(sudoku);//������sudoku 
            return true;
        }
        if(haveone==0)//û��ֻ��һ�ֿ��ܵĸ��� 
        {
            int a[10][10];//��¼��ǰ��sudoku
            for(i=1;i<=9;i++)for(j=1;j<=9;j++)a[i][j]=sudoku[i][j];
            for(k=1;k<=9;k++)if(minwhich[k])
            {
                sudoku[x][y]=k;
                if(solve(sudoku))return true;//�н� 
                for(i=1;i<=9;i++)for(j=1;j<=9;j++)sudoku[i][j]=a[i][j];//��ԭ 
            }
            return false;//��·��ͨ 
        }
    }
}
int main()//made by �¼̾� 
{
    int sudoku[10][10];//��������� 
    int i,j,m,n; 
    freopen("sudokuin.tsv","r",stdin);
    freopen("sudokuout.tsv","w",stdout); 
    for(i=1;i<=9;i++)for(j=1;j<=9;j++)cin>>sudoku[i][j];//���� 
    solve(sudoku);//����solve������������ 
    return 0;
} 
