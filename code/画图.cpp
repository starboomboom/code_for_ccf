#include<iostream>
#include<vector>
#include<set>
//这一题不要被重叠面积的计算的思维定式所困扰 
using namespace std;
int main()
{
	int n;
	cin>>n;
	//vector<vector<int> > a;
	int x1,y1,x2,y2;
	bool color[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			color[i][j] = false;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		
		for(int m=x1;m<x2;m++)
		{
			for(int m2=y1;m2<y2;m2++)
			{
				color[m][m2] = true;
			}
		 } 
		
		/*vector<int> temp;
		temp.push_back(x1);
		temp.push_back(y1);
		temp.push_back(x2);
		temp.push_back(y2);
		a.push_back(temp);
		temp.clear();*/
		
	}
	
	int count = 0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			if(color[i][j])
			{
				count++;
			}
		}
	}
	
	cout<<count;

	
	
	return 0; 
}
