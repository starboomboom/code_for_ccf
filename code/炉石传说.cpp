#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct suicong
{
	//int pos;
	int attack;
	int health;
};
int main()
{
	int n;
	cin>>n;
	string s;
	int pos;//位置 
	int attack;
	int health; 
	//两个存放随从的数组  
	vector<suicong> a;	
	vector<suicong> b;
	suicong temp;
	temp.health = 30;
	temp.attack = 0;
	a.push_back(temp);
	b.push_back(temp);
	//加入英雄，英雄编号是0 
	
    bool first = true;
    int attack1;
    int attack2;
    int win = 0;
	for(int i=0;i<n;i++)
	{

		cin>>s;
		if(s=="summon")
		{
			suicong x;
			cin>>pos>>attack>>health;
			x.attack = attack;
			x.health = health;
			
			if(first)
			{
				a.insert(a.begin()+pos,x);
			}
			else
			{
				b.insert(b.begin()+pos,x);
			}

			
		}
		else if(s=="attack")
		{
			cin>>attack1>>attack2;
			if(first)//先手 
			{
				a[attack1].health-=b[attack2].attack;
				b[attack2].health-=a[attack1].attack;
				if(a[attack1].health<=0) a.erase(a.begin()+attack1);
				if(attack2==0)
				{
					if(b[0].health<=0)
					{
						win = 1;
						break;
					}
				 }
				 else
				 {
				 	if(b[attack2].health<=0) b.erase(b.begin()+attack2);
				  } 
			}
			else
			{
				b[attack1].health-=a[attack2].attack;
				a[attack2].health-=b[attack1].attack;
				if(b[attack1].health<=0) b.erase(b.begin()+attack1);
				if(attack2==0)
				{
					if(a[0].health<=0)
					{
						win = -1;
						break;
					}

				}
				else
				{
					if(a[attack2].health<=0) a.erase(a.begin()+attack2);
				}
			}


				
			

		}
		else if(s=="end")
		{
			first = !first;//另外一名玩家开始 
		}
	}
	
	cout<<win<<endl;
	cout<<a[0].health<<endl;
	cout<<a.size()-1<<' ';
	for(int i=1;i<a.size();i++)
	{
		cout<<a[i].health<<' ';	
	}
	cout<<endl;
	cout<<b[0].health<<endl;
	cout<<b.size()-1<<' ';
	for(int i=1;i<b.size();i++)
	{
		cout<<b[i].health<<' ';
	}
	cout<<endl;
	
	return 0;
 } 
