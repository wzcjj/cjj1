#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm> 
#include <functional>
#include <utility> 
#include <queue>
#include <set>

using namespace std;

int n;
int le;
pair<vector<int>, vector<int> > p;
pair<vector<int>, vector<int> > get_input()
{
	
	int tx,ty;
	pair<vector<int>, vector<int> >temp;
	
	n = 0;
	tx = -9999;
	ty = -9999;
	temp.first.push_back(-9999);
	temp.second.push_back(-9999);//useless
	while (tx!=0||ty!=0)
	{
		scanf("%d%d",&tx,&ty);
		temp.first.push_back(tx);
		temp.second.push_back(ty);
		n++;

	}
	n--;
	return temp;

}
bool cmpa(pair<vector<int>, vector<int> >&pp,int a, int b)
{
	int lena, lenb;
	lena = (pp.first[a] * pp.first[a]) + (pp.second[a] * pp.second[a]);
	lenb = (pp.first[b] * pp.first[b]) + (pp.second[b] * pp.second[b]);
	if (lena > lenb)
		return true;
	else
		return false;

}
void maxheapify(pair<vector<int>, vector<int> >&pp,int i) 
{
	int lf = i * 2; 
	int rt = i * 2 + 1;
	int largest;
	if (lf <= le && cmpa(pp, lf, i))
		largest = lf;
	else largest = i;
	if (rt <= le && cmpa(pp,rt,largest))
		largest = rt;
	if (largest != i) {
		
		swap(pp.first[i], pp.first[largest]);                 
		swap(pp.second[i], pp.second[largest]);
		maxheapify(pp,largest);
	}
}

void buildmaxheap(pair<vector<int>, vector<int> >&pp) 
{
	for (int i = n/2 ; i >= 1; i--)
		maxheapify(pp,i);
}
void heap_sort(pair<vector<int>, vector<int> > &q)
{
	pair<vector<int>, vector<int> >pp = q;
	le = n;
	buildmaxheap(pp);
	
	for (int i = n; i >=2; i--) 
	{
		swap(pp.first[ 1], pp.first[i]);
		swap(pp.second[1], pp.second[i]);
		le--;
		maxheapify(pp,1);
	}
	
	printf("%d", ((pp.first[1] * pp.first[1]) + (pp.second[1] * pp.second[1])));
	for (int i = 2; i<=n; i++)
		printf(" %d", ((pp.first[i]*pp.first[i])+(pp.second[i]*pp.second[i])));
	printf("\n");

}
struct pqcmp
{
	 bool operator () (pair<int, int>&a , pair<int, int> &b) //reload () not >
	{
		return a.first*a.first + a.second*a.second > b.first*b.first + b.second*b.second;
	}
};
struct mscmp
{
	bool operator()(pair<int, int> x, pair<int, int> y)
	{
		return x.first*x.first + x.second*x.second < y.first*y.first + y.second*y.second;
	}
};
void priority_queue_sort(pair<vector<int>, vector<int> > &pp)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, pqcmp> ptemp;
	pair<int, int> x;
	for (int i = 1; i <= n; i++)  
	{
		x.first = pp.first[i];
		x.second = pp.second[i];
		ptemp.push(x);
	}
	x = ptemp.top();
	printf("%d", (x.first*x.first) + (x.second*x.second));
	ptemp.pop();
	while (!ptemp.empty()) 
	{
		x = ptemp.top();
		printf(" %d", (x.first*x.first) + (x.second*x.second));
		ptemp.pop();
	}
	cout << endl;
}

void set_sort(pair<vector<int>, vector<int> > pp)
{
	multiset<pair<int, int>, mscmp> ptemp;
	pair<int, int> x;
	for (int i = 1; i <= n; i++)  {
		x.first = pp.first[i];
		x.second = pp.second[i];
		ptemp.insert(x);
	}
	multiset<pair<int, int>, pqcmp>::iterator pointt;
	pointt = ptemp.begin();
	x = *pointt;
	printf("%d", x.first*x.first + x.second*x.second);
	pointt++;
	for (pointt; pointt != ptemp.end(); pointt++) {
		x = *pointt;
		printf(" %d", x.first*x.first + x.second*x.second);
	}
	printf("\n");

}
int main(int argc, char *argv[])
{
	
	
	
	p=get_input();

	heap_sort(p);

	priority_queue_sort(p);

	set_sort(p);


}
