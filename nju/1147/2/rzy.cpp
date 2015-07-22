
#include <iostream>
#include <vector>

using namespace std;

vector<int> p[400000];
int n, len;

int DFS(vector<int>pp[400000],int t, int f) {
	int u = 0, v = 0,x;
	for (int i = 0; i < pp[t].size(); i++) 
	{
		if (pp[t][i] != f)
		{
			 x = DFS(pp,pp[t][i], t);
			if (x > u)
				v = u, u = x;
			else
				if (x > v) v = x;
		}
	}
	if ((u + v)>len) 
		len = u + v;
	return (u + 1);
}

int main()
{
	cin>>n;
	for (int i = 1; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	len = 0;
	DFS(p,1, 0);
	cout << len;;
}
