#include <iostream>
#include<cstdio>
using namespace std;
struct node
{
	int character;
	node *p;
	long long f;
	node(int fr,int c)
	{
		character=c;
		f=fr;
	}
	node()
	{
	}
};
void sort(node *b[],int n)
{
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if((*b[j]).f>(*b[j+1]).f)
			{
				node *temp=new node;
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
}
void insert(node *newnode,node *b[],int number)
{
	int fre=(*newnode).f;
	for(int i=number;i>=0;i--)
	{
		if(fre<(*b[i]).f)
		{
			b[i+1]=b[i];
		}
		else
		{
			b[i+1]=newnode;
			break;
		}
	}
}
int main()
{
	int n;
	int fr,c;
	while(cin>>n)
	{
		node **a=new node *[n+1];
	    node **b=new node *[n+1];
	    int number=n;
		for(int i=1;i<=n;i++)
		{
			cin>>fr>>c;
			node *x=new node;
			(*x).f=fr;
			(*x).character=c;
			(*x).p=x;
		    a[i]=x;
			b[i]=x;
		}
		sort(b,n);
		while(number>1)
		{
    		node *newnode=new node;
    	    (*newnode).f=(*b[1]).f+(*b[2]).f;
    		(*newnode).character=-100;
    		(*b[1]).p=newnode;
    		(*b[2]).p=newnode;
    		for(int i1=1;i1<=number-2;i1++)
    		{
    			b[i1]=b[i1+2];
    		}
    		number-=2;
    		(*newnode).p=newnode;
    		insert(newnode,b,number);
    		number+=1;
		}
		long long cost=0;
		for(int j=1;j<=n;j++)
		{
			node *t;
			t=a[j];
			long long cost1=0;
			while((*t).p!=t)
			{
				cost1++;
				t=(*t).p;
			}
			cost=cost+(*a[j]).f*cost1;
		}
		cout<<cost<<endl;
	}
	return 0;
}
