#include<iostream>
using namespace std;
bool is_leapYear(int y)
{
	if(y%4==0&&y%100!=0||y%400==0) return true;
	else
	{
		return false;
	}
}
int main()
{
	int  y,d;
	cin>>y>>d;
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(is_leapYear(y)) month[1] = 29;
	int sum = 0;
	int m = 0;
	int date  =0;
	for(int i=0;i<12;i++)
	{
		sum+=month[i];
		if(sum>d)
		{
			m = i;
			break;
		}
	}
	//边界情况的处理 
	if(sum==d)
	{
		cout<<12<<endl;
		cout<<31<<endl;
		return 0;
	}
	sum = sum-month[m];
	date = d - sum;
	if(date==0)
	{
		cout<<m<<endl;
		cout<<month[m-1]<<endl;
	}
	else
	{
		cout<<m+1<<endl;
		cout<<date<<endl; 
	 } 

	return 0;
}
