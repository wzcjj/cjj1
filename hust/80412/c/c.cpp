#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define N 105
int dir[8][2]={{1,0},{0,-1},{-1,0},{0,1},{1,1},{1,-1},{-1,-1},{-1,1}};
int map[N][N];
int dp[N][N][8];
int n;
int tr(int x,int y,int d)
{
	if (!(x>=0 && y>=0 && x<n && y<n) || map[x][y]==0) return 0;
	return tr(dir[d][0]+x,y+dir[d][1],d)+1;
}
	
int main()
{
	int ma;
	char s[N];
	scanf("%d",&n);
	while (n!=0)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%s",&s);		
			for (int j=0;j<n;j++)
				map[i][j]=(s[j]=='#')?0:1;
		}
		ma=2;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<8;k++)
					dp[i][j][k]=tr(i,j,k);
			}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<8;k++)
				{
					if (k<4) ma=max(ma,dp[i][j][k]+dp[i][j][(k+3) % 4]);
					else ma=max(ma,dp[i][j][k]+dp[i][j][4+(k+3) % 4]);
				}
			}
		printf("%d\n",ma-1);
		scanf("%d",&n); 
	}
	return 0;
}


		
