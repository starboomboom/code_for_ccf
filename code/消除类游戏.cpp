#include<iostream>
using namespace std;
bool can_erase(int **a,int i,int j,int n,int m)
{
	int left = 0;
	int right = 0;
	int top = 0;
	int down = 0;
	while(j+right<m&&a[i][j+right]==a[i][j]) right++;
	while(j-left>=0&&a[i][j-left]==a[i][j])  left++;
	while(i+down<n&&a[i+down][j]==a[i][j]) down++;
	while(i-top>=0&&a[i-top][j]==a[i][j]) top++;
	if(right+left-1>=3||top+down-1>=3) return true;
	else
	{
		return false;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	int **a = new int *[n];
	bool **b = new bool *[n];
	for(int i=0;i<n;i++)
	{

		a[i] = new int[m];
		b[i] = new bool[m];

	 } 
	 
	 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	 }
	 
	for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		b[i][j] = false;
		 }
		 
	 }

	 for(int i =0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(can_erase(a,i,j,n,m))
	 		{
	 			b[i][j] = true;
			 }
		 }
	 }
	 
	 
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(b[i][j])
	 		{
	 			a[i][j] = 0;
			 }
			 
			 cout<<a[i][j]<<' ';
		 }
		 
		 cout<<endl;
	 }
	 //new后面可能需要delete，不过不delete也不算错 
	 for(int i=0;i<n;i++)
	 {
	 	delete [] a[i];
	 	delete [] b[i];
	 }
	 delete []a;
	 delete []b;
	 
}
