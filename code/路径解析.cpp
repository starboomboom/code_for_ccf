#include<iostream>
#include<string>
#include<vector>
using namespace std;
//这一题不太会 
vector<string> split(string str,string ch);
string handle(vector<string> v);



int main()
{
	int p;
	cin>>p;
	string curPath;
	cin>>curPath;//当前路径
	vector<string> vCurPath;
	vCurPath = split(curPath,"/");
	
	string *arr = new string[num];
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	 } 
	 
	 //计算
	 vector<string> v;
	 for(int i=0;i<num;++i)
	 {
	 	v = split(arr[i],"/");
	 	string res = handle(v);
	 	cout<<res<<endl;
	  } 
	 
	return 0; 
}

vector<string> split(string str,string ch)
{
	int a=0,b=0;
	b = str.find(ch,a);
	string temp;
	vector<string> v;
	while(b!=string::npos){
		temp = str.substr(a,b-a);
		v.push_back(temp);
		a = b+1;
		b = str.find(ch,a);
	}
	
	temp = str.substr(a);
	v.push_back(temp);
	return v;
}

string handle(vector<string> v)
{

}
