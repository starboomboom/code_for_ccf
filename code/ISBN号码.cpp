#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int w = 1;
	int sum = 0;
	for(int i=0;i<11;i++)
	{
		if(s[i]=='-') continue;
		else
		{
			int k = s[i]-'0';
			sum+=k*w;
			w++;
			
		}
	}
	//cout<<sum<<endl;
	int t = sum%11;
	char c;
	if(t==10) c = 'X';
	else
	{
		c = t+'0';
	}
	
	if(c==s[12]) cout<<"Right";
	else
	{
		s[12] = c;
		cout<<s;
	}
	return 0; 
 } 
