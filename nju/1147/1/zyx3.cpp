#include <iostream>
#include <vector>
#include <utility>
#include <queue>          
#include <functional>
#include <set>

using namespace std;

void change(pair< vector<int>,vector<int> > p0, pair< vector<int>,vector<int> > p, int size)
{
	p.first[0]=0,p.second[0]=0;
    for (int k=1; k<=size; k++)
    {
    	p.first[k]=p0.first[k-1];
    	p.second[k]=p0.second[k-1];
    }
}

pair< vector<int>,vector<int> > get_input()
{
    pair< vector<int>,vector<int> > f;
    int first,last;
    
    while (cin >> first >> last)
    {
    	if (first ==0 && last==0) break;
		f.first.push_back (first);
	    f.second.push_back (last);
    }
    return f;
}

void max_heapify(pair< vector<int>,vector<int> > &p, int size, int i)
{
    int l=i*2, r=2*i+1, largest=0;
    if (l<=size && (p.first[l]*p.first[l]+p.second[l]*p.second[l])>(p.first[i]*p.first[i]+p.second[i]*p.second[i])) largest=l;
    else largest=i;
    if (r<=size && (p.first[r]*p.first[r]+p.second[r]*p.second[r])>(p.first[largest]*p.first[largest]+p.second[largest]*p.second[largest])) largest=r;
    if (largest!=i) 
    {
        int temp1=p.first[i], temp2=p.second[i];
        p.first[i]=p.first[largest];
        p.second[i]=p.second[largest];
        p.first[largest]=temp1;
        p.second[largest]=temp2;
        max_heapify(p, size, largest);
    }
}
 
void build_max_heap(pair< vector<int>,vector<int> > &p, int n)
{
    int size=n;
    for (int j=n/2; j>=1; j--) 
    max_heapify(p, size, j);
}
 
void heap_sort(pair< vector<int>,vector<int> > p, int n)
{
    int size=n;
    build_max_heap(p, n);
    for (int j=n; j>1; j--)
    {
        int temp1=p.first[1], temp2=p.second[1];
        p.first[1]=p.first[j];
        p.second[1]=p.second[j];
        p.first[j]=temp1;
        p.second[j]=temp2;
        size--;
        max_heapify(p ,size ,1);
    }
    
    for (int k=1; k<n; k++)
    {
    	cout <<(p.first[k]*p.first[k]+
		p.second[k]*p.second[k]) << " ";
    }
    cout << (p.first[n]*p.first[n]+p.second[n]*p.second[n]) <<endl;
}

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b) 
	{
		return a.first*a.first+a.second*a.second > b.first*b.first+b.second*b.second;
	}
};

void priority_queue_sort(pair< vector<int>,vector<int> > p, int size)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> ans;
	pair<int, int> temp;
	for (int i=0; i<=size; i++)
	{
		temp.first=p.first[i];
		temp.second=p.second[i];
		ans.push(temp);
	}
	
	int count=0;
	while (!ans.empty()) 
	{
		temp=ans.top();
		count++;
		if (count< size) cout << (temp.first*temp.first+temp.second*temp.second) << " ";
		else cout << (temp.first*temp.first+temp.second*temp.second);
		ans.pop();
	}
	cout << endl;
}

struct compare2
{
	bool operator()(pair<int, int> a, pair<int, int> b) 
	{
		return a.first*a.first+a.second*a.second < b.first*b.first+b.second*b.second;
	}
};

void set_sort(pair<vector<int>,vector<int> > p, int size) 
{
	multiset<pair<int, int>, compare2> ans;
	pair<int, int> temp;
	for (int i=0; i<=size; i++)  
	{
		temp.first=p.first[i];
		temp.second=p.second[i];
		ans.insert(temp);
	}
	multiset<pair<int, int>, compare>::iterator it;
	it=ans.begin();
	temp=*it;
	cout<< temp.first*temp.first+temp.second*temp.second;
	it++;
	for (it; it!=ans.end(); it++) 
	{
		temp=*it;
		cout << " " << temp.first*temp.first+temp.second*temp.second;
	}
	cout << endl;
}


int main(int argc, char *argv[]) {

    pair< vector<int>,vector<int> > p;

    p=get_input();
    
    int size=p.first.size();
  
    heap_sort(p, size);
    
    priority_queue_sort(p,size);

    set_sort(p, size);

}
