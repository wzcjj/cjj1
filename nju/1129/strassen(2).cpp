#include <iostream>
using namespace std;
int **add(int n,int **a,int **b);//用于处理s=a11+a12 等 
int **delete1(int n,int **a,int **b);//用于处理s=b12-b22等 
int **strassen(int n,int **a,int **b);
int **sum(int n,int **a,int **b,int **c,int **d);//用于处理c11=p3+p4-p1+p6 

void output(int n,int **c);//输出 
int main()
{  int N;  
   cin>>N;
   int i,j;    
int **a=new int *[N];
int **b=new int *[N];
int **c1=new int *[N];
int **c2=new int *[N];//定义4个矩阵 
for(i=0;i<N;i++)
   a[i]=new int[N];
for(i=0;i<N;i++)
   b[i]=new int[N];
for(i=0;i<N;i++)
   c1[i]=new int[N];
for(i=0;i<N;i++)
   c2[i]=new int[N];//定义 
for(i=0;i<N;i++)
for(j=0;j<N;j++)
cin>>a[i][j];
for(i=0;i<N;i++)
for(j=0;j<N;j++)
cin>>b[i][j];//输入 


     c1=strassen(N,a,b);
     c2=strassen(N,b,a);
     output(N,c1);
     output(N,c2);
     
 	return 0;
}
void output(int n,int **c)
{  int i,j;
   for(i=0;i<n;i++)
   for(j<0;j<n-1;j++)
{  cout<<c[i][j]<<" ";
   cout<<c[i][n-1]<<endl;
}
}
int **add(int n,int **a,int **b)
{    int i,j;
 int **c=new int *[n];
       for(i=0;i<n;i++)
            c[i]=new int[n];//定义返回的c 
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     c[i][j]=a[i][j]+b[i][j]; 
     return (c);
	
	
}
int **delete1(int n,int **a,int **b)
{ int i,j;
  int **c=new int *[n];
       for(i=0;i<n;i++)
            c[i]=new int [n];//定义返回的c 
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     c[i][j]=a[i][j]-b[i][j]; 
     return (c);
	
	
}
int **sum(int n,int **a,int **b,int **c,int **d)
{  int i,j;
  int **e=new int *[n];for(i=0;i<n;i++) e[i]=new int[n];//定义返回的矩阵 
      
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  e[i][j]=a[i][j]+b[i][j]-c[i][j]+d[i][j];
  return (e);
	
}
int **strassen(int n,int **a,int **b)
{   
	if (n == 1)
	{
		int **c=new int*[1];
		    c[0]=new int[1];
	c[0][0] = a[0][0] * b[0][0];
	     return(c);
	}
	else
{	    int **s1=new int *[n/2];for(int i=0;i<n/2;i++) s1[i]=new int[n/2];
int **s2=new int *[n/2];for(int i=0;i<n/2;i++) s2[i]=new int[n/2];
int **s3=new int *[n/2];for(int i=0;i<n/2;i++) s3[i]=new int[n/2];
int **s4=new int *[n/2];for(int i=0;i<n/2;i++) s4[i]=new int[n/2];
int **s5=new int *[n/2];for(int i=0;i<n/2;i++) s5[i]=new int[n/2];
int **s6=new int *[n/2];for(int i=0;i<n/2;i++) s6[i]=new int[n/2];
int **s7=new int *[n/2];for(int i=0;i<n/2;i++) s7[i]=new int[n/2];
int **s8=new int *[n/2];for(int i=0;i<n/2;i++) s8[i]=new int[n/2];
int **s9=new int *[n/2];for(int i=0;i<n/2;i++) s9[i]=new int[n/2];
int **s10=new int *[n/2];for(int i=0;i<n/2;i++) s10[i]=new int[n/2];
int **p1=new int *[n/2];for(int i=0;i<n/2;i++) p1[i]=new int [n/2];
int **p2=new int *[n/2];for(int i=0;i<n/2;i++) p2[i]=new int [n/2];
int **p3=new int *[n/2];for(int i=0;i<n/2;i++) p3[i]=new int [n/2];
int **p4=new int *[n/2];for(int i=0;i<n/2;i++) p4[i]=new int [n/2];
int **p5=new int *[n/2];for(int i=0;i<n/2;i++) p5[i]=new int [n/2];
int **p6=new int *[n/2];for(int i=0;i<n/2;i++) p6[i]=new int [n/2];
int **p7=new int *[n/2];for(int i=0;i<n/2;i++) p7[i]=new int [n/2];
int **a11=new int *[n/2];for(int i=0;i<n/2;i++) a11[i]=new int[n/2];
int **a12=new int *[n/2];for(int i=0;i<n/2;i++) a12[i]=new int[n/2];
int **a21=new int *[n/2];for(int i=0;i<n/2;i++) a21[i]=new int[n/2];
int **a22=new int *[n/2];for(int i=0;i<n/2;i++) a22[i]=new int[n/2];
int **b11=new int *[n/2];for(int i=0;i<n/2;i++) b11[i]=new int[n/2];
int **b12=new int *[n/2];for(int i=0;i<n/2;i++) b12[i]=new int[n/2];
int **b21=new int *[n/2];for(int i=0;i<n/2;i++) b21[i]=new int[n/2];
int **b22=new int *[n/2];for(int i=0;i<n/2;i++) b22[i]=new int[n/2];
int **c11=new int *[n/2];for(int i=0;i<n/2;i++) c11[i]=new int[n/2];
int **c12=new int *[n/2];for(int i=0;i<n/2;i++) c12[i]=new int[n/2];
int **c21=new int *[n/2];for(int i=0;i<n/2;i++) c21[i]=new int[n/2];
int **c22=new int *[n/2];for(int i=0;i<n/2;i++) c22[i]=new int[n/2];
int **c=new int *[n];for(int i=0;i<n;i++) c[i]=new int[n];//定义各种提到的矩阵 


  for(int i=0; i<n/2; i++)
  {   
           for(int j=0; j<n/2; j++) 
		   {   
               a11[i][j] = a[i][j];   
               a12[i][j] = a[i][j+n/2];   
               a21[i][j] = a[i+n/2][j];   
               a22[i][j] = a[i+n/2][j+n/2];   
                 
               b11[i][j] = b[i][j];   
               b12[i][j] = b[i][j+n/2];   
               b21[i][j] = b[i+n/2][j];   
               b22[i][j] = b[i+n/2][j+n/2];       
            }           
         
	
}//分为4个小的 
          s1=delete1(n,b12,b22);
          s2=add(n,a11,a12);
          s3=add(n,a21,a22);
          s4=delete1(n,b21,b11);
          s5=add(n,a11,a22);
          s6=add(n,b11,b22);
          s7=delete1(n,a12,a22);
          s8=add(n,b21,b22);
          s9=delete1(n,a11,a21);
          s10=add(n,b11,b12);
          p1=strassen(n/2,a11,s1);
          p2=strassen(n/2,s2,b22);
          p3=strassen(n/2,s3,b11);
          p4=strassen(n/2,a22,s4);
          p5=strassen(n/2,s5,s6);
          p6=strassen(n/2,s7,s8);
          p7=strassen(n/2,s9,s10);//7递归 
c11=sum(n/2,p5,p4,p2,p6);
c12=add(n/2,p1,p2);
c21=add(n/2,p3,p4);
c22=sum(n/2,p5,p1,p3,p7);//高出4小的 
for(int i=0; i<n/2; i++) 
{   
           for(int j=0; j<n/2; j++) 
        {   
               c[i][j] = c11[i][j];   
               c[i][j+n/2] = c12[i][j];   
               c[i+n/2][j] = c21[i][j];   
               c[i+n/2][j+n/2] = c22[i][j];           
                      
         }   
}//合 
  return(c);
}}
