#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int next;	
	int i = 1;
	int max = 0;
	int min = 0;
	int flag = 1;
	int t = 0;
	int t1 = 0;
	while(cin >> next)
	{
		if(next == i)
		{
			if(v.size() == 0)
			{
				cout << next << endl;
				i++;
				flag++;
			}
			else if((max - v.size()) == flag)
			{
				for(int j = flag;j < max;j++)
					cout << j << ",";
				cout << max << endl;
				v.resize(0);
				i = max+1;
				flag = i;
			}
			else{
				for(int j = flag+1;j < max;j++)
				{
					for(int k = 0;k < v.size();k++)
					{
						if(v[k] == j)
							break;
						else t++;
					}
					if(t == v.size())
					{
						t1 = j;
						break;
					}
				}
				i = t1;
				v.push_back(flag);
			}
		}		
		else if(next > i)
		{
			v.push_back(next);
			if(next > max)
				max = next;
		}

	}
	for(i=0;i<v.size();i++)cout<<v[i]<<endl;
	system("pause");
	return 0;
}

			




	
