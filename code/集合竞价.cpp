#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct Record
{
	string  m;//买还是卖 
	double p;
	int s;
	bool e;//是否被删除 
}; 

int main()
{
	string s1;
	vector<Record> r;//存储记录的 
	int line; 

	while(cin>>s1)
	{
		Record temp;
		if(s1=="buy")
		{
			
			cin>>temp.p>>temp.s;
			temp.m = "buy";
			temp.e = false;
			r.push_back(temp);
		}
		else if(s1=="sell")
		{
			cin>>temp.p>>temp.s;
			temp.m = "sell";
			temp.e = false;
			r.push_back(temp);
			
		}
		else if(s1=="cancel")//cancel也可能被撤销 
		{
			cin>>line;
			r[line-1].e = true;
			temp.m ="cancel";
			temp.e = false;
			temp.p = 0;
			temp.s = 0;
			r.push_back(temp);
		}
		else
		{
			break;
		}
	}
	double price = 0;
	int b_sum = 0;
	int s_sum = 0;
	int sum = 0;
	int max = 0;
	double max_p = 0;
	set<double> Price;
	for(int i=0;i<r.size();i++)
	{
		if(r[i].m!="cancel"&&!r[i].e)
		{
			Price.insert(r[i].p);
		}
	}

	
	for(set<double>::iterator it=Price.begin();it!=Price.end();it++)
	{
		price = *it;

		b_sum = s_sum =sum = 0;
		for(int i=0;i<r.size();i++)
		{
			if(r[i].m=="buy"&&!r[i].e&&r[i].p>=price) b_sum+=r[i].s;
			if(r[i].m=="sell"&&!r[i].e&&r[i].p<=price) s_sum+=r[i].s;
			
		}
		sum = min(b_sum,s_sum);
		if(sum>=max)
		{
			max = sum;
			max_p = price;
		}
	}
	printf("%.2f ",max_p);//输出保留两位小数 
	cout<<max<<endl; 
}
