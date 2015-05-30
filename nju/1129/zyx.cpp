#include <iostream>

using namespace std;

void fadd(int a[][65], int b[][65], int n, int xa, int ya, int xb, int yb, int s[][65], int m)//x y is the site of the first element
{
	for (int i=xa; i<xa+m; i++)
	{
		for (int j=ya; j<ya+m; j++)
		{
			s[i-xa][j-ya]=a[i][j]+b[i-xa+xb][j-ya+yb];
		}
	}
	return;
}

void fminus(int a[][65], int b[][65], int n, int xa, int ya, int xb, int yb, int s[][65], int m)
{
	for (int i=xa; i<xa+m; i++)
	{
		for (int j=ya; j<ya+m; j++)
		{
			s[i-xa][j-ya]=a[i][j]-b[i-xa+xb][j-ya+yb];
		}
	}
	return;
}

void product(int a[][65], int b[][65], int c[][65], int n)
{
	if (n!=1)
	{
		int s1[n/2][65];
    	fminus(b,b,n,0,n/2-1,n/2-1,n/2-1,s1,n/2);
    	for (int i=0; i<n/2; i++)
    	{
    		for (int j=0; j<n/2; j++) cout << s1[i][j];
    		cout << "debug" << endl;
    	}
	    int s2[n/2][65];
    	fadd(a,a,n,0,0,0,n/2-1,s2,n/2);
	    int s3[n/2][65];
    	fadd(a,a,n,n/2-1,0,n/2-1,n/2-1,s3,n/2);
    	int s4[n/2][65];
    	fminus(b,b,n,n/2-1,0,0,0,s4,n/2);
    	int s5[n/2][65];
    	fadd(a,a,n,0,0,n/2-1,n/2-1,s5,n/2);
    	int s6[n/2][65];
    	fadd(b,b,n,0,0,n/2-1,n/2-1,s6,n/2);
    	int s7[n/2][65];
    	fminus(a,a,n,0,n/2-1,n/2-1,n/2-1,s7,n/2);
    	int s8[n/2][65];
    	fadd(b,b,n,n/2-1,0,n/2-1,n/2-1,s8,n/2);
    	int s9[n/2][65];
    	fminus(a,a,n,0,0,n/2-1,0,s9,n/2);
    	int s10[n/2][65];
    	fadd(b,b,n,0,0,0,n/2-1,s10,n/2);
    	
    	int tempa1[65][65],tempa2[65][65],tempa3[65][65],tempa4[65][65],tempb1[65][65],tempb2[65][65],tempb3[65][65],tempb4[65][65];
    	for (int i=0; i<n/2; i++)
    	{
    		for (int j=0; j<n/2; j++)
    		{
    			tempa1[i][j]=a[i][j];
    			tempa2[i][j]=a[i][j+n/2];
    			tempa3[i][j]=a[i+n/2][j];
    			tempa4[i][j]=a[i+n/2][j+n/2];
    			tempb1[i][j]=b[i][j];
    			tempb2[i][j]=b[i][j+n/2];
    			tempb3[i][j]=b[i+n/2][j];
    			tempb4[i][j]=b[i+n/2][j+n/2];
    		}
    	}
    	
    	int p1[n/2][65],p2[n/2][65],p3[n/2][65],p4[n/2][65],p5[n/2][65],p6[n/2][65],p7[n/2][65];
    	product(tempa1, s1, p1, n/2);
    	product(s2, tempb4, p2, n/2);
    	product(s3, tempb1, p3, n/2);
    	product(tempa4, s4, p4, n/2);
    	product(s5, s6, p5, n/2);
    	product(s7, s8, p6, n/2);
    	product(s9, s10, p7, n/2);
    	
    	int c11[n/2][65],c12[n/2][65],c21[n/2][65],c22[n/2][65];
    	for (int i=0; i<n/2; i++)
    	{
    		for (int j=0; j<n/2; j++)
    		{
    			c11[i][j]=p5[i][j]+p4[i][j]-p2[i][j]+p6[i][j];
    			c22[i][j]=p5[i][j]+p1[i][j]-p3[i][j]-p7[i][j];
    			c12[i][j]=p1[i][j]+p2[i][j];
    			c21[i][j]=p3[i][j]+p4[i][j];
    		}
    	}
    	
    	for (int i=0; i<n; i++)
    	{
    		for (int j=0; j<n; j++)
    		{
    			if (i<n/2)
    			{
    				if (j<n/2) c[i][j]=c11[i][j];
    				else c[i][j]=c12[i][j];
    			}
    			else
    			{
    				if (j<n/2) c[i][j]=c21[i][j];
    				else c[i][j]=c22[i][j];
    			}
    		}
    	}
	}
    
    else
    {
    	c[0][0]=a[0][0]*b[0][0];
    }
}

int main()
{
	//input
	int n;
	cin >> n;
	int a[65][65]={0},b[65][65]={0};
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++) cin >> a[i][j];
	}
	for (int i=0; i< n; i++)
	{
		for (int j=0; j<n; j++) cin >> b[i][j];
	}
	
	int c[65][65];
	product(a, b, c, n);
    for (int i=0; i<n; i++)
    {
    	for (int j=0; j<n-1; j++) cout << c[i][j] << " ";
    	cout << c[i][n-1] << endl;
    }
    product(b, a, c, n);
    for (int i=0; i<n; i++)
    {
    	for (int j=0; j<n-1; j++) cout << c[i][j] << " ";
    	cout << c[i][n-1] << endl;
    }
    system("pause"); 
	return 0;
}
