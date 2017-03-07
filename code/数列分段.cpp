#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int count = 0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]!=a[i])
		{
			count++;
		}
	}
	
	count++;
	cout<<count;
	return 0;
 } 
