#include<iostream>
using namespace std;
int main()
{
	bool M[10];
	if(!M[0])
	{
		cout<<"hello"<<endl;
	}
}


		if(temp.x1-1>=1&&(temp.step<data[temp.x1-1][temp.y1].x||temp.step>data[temp.x1-1][temp.y1].y))//可以往左走
		{
			if(!marked[temp.step][temp.x1-1][temp.y1])
			{
				marked[temp.step][temp.x1-1][temp.y1] = true;
				re.push(S(temp.x1-1,temp.y1,temp.step));
			}
				 
		} 
		if(temp.x1+1<=n&&(temp.step<data[temp.x1+1][temp.y1].x||temp.step>data[temp.x1+1][temp.y1].y))//可以往左走
		{
			if(!marked[temp.step][temp.x1+1][temp.y1])
			{
				marked[temp.step][temp.x1+1][temp.y1] = true;
				re.push(S(temp.x1+1,temp.y1,temp.step));
			}
				 
		} 
		if(temp.y1-1>=1&&(temp.step<data[temp.x1][temp.y1-1].x||temp.step>data[temp.x1][temp.y1-1].y))//可以往左走
		{
			if(!marked[temp.step][temp.x1][temp.y1-1])
			{
				marked[temp.step][temp.x1][temp.y1-1] = true;
				re.push(S(temp.x1,temp.y1-1,temp.step));
			}
				 
		} 
		if(temp.y1+1<=m&&(temp.step<data[temp.x1][temp.y1+1].x||temp.step>data[temp.x1][temp.y1+1].y))//可以往左走
		{
			if(!marked[temp.step][temp.x1][temp.y1+1])
			{
				marked[temp.step][temp.x1][temp.y1+1] = true;
				re.push(S(temp.x1,temp.y1+1,temp.step));
			}
			 
		} 
