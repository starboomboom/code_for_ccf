#include<iostream>
#include<string>
#include<vector>
using namespace std;
string to_xiaoxie(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i] = s[i]-'A'+'a';
		}
	}
	
	return s;
}

bool is_substr(string s1,string s2)
{
	for(int i=0;i<=s2.size()-s1.size();i++)
	{
		int k = 0;
		while(k<s1.size())
		{
			if(s1[k]==s2[i+k])
			{
				k++;
			}
			else
			{
				break;
			}
		}
		if(k==s1.size())
		{
			return true;
		}



	}
	
	return false;
}
int main()
{
	string s;
	cin>>s;
	int min_gan;
	cin>>min_gan;
	int n;
	cin>>n;
	vector<string> Str;
	string s1;
	for(int i=0;i<n;i++)
	{
		cin>>s1;
		Str.push_back(s1);
	}
	vector<string> res;
	if(min_gan==0)//大小写不敏感 
	{
		string temp1 = to_xiaoxie(s);
		for(int i=0;i<Str.size();i++)
		{
			 string temp2 = to_xiaoxie(Str[i]);
			 if(is_substr(temp1,temp2))
			 {
			 	res.push_back(Str[i]);
			 }
		}
	}
	else//大小写敏感 
	{
		for(int i=0;i<Str.size();i++)
		{
			 if(is_substr(s,Str[i]))
			 {
			 	res.push_back(Str[i]);
			 }
		}
	}
	
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	 } 
	return 0;
}
