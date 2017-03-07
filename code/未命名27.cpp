#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int xx=0,int yy=0)
	{
		x  = xx;
		y =  yy;
	}
};

/*bool can_arrive(Pos B,char **a,int R,int C)
{
	if(a[B.x][B.y]=='S'||a[B.x][B.y]=='T') return true;
	queue<Pos> q;
	q.push(B);
	bool marked[50][50];
	
	while(!q.empty())
	{
		Pos temp = q.front();
		q.pop();
		int x1 = temp.x;
		int y1 = temp.y;
		if(!marked[temp.x][temp.y])
		{
			marked[temp.x][temp.y] = true;
			if(a[temp.x][temp.y]=='T'||a[temp.x][temp.y]=='S')
			{
				return true;
				
			}
			if(a[temp.x][temp.y]=='+')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				if(x1-1>=0&&a[x1-1][y1]!='#'&&!marked[x1-1][y1])
				{
					q.push(Pos(x1-1,y1));
				}
				if(y1+1<C&&a[x1][y1+1]!='#'&&!marked[x1][y1+1])
				{
					q.push(Pos(x1,y1+1));
				}
				if(y1-1>=0&&a[x1][y1-1]!='#'&&!marked[x1][y1-1])
				{
					q.push(Pos(x1,y1-1));
				}
			}
			if(a[temp.x][temp.y]=='-')
			{
				if(y1+1<C&&a[x1][y1+1]!='#'&&!marked[x1][y1+1])
				{
					q.push(Pos(x1,y1+1));
				}
				if(y1-1>=0&&a[x1][y1-1]!='#'&&!marked[x1][y1-1])
				{
					q.push(Pos(x1,y1-1));
				}
			}
			if(a[temp.x][temp.y]=='|')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				if(x1-1>=0&&a[x1-1][y1]!='#'&&!marked[x1-1][y1])
				{
					q.push(Pos(x1-1,y1));
				}
			}
			if(a[temp.x][temp.y]=='.')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				
			}
			
		}
		
	}
	
	return false;
	
	
}*/

int main()
{
	int R,C;
	cin>>R>>C;
	bool flag = false;
	bool marked[50][50];
	char **a = new char *[R];
	for(int i=0;i<R;i++)
	{
		a[i] = new char[C];
	}
	Pos Start;
	Pos T;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='S') 
			{
				Start.x = i;
				Start.y = j;
			}
			if(a[i][j]=='T')
			{
				T.x  = i;
				T.y  = j;
			}
		}
	}
	queue<Pos> q;
	q.push(Start);
	vector<Pos> vis;
	while(!q.empty())
	{
		Pos temp = q.front();
		q.pop();
		int x1 = temp.x;
		int y1 = temp.y;
		cout<<x1<<" "<<y1<<" "<<a[x1][y1]<<endl;
		if(!marked[temp.x][temp.y])
		{
			marked[temp.x][temp.y] = true;
			vis.push_back(temp);
			if(a[temp.x][temp.y]=='T')
			{
				flag = true;
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				if(x1-1>=0&&a[x1-1][y1]!='#'&&!marked[x1-1][y1])
				{
					q.push(Pos(x1-1,y1));
				}
				if(y1+1<C&&a[x1][y1+1]!='#'&&!marked[x1][y1+1])
				{
					q.push(Pos(x1,y1+1));
				}
				if(y1-1>=0&&a[x1][y1-1]!='#'&&!marked[x1][y1-1])
				{
					q.push(Pos(x1,y1-1));
				}
			}
			if(a[temp.x][temp.y]=='+'||a[temp.x][temp.y]=='S')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					cout<<"об"<<endl;
					q.push(Pos(x1+1,y1));
				}
				if(x1-1>=0&&a[x1-1][y1]!='#'&&!marked[x1-1][y1])
				{
					cout<<"ио"<<endl;
					q.push(Pos(x1-1,y1));
				}
				if(y1+1<C&&a[x1][y1+1]!='#'&&!marked[x1][y1+1])
				{
					cout<<"ср"<<endl;
					q.push(Pos(x1,y1+1));
				}
				if(y1-1>=0&&a[x1][y1-1]!='#'&&!marked[x1][y1-1])
				{
					cout<<"вС"<<endl;
					q.push(Pos(x1,y1-1));
				}
			}
			if(a[temp.x][temp.y]=='-')
			{
				if(y1+1<C&&a[x1][y1+1]!='#'&&!marked[x1][y1+1])
				{
					q.push(Pos(x1,y1+1));
				}
				if(y1-1>=0&&a[x1][y1-1]!='#'&&!marked[x1][y1-1])
				{
					q.push(Pos(x1,y1-1));
				}
			}
			if(a[temp.x][temp.y]=='|')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				if(x1-1>=0&&a[x1-1][y1]!='#'&&!marked[x1-1][y1])
				{
					q.push(Pos(x1-1,y1));
				}
			}
			if(a[temp.x][temp.y]=='.')
			{
				if(x1+1<R&&a[x1+1][y1]!='#'&&!marked[x1+1][y1])
				{
					q.push(Pos(x1+1,y1));
				}
				
			}
			
		}
		
	}
	
	cout<<vis.size()<<endl;
	if(!flag)
	{
		cout<<"I'm stuck!";
		return 1;
	}
	/*int count = 0;
	for(int i=0;i<vis.size();i++)
	{
		if(can_arrive(vis[i],a,R,C))
		{
			count++;
		}
	}
	int res = vis.size()-count;
	//cout<<res;*/	
	return 0;

}


