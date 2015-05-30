#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;
class postnet
{
public:
	void output_zip();
	void output_bar();
	string s;
	int a[10][10];
	int d[10];
};

int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
	postnet code;
	while(getline(cin,code.s))
	{
		int flag = 0;
		int j = 0;
		for(int i = 0;i < code.s.length();i++)
		{
			if(isdigit(code.s[i]))
		    {
				code.a[flag][j] = code.s[i] - '0';
				j++;
			}
		    else if(isspace(code.s[i]))
			{
				flag++;
				j = 0;
			    continue;
			}
		}
	    if(flag == 0)
			code.output_bar();
	    else 
			code.output_zip();
	}
	return 0;
}
void postnet::output_zip()
{
	bool c = true;
	for(int i = 0;i < 5;i++)
	{
		int t1 = 0;
		int t2 = 0;
		for(int j = 0;j < 5;j++)
		{
			if(a[i][j] == 1)
				t1++;
			if(a[i][j] == 0)
				t2++;
		}
		if(t1 == 2&&t2 == 3)
		{
			d[i] = 7*a[i][0] + 4*a[i][1] + 2*a[i][2] + a[i][3];
			if(d[i] == 11)
				d[i] = 0;
		}
		else{
			c = false;
			break;
		}
	}
	if(c)
	{
		for(int i = 0;i < 5;i++)
			cout << d[i];
	}
	else cout << "error";
	cout << endl;
}
void postnet::output_bar()
{
	for(int i = 0;i < 4;i++)
	{
		if(a[0][i] == 0)
			cout << "11000" << " ";
		else if(a[0][i] == 1)
			cout << "00011" << " ";
		else if(a[0][i] == 2)
			cout << "00101" << " ";
		else if(a[0][i] == 3)
			cout << "00110" << " ";
		else if(a[0][i] == 4)
			cout << "01001" << " ";
		else if(a[0][i] == 5)
			cout << "01010" << " ";
		else if(a[0][i] == 6)
			cout << "01100" << " ";
		else if(a[0][i] == 7)
			cout << "10001" << " ";
		else if(a[0][i] == 8)
			cout << "10010" << " ";
		else if(a[0][i] == 9)
			cout << "10100" << " ";
	}
	if(a[0][4] == 0)
		cout << "11000";
	else if(a[0][4] == 1)
		cout << "00011";
	else if(a[0][4] == 2)
		cout << "00101";
	else if(a[0][4] == 3)
		cout << "00110";
	else if(a[0][4] == 4)
		cout << "01001";
	else if(a[0][4] == 5)
		cout << "01010";
	else if(a[0][4] == 6)
		cout << "01100";
	else if(a[0][4] == 7)
		cout << "10001";
	else if(a[0][4] == 8)
		cout << "10010";
	else if(a[0][4] == 9)
		cout << "10100";
	cout << endl;
}
