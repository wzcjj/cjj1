#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum=0, temp=0, i=0;
	char x, a[1000001];
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	while (cin >> x)
	{
		a[i]=x;
		i++;
	}
	n=i-1;
	
    while (n>=0)
	{
		if (a[n]==')') temp++;
		else sum+=temp;
		n--;
	}
	
	cout << sum << endl;

	return 0;
}
