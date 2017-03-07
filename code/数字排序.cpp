#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PAIR;//定义一个pair类型 

bool cmp(const PAIR a,const PAIR b)
{
	return (a.second>b.second)||(a.second==b.second&&a.first<b.first);
}
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> count;
	for(int i=0;i<n;i++)
	{
		++count[a[i]];
	}
	vector<PAIR> res;
	for(map<int,int>::iterator it = count.begin();it!=count.end();it++)
	{
		res.push_back(make_pair(it->first,it->second));
	 } 
	 
	 sort(res.begin(),res.end(),cmp);
	 
	 
	 
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].first<<' '<<res[i].second<<endl;
	}
	
	return 0;
 } 
