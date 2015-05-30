#include<iostream>
int gcd(int n1, int n2);
class real
{
private:
	int fenzi,fenmu;
public:
	void get(int a, int b)
	{
		fenzi = a;
		fenmu = b;
	}
	int geta()
	{ 
		return fenzi;
	}
	int getb()
	{
		return fenmu;
	}
	void print()
	{
		if (fenzi == 0)
			std::cout << 0;
		else
		{
			int m = gcd(fenzi, fenmu);
			fenzi = fenzi / m;
			fenmu = fenmu / m;
			if (fenmu < 0)
			{
				fenzi = -fenzi;
				fenmu = -fenmu;
			}
			if (fenmu == 1)
				std::cout << fenzi;
			else
			{
				std::cout << fenzi << '/' << fenmu ;
			}
		}
	}

};

int gcd(int n1, int n2)
{
	if (n1%n2 == 0)
		return n2;
	else
		return gcd(n2, n1 % n2);
}
int main()
{
	using namespace std;
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
	int a1, a2, b1, b2;
	int m, n;
	real r1, r2;
	real plus, minus, mul, div;
	while (cin >> a1 >> b1 >> a2 >> b2)
	{
		m = gcd(a1, b1);
		r1.get(a1 / m, b1 / m);
		m = gcd(a2, b2);
		r2.get(a2 / m, b2 / m);
		b1 = r1.getb();
		b2 = r2.getb();
		m = gcd(b1, b2);
		a1 = r1.geta();
		a2 = r2.geta();
		plus.get(a1*b2 / m + a2*b1 / m, b1*b2 / m);
		plus.print();
		cout << ' ';
		minus.get(a1*b2 / m - a2*b1 / m, b1*b2 / m);
		minus.print();
		cout << ' ';
		n = gcd(a1, a2);
		div.get(a1 / n*b2 / m, b1 / m*a2 / n);
		m = gcd(a1, b2);
		n = gcd(a2, b1);
		mul.get(a1*a2 / m / n, b1*b2 / m / n);
		mul.print();
		cout << ' ';
		div.print();
		cout << ' ';
		m = minus.geta();
		if (m >= 0)
			cout << "flase";
		else
			cout << "true";
		cout << endl;
	}
	return 0;
}
