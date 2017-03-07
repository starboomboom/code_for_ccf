#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct Time
{
	int x;
	int y;
 }; 
struct S
{
	int  x1;
	int  y1;
	int step;
	S(int xx =0,int yy=0,int ss = 0)
	{
		x1 = xx;
		y1 = yy;
		step = ss;
	 } 	
};
int main()
{
	int n,m;
	int t;
	cin>>n>>m>>t;
	int r,c,a,b;

	
	Time data[101][101];
	//初始化 ,数组从1开始 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			data[i][j].x = -1;
			data[i][j].y = -1;
		}
	}
	
	
	for(int i=0;i<t;i++)
	{
		cin>>r>>c>>a>>b;
		data[r][c].x = a;
		data[r][c].y =b;		
	}
	
	

	queue<S> re;
	re.push(S(1,1,0));
	int count = 0;
	while(!re.empty())
	{
		S temp = re.front();
		re.pop(); 
		//cout<<temp.x1<<" "<<temp.y1<<" "<<temp.step<<endl;
		if(temp.x1==n&&temp.y1==m)
		{
			count = temp.step;
			break;
		 } 
		 ++temp.step;
		if(temp.x1-1>=1&&(temp.step<data[temp.x1-1][temp.y1].x||temp.step>data[temp.x1-1][temp.y1].y))//可以往左走
		{
				
			re.push(S(temp.x1-1,temp.y1,temp.step));

		} 
		if(temp.x1+1<=n&&(temp.step<data[temp.x1+1][temp.y1].x||temp.step>data[temp.x1+1][temp.y1].y))//可以往左走
		{
			re.push(S(temp.x1+1,temp.y1,temp.step));	 
		} 
		if(temp.y1-1>=1&&(temp.step<data[temp.x1][temp.y1-1].x||temp.step>data[temp.x1][temp.y1-1].y))//可以往左走
		{
			re.push(S(temp.x1,temp.y1-1,temp.step));	 
		} 
		if(temp.y1+1<=m&&(temp.step<data[temp.x1][temp.y1+1].x||temp.step>data[temp.x1][temp.y1+1].y))//可以往左走
		{
			re.push(S(temp.x1,temp.y1+1,temp.step));	 
		} 
		

	}
	
	cout<<count;
	
	return 0;
 } 
