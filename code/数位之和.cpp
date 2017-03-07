#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	while(n>0)
	{
		a.push_back(n%10);
		n = n/10;
	}
	int sum = 0;
	for(int i=0;i<a.size();i++)
	{
		sum+=a[i];
	 }
	 
	 cout<<sum;
	 return 0; 
 } 
