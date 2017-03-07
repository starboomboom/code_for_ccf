#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	 } 
	 map<int,int> res;
	 for(int i=0;i<n;i++)
	 {
	 	if(res.find(a[i])!=res.end())
	 	{
	 		res[a[i]]++;
		 }
		 else
		 {
		 	res[a[i]] = 1;
		 }
		 
		 cout<<res[a[i]]<<' ';
	 }
 } 
