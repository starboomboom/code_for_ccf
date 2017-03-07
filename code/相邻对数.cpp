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
	for(int i=0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			//cout<<a[i]<<","<<a[j]<<endl; 
			if((a[j]-a[i]==1)||(a[i]-a[j]==1))
			{
				count++;
			}
		}
	}
	cout<<count;
	return 0;
 } 
