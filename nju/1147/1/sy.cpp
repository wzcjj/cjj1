#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>

#define PVV pair <vector <int>, vector <int> >

using namespace std;

struct sy
{
	int x, y;
	sy() {}
	sy(int _x, int _y) {x = _x, y = _y;}
	bool operator < (const sy &a) const
	{
		return x * x + y * y > a.x * a.x + a.y * a.y;
	}
};

struct xy
{
	int x, y;
	xy() {}
	xy(int _x, int _y) {x = _x, y = _y;}
	bool operator < (const xy &a) const
	{
		return x * x + y * y < a.x * a.x + a.y * a.y;
	}
};

int n, m;
xy a[100100];

void swap(int i, int j) {
    xy t;
    t = a[i]; a[i] = a[j]; a[j] = t;
}
 
void MaxHeapify(int i) {
    int k;
    if (i*2 <= m && a[i] < a[i*2])    k = i*2;
    else k = i;
    if (i*2+1 <= m && a[k] < a[i*2+1]) k = i*2+1;
    if (k != i) {
        swap(i, k);
        MaxHeapify(k);
    }
}

PVV get_input()
{
	PVV p;
	int x0, y0;
	while (1)
	{
		scanf("%d%d", &x0, &y0);
		if (x0 == 0 && y0 == 0) break;
		p.first.push_back(x0);
		p.second.push_back(y0);
	}
	return p;
}

void heap_sort(PVV p)
{
	for (int i = 0; i < n; i++)
	{
		a[i].x = p.first[i];
		a[i].y = p.second[i];
	}
	m = n-1;
	for (int i = n/2-1; i >= 0; --i)   MaxHeapify(i);
	for (int i = n-1; i > 0; --i)
	{
            swap(0, i);
            m--;
            MaxHeapify(0);
    }
    for (int i = 0; i < n-1; ++i) printf("%d ", a[i].x * a[i].x + a[i].y * a[i].y);
    printf("%d\n", a[n-1].x * a[n-1].x + a[n-1].y * a[n-1].y);
} 

void priority_queue_sort(PVV p)
{
	priority_queue <sy> q;
	for (int i = 0; i < n; i++)
	{
		q.push(sy(p.first[i], p.second[i]));
	}
	while (!q.empty())
	{
		sy now = q.top();
		q.pop();
		printf("%d", now.x * now.x + now.y * now.y);
		if (!q.empty()) printf(" "); else printf("\n");
	}
}

void set_sort(PVV p)
{
	multiset <xy> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(xy(p.first[i], p.second[i]));
	}
	multiset <xy> :: iterator it = s.begin();
	for (; it != s.end(); it++)
	{
		int x0 = it -> x, y0 = it -> y;
		if (it != s.begin()) printf(" ");
		printf("%d", x0 * x0 + y0 * y0);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	PVV p;
	p = get_input();
	n = p.first.size();
	heap_sort(p);
	priority_queue_sort(p);
	set_sort(p);
	return 0;
}

