#include<iostream>

using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int **a = new int *[n];
	for(int i=0;i<n;i++)
	{
		a[i]= new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 0;
		}
	}
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		a[x-1][y-1] = 1;
		a[y-1][x-1] = 1;
		
	}
	int count = 0;
	for(int i = 0;i<n;i++)
	{
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1) sum++;
		}
		if(sum%2==1) count++;
	}
	if(count!=0&&count!=2) cout<<"-1";

	return 0;
}
