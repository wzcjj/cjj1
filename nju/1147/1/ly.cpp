#include <cstdio>
#include <vector>
#include <utility> 
#include <queue>
#include <set>

using namespace std;

int len=0, n;
pair<vector<int>, vector<int> > p1;

pair<vector<int>, vector<int> > get_input() {
	
	pair<vector<int>, vector<int> > p0;
	int x, y;
	
	p0.first.push_back (0);
	p0.second.push_back (0);
	scanf("%d%d", &x, &y);
	while (!(x==0 && y==0)) {
		len++;
		p0.first.push_back (x);
		p0.second.push_back (y);
		scanf("%d%d", &x, &y);
	}
	return p0;
}

int cal(pair<vector<int>, vector<int> > &x, int i) {
	return x.first[i]*x.first[i]+x.second[i]*x.second[i];
}

void swap(pair<vector<int>, vector<int> > &p1, int x, int y) {
		int z=p1.first[x];
		p1.first[x]=p1.first[y];
		p1.first[y]=z;
		z=p1.second[x];
		p1.second[x]=p1.second[y];
		p1.second[y]=z;
}

void max_heapify(int i) {
	int l=i*2, r=i*2+1, largest;
	if (l<=n && cal(p1, l)>cal(p1, i)) 
		largest=l;
	else largest=i;
	if (r<=n && cal(p1, r)>cal(p1, largest)) 
		largest=r;
	if (largest!=i) {
		swap(p1, i, largest);
		max_heapify(largest);
	}
}

void build_maxheap() {
	for (int i=len/2; i>=1; i--) 
		max_heapify(i);
}

void heap_sort(pair<vector<int>,vector<int> > q) {
	p1=q;
	n=len;
	build_maxheap();
	for (int i=len; i>=2; i--) {
		swap(p1, 1, i);
		n--;
		max_heapify(1);
	}
	for (int i=1; i<len; i++)
		printf("%d ", cal(p1, i));
	printf("%d\n", cal(p1, len));
}

struct cmp{
	bool operator()(pair<int, int> x, pair<int, int> y) {
		return x.first*x.first+x.second*x.second > y.first*y.first+y.second*y.second;
	}
};

void priority_queue_sort(pair<vector<int>, vector<int> > q) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> p2;
	pair<int, int> x;
	for (int i=1; i<=len; i++)  {
		x.first=q.first[i];
		x.second=q.second[i];
		p2.push(x);
	}
	x=p2.top();
	printf("%d", x.first*x.first+x.second*x.second);
	p2.pop();
	while (!p2.empty()) {
		x=p2.top();
		printf(" %d", x.first*x.first+x.second*x.second);
		p2.pop();
	}
	printf("\n");
}

struct comp{
	bool operator()(pair<int, int> x, pair<int, int> y) {
		return x.first*x.first+x.second*x.second < y.first*y.first+y.second*y.second;
	}
};

void set_sort(pair<vector<int>,vector<int> > q) {
	multiset<pair<int, int>, comp> p3;
	pair<int, int> x;
	for (int i=1; i<=len; i++)  {
		x.first=q.first[i];
		x.second=q.second[i];
		p3.insert(x);
	}
	multiset<pair<int, int>, cmp>::iterator it;
	it=p3.begin();
	x=*it;
	printf("%d", x.first*x.first+x.second*x.second);
	it++;
	for (it; it!=p3.end(); it++) {
		x=*it;
		printf(" %d", x.first*x.first+x.second*x.second);
	}
	printf("\n");
}

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	
	pair<vector<int>, vector<int> > p;
	p=get_input();
	heap_sort(p);	
	priority_queue_sort(p);
	set_sort(p);
	system("pause");
	return 0;
} 
