#include<iostream>
#include<vector>
#include<map> 
#include<string> 
#include<set>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==0)
				count++;
		}
	 } 
	 
	 cout<<count;
	return 0;
 } 
