#include<iostream>
#include<string>
#include<vector>
#include<map>
//得分100 
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	
	cin.get();
	vector<string> a;
	string s;
	for(int i=0;i<m;i++)
	{
		getline(cin,s);
		a.push_back(s);
	}
	map<string,string> table;
	for(int i=0;i<n;i++)
	{
		getline(cin,s); 
		string temp1,temp2;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==' ')
			{
				temp1 = s.substr(0,j);
			}
			else if(s[j]=='"')
			{
				temp2 = s.substr(j+1,s.size()-2-j);
				break;
			}
		}
		table[temp1] = temp2;	
	}
	for(int i=0;i<a.size();i++)
	{
		//k1和k2用来截取字符串 
		int k1 = 0;
		int k2 = 0; 
		vector<string> t;
		//cout<<a[i]<<endl;
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]=='{'&&a[i][j+1]=='{')//要判断一下两个{{,这是我当时得90分的原因 
			{
				
				k2 = j;
				string  temp = a[i].substr(k1,k2-k1);//一定要记住substr的用法，别用错 
				//cout<<k1<<","<<k2<<endl;
				t.push_back(temp);
				int l = j+3;
				while(a[i][l]!=' ')
				{
					l++;
				}
				temp = a[i].substr(j+3,l-j-3);

				t.push_back(table[temp]);
				j = l+2;
				k1 = j+1;
			}
			
		}
		
		
		
		t.push_back(a[i].substr(k1,a[i].size()-k1));//加入最后一个
		
		string res = "";
		for(int kk=0;kk<t.size();kk++)
		{
			res+=t[kk];
		}

		t.clear();
		cout<<res<<endl;
		 
		
		 
	}

	return 0;
	
}
