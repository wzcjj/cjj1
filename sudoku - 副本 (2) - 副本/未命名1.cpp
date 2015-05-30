#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

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
bool fill(int sudoku[][10],int i,int j)//�������������е�����i 
{
	if(j==9)return true;
	int x,y;
		int w=rand()%9;
		for(int e=0;e<9;++e)
		{
			x=w/3+1+j/3*3;
		    y=w%3+1+j%3*3;
		    w=(w+1)%9;
			if(sudoku[x][y]!=0)continue;
			int t=whichcan(sudoku,x,y);
		    int which[10];
		    memset(which,0,sizeof(which));
		    for(int k=1;k<=i+1;k++)//��tչ�� 
            {
                if(t%2)
                {
                    which[k]=1;
                }
                t/=2;
            }
			if(which[i+1]!=0)
            {
            	int a[10][10];//��¼��ǰ��sudoku
                for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];
				sudoku[x][y]=i+1;
            	if(fill(sudoku,i,j+1))return true;
            	for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];//��ԭ 
            }
		}
	    return false; 
}
int main()
{
	int sudoku[10][10];//������� 
	srand((unsigned int)time(NULL));//�����
    int NO=0;
	do
	{
		NO=0;
	memset(sudoku,0,sizeof(sudoku));//��ʼ�� 
		for(int i=0;i<9;++i)
	    {
		    int f=fill(sudoku,i,0);
		    if(f==0)
		    {
		    	NO++;
		    	break;
		    }
	    }
	}while(NO!=0);//����һ��������ȫ�� 
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)cout<<sudoku[i][j]<<' ';
        cout<<endl;
    }
    system("pause");
    return 0;
}
        
