#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n<=2) 
	{
		int m = 0;
		cout<<m;
		return 0;
	}
	int count = 0;	
	for(int i=1;i<n-1;i++)
	{
		if((a[i]-a[i-1])*(a[i+1]-a[i])<0)
			count++;
	}
	cout<<count; 
	return 0; 
 } 
