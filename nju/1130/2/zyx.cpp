#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class zip
{
	public:
		
		void input(string da[5], int m)
		{
			n=m;
			if (n==1)
			{
				for (int i=0; i<5; i++)
				{
					z[i]=int(da[0][i])-int('0');//***transform char to int
				}
			}
			else
			{
				for (int i=0; i<5; i++) 
				{
					for (int j=0; j<5; j++)
					{
						d[i][j]=int(da[i][j])-int('0');
						//cout << " checks" << d[i][j] << endl;
					}
				}
			}
		}
		
		void transfer()
		{
			int store[10][2]={1,0,4,3,4,2,3,2,4,1,3,1,2,1,4,0,3,0,2,0};
			if (n==5)
			{
				int temp[6]={0};
				for (int i=0; i<5; i++)
				{
					temp[i]=7*d[i][0]+4*d[i][1]+2*d[i][2]+d[i][3];
					//int ss=temp[i];int mm=d[i][0];
					//cout << " check" << ss << mm << endl;
					if (temp[i]>9) temp[i]=0;
					int k=0,ans=temp[i];
					while (k<4-i)
					{
						ans*=10;
						k++;
					}
					temp[5]+=ans;
				}
				cout << temp[5] << endl;
			} 
			else
			{
				string s[5];
				for (int i=0; i<5; i++)
				{
					s[i]="00000";
					int x=store[z[i]][0];
					int y=store[z[i]][1];
					s[i][x]='1';
					s[i][y]='1';
					if (i<4) cout << s[i] << " ";
					else cout << s[i] << endl;
			    }
			}
		}
		
	private:
		int n,d[5][5],z[5];
		
};

int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
	int m;
	string da[5];
	string yy;
	
	int counter=0;
	while (getline(cin,yy))//string¶ÁÈëÊ±ºöÂÔ¿Õ¸ñ 
	{
		 //check if legal
		int length=yy.size();
		if (length<29)
		{
			counter=0;
			for (int i=0; i<5; i++)
			{
				da[0][i]=yy[i];//the place of string starts from 0
			}
		}
		else
		{
			counter=4;
			for (int i=0; i<5; i++)
			{
				for (int j=0; j<5; j++)
				{
					da[i]+=yy[6*i+j];
				}
			}
		}
		//else
	//	{
			m=counter+1;
			bool flag=1;
			if (m==5)
			{
				for (int i=0; i<5; i++)
				{
					int num=0;
					for (int j=0; j<5; j++)
					{
						if (da[i][j]=='1') num++;
						if (da[i][j]!='0' && da[i][j]!='1') flag=0;
					}
					if (num!=2) 
					{
						flag=0;
					}
			    }
			}
			
			if (flag)
			{
				zip work;
				work.input(da, m);
				work.transfer();
			}
			else cout << "error" << endl;
	//	}
	}
	
	return 0;
}
