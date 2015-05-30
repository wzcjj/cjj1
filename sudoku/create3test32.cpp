#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
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
            //output(sudoku);//�������sudoku 
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

bool fill(int sudoku[][10],int i,int j)//�������������е�����i 
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
		    for(int k=1;k<=i+1;k++)//��tչ�� 
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
            	int a[10][10];//��¼��ǰ��sudoku
                for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];
				sudoku[x][y]=i+1;
            	if(fill(sudoku,i,j+1))return true;
            	for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];//��ԭ 
            }
            
		}
	    return false; 
}


bool cuteasy(int sudoku[][10],int real[][10],int *num)
{
	int h=rand()%9,t=rand()%9;//�������������һ��λ�� 
	while(sudoku[h+1][t+1]==0)//ȷ����λ�÷ǿ� 
	{
		h=rand()%9;
		t=rand()%9;
	}
	int v=sudoku[h+1][t+1];//v�����λ����ֵ 
	//�����ȥ��ǰ����Ƿ��Ծ���Ψһ�⣬����Ϊ����λ�û��������������֣�
	//����ܲ�����Ч�⣬����ȥ��ǰ���û��Ψһ�⣬�������˼���״̬ 
	for(int l=1;l<10;++l)if(l!=v)
	{
		int a[10][10];
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];//a[10][10]���浱ǰ����״̬���Ա���ԭ 
		sudoku[h+1][t+1]=l;//�ı䵱ǰ����ֵ 
		if(solve(sudoku))
		{
			int r=0; 
			for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)
			{
				if(sudoku[p][q]!=real[p][q])
				{
					r++;
				}
			}//����Ƿ�Ϊ��⣬�������⣨�������ʹ�������r=1����Ϊ��⣬��r��Զ����1 
			if(r>1)
			{
				for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
			    return true;
			}//��Ϊ��⣬��ָ�ԭ��״̬������true 
		}
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
	} 
	sudoku[h+1][t+1]=0; 
	*num=*num+1;
	if(*num>=40||cuteasy(sudoku,real,&*num))return true;
}

bool cutmid(int sudoku[][10],int real[][10])
{
	int em=0,ju;
	for(int p1=1;p1<10;++p1)for(int q1=1;q1<10;++q1)
	{
		ju=0;
		int h=rand()%9+1,t=q1;
		if(p1%2==0)t=10-q1;
		int v=sudoku[h][t];
		if(v==0)continue;
		for(int l=1;l<10;++l)if(l!=v)
	{
		int a[10][10];
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];//a[10][10]���浱ǰ����״̬���Ա���ԭ 
		sudoku[h][t]=l;//�ı䵱ǰ����ֵ 
		if(solve(sudoku))
		{
			int r=0; 
			for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)
			{
				if(sudoku[p][q]!=real[p][q])
				{
					r++;
				}
			}//����Ƿ�Ϊ��⣬�������⣨�������ʹ�������r=1����Ϊ��⣬��r��Զ����1 
			if(r>1)
			{
				for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
				if(em<=50)
				{
					ju++;
					break;
				}
				else 
				{
					//cout<<em<<endl;//
					return true;
				}
				
			}//��Ϊ��⣬��ָ�ԭ��״̬������true 
		}
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
	} 
	if(ju!=0)continue;
	sudoku[h][t]=0; 
	em++;
	}
	//cout<<em<<endl;//
}

bool cuthard(int sudoku[][10],int real[][10])
{
	int em=0,ju;
	for(int p1=1;p1<10;++p1)for(int q1=1;q1<10;++q1)
	{
		ju=0;
		int h=p1,t=q1;
		int v=sudoku[h][t];
		for(int l=1;l<10;++l)if(l!=v)
	{
		int a[10][10];
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)a[p][q]=sudoku[p][q];//a[10][10]���浱ǰ����״̬���Ա���ԭ 
		sudoku[h][t]=l;//�ı䵱ǰ����ֵ 
		if(solve(sudoku))
		{
			int r=0; 
			for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)
			{
				if(sudoku[p][q]!=real[p][q])
				{
					r++;
				}
			}//����Ƿ�Ϊ��⣬�������⣨�������ʹ�������r=1����Ϊ��⣬��r��Զ����1 
			if(r>1)
			{
				for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
				if(em<=60)
				{
					ju++;
					break;
				}
				else 
				{
					//cout<<em<<endl;//
					return true;
				}
				
			}//��Ϊ��⣬��ָ�ԭ��״̬������true 
		}
		for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)sudoku[p][q]=a[p][q];
	} 
	if(ju!=0)continue;
	sudoku[h][t]=0; 
	em++;
	}
	//cout<<em<<endl;//
}

bool create(int sudoku[][10],char level[])
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
	}while(NO!=0);//����һ��������ȫ�� 
	int real[10][10];
	for(int p=1;p<=9;p++)for(int q=1;q<=9;q++)real[p][q]=sudoku[p][q];
	int *num=new int;//num��¼���������еĿո��������ƿո����� 
	*num=0;
	if(strcmp(level,"easy")==0)cuteasy(sudoku,real,&*num);
	else if(strcmp(level,"normal")==0)cutmid(sudoku,real);
	else cuthard(sudoku,real);
	//cout<<*num<<endl;//
	delete num;
	//
	    
		int a=0;
        for(int i=1;i<10;++i)for(int j=1;j<10;++j)
	    {
	        cout<<sudoku[i][j];
	        a++;
	        if(a%9!=0)cout<<"\t";
	        else cout<<endl;
        }
	//test
	return true;
}
int main()
{
	int sudoku[10][10];//������� 
	srand((unsigned int)time(NULL));//�����
	memset(sudoku,0,sizeof(sudoku));//��ʼ�� 
	freopen("hardlevel.in","r",stdin);
    freopen("sudokuin.tsv","w",stdout); 
	char level[10];
    cin>>level;//����ȼ���0Ϊeasy��1Ϊmedium��2Ϊhard 
	create(sudoku,level);
	return 0;
}