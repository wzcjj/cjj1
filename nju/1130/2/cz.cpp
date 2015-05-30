#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int table1[5]={7,4,2,1,0};
const char table2[10][6]={"11000","00011","00101","00110","01001","01010","01100","10001","10010","10100"};
class zipCode
{
public:
	zipCode(int nn)
	{
		n=nn;
	}
	zipCode(char s[])
	{
		int i,j,sum=0;
		int m;
		if(!isValid(s))	
		{
			n=-1;
		}else
		{
			for(i=0;i<5;i++)
			{
				m=0;
				for(j=0;j<5;j++)
				{
					m+=(s[i*5+j]-'0')*table1[j];
				}
				sum=sum*10+(m==11 ? 0:m);
			}
			n=sum;
		}
	}
	void intOut()
	{
		if(n==-1)
		{
			cout<<"error"<<endl;
		}else
		{
			cout<<setw(5)<<setfill('0')<<n<<endl;
		}
	}
	void strOut()
	{
		int i,nn,arr[5]={0};
		nn=n;
		for(i=0;i<5;i++)
		{
			arr[4-i]=nn%10;
			nn/=10;
		}
		for(i=0;i<5;i++)
		{
			cout<<table2[arr[i]];
			if(i==4)
			{
				cout<<endl;
			}else
			{
				cout<<" ";
			}
		}
	}
private:
	bool isValid(char s[])
	{
		int i,j,count1,count0;
		for(i=0;i<5;i++)
		{
			count0=count1=0;
			for(j=0;j<5;j++)
			{
				if(s[i*5+j]=='1')
					count1++;
				if(s[i*5+j]=='0')
					count0++;
			}
			if(count1!=2||count0!=3) return false;
		}
		return true;
	}
	int n;
	

};
int main()
{
	int count=0;
	char s[26];
	char c;
	while((c=cin.get())!=EOF)
	{
		if(c=='\n')
		{
			s[count]='\0';
			if(count==5)
			{
				zipCode z(atoi(s));
				z.strOut();
			}else
			{
				zipCode z(s);
				z.intOut();
			}
			count=0;
		}else
		{
			if(c!=' ')
			{
				s[count]=c;
				count++;
			}
		}
	}
	return 0;
}
