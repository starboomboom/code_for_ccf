#include<iostream>
#include<map> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> res;
	
	for(int i=0;i<n;i++)
	{
		++res[a[i]];
	}
	
	
	int max = 0;
	int i_max = 0;
	for(map<int,int>::iterator it = res.begin();it!=res.end();it++)
	{
		if(it->second>max)
		{
			max = it->second;
			i_max = it->first;

		}
		else if(it->second==max)
		{
			if(it->first<i_max)
			{
				i_max = it->first;
			}
		}
	}
	
	cout<<i_max;
	
}
