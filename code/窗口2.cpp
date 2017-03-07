#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a;
	int x1,x2,y1,y2;
	for(int i = 0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		vector<int> window;
		window.push_back(x1);
		window.push_back(y1);
		window.push_back(x2);
		window.push_back(y2);
		window.push_back(i+1);//´°¿Ú±àºÅ 
		a.push_back(window);
		window.clear();
		
	}
	
	//µã»÷ 
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		int j;
		for(j = n-1;j>=0;j--)
		{
			if(x>=a[j][0]&&x<=a[j][2]&&y>=a[j][1]&&y<=a[j][3])
			{
				cout<<a[j][4]<<endl;
				//vector<int> temp = a[j];
				a.push_back(a[j]);
				
				a.erase(a.begin()+j);
				

				break;
			}
		}
		if(j<0)
		{
			cout<<"IGNORED"<<endl; 
		}
	 } 
	return 0;
 } 
