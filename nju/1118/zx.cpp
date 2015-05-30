#include <iostream>
using namespace std;
int main()
{int a[64],b[64],c[64],d,i,j,k1,k2,k,n;
  i=0,j=0,k=-1,n=0;
  for(i=0;i<=64;i++)
  {cin>>d;

  if(d!=-1)
  {a[i]=d;
  k1=i;}
  if(d==-1)
  break;
  } 
  for(j=0;j<=64;j++)
  {cin>>d;

  if(d!=-1)
  {b[j]=d;
  k2=j;}
  if(d==-1)
  break;
  }
  
  for(i=0;i<=k1;i++)
  {for(j=0;j<=k2;j++)
  if(a[i]==b[j])
 {k++;
  c[k]=a[i];
   }}
   if(k==-1)
   cout<<" "<<endl;
   else
   for(i=0;i<=k;i++)
   {if(i!=k)
   cout<<c[i]<<" ";
   else
   cout<<c[i]<<endl;}
   
   for(i=0;i<=k1;i++)
   {c[i]=a[i];}
   for(j=0;j<=k2;j++)
   {k=-1;
   for(i=0;i<=k1;i++)
   {
   if(b[j]!=a[i])
    k++;
	else
	break;}
    if(k==k1)
   {c[k1+n+1]=b[j];
   n++;}
   	}
   for(i=0;i<=k1+n;i++)
   {if(i!=k1+n)
   cout<<c[i]<<" ";
   else
   cout<<c[i]<<endl;}
   
   n=0;
   for(i=0;i<=k1;i++)
   {k=-1;
   for(j=0;j<=k2;j++)
   {if(b[j]!=a[i])
     k++;}
     if(k==k2)
     {c[n]=a[i];
	 n++;  	  	
   }}
   if(n==0)
   cout<<" "<<endl;
   else
   for(i=0;i<=n-1;i++)
   {if(i!=n-1)
   cout<<c[i]<<" ";
   else
   cout<<c[i]<<endl;
   }
   
   k=-1;
   for(i=0;i<=k1;i++)
   {
   for(j=0;j<=k2;j++)
   if(b[j]==a[i])
   k++;
   	}
   	if(k==k1)
   	cout<<"ture"<<endl;
   	else
   	cout<<"false"<<endl;
   	system("pause");
  	return 0;
}
