#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int max = 0;
	for(int i=0;i<n;i++)
	{
		int left=0;
		int right = 0;
		while(i-left>=0&&a[i-left]>=a[i]) left++;
		while(i+right<n&&a[i+right]>=a[i]) right++;
		int s = a[i]*(left+right-1);
		if(s>max)
		{
			max = s;
		}
		
	 } 
	 
	cout<<max;
	return 0;
}
