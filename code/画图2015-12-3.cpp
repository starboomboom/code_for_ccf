#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,m,q;//n �У�m�У�q�������� 
	cin>>m>>n>>q;
	
	int x1,y1,x2,y2;
	int c;
	int is_fillAction;
	vector<vector<int> >res;
	//������� 
	for(int i=0;i<q;i++)
	{
		cin>>is_fillAction;
		if(is_fillAction==0)
		{
			cin>>x1>>y1>>x2>>y2;
			vector<int> temp;
			temp.push_back(x1);
			temp.push_back(y1);
			temp.push_back(x2);
			temp.push_back(y2);
			res.push_back(temp);
			temp.clear();
			
		 }
		 else if(is_fillAction==1)
		 {
		 	int x1,y1;
		 	char c;
		 	cin>>x1>>y1>>c;
		 	int c_int  = c-'A';
		 	vector<int> temp1;
		 	temp1.push_back(x1);
		 	temp1.push_back(y1);
		 	temp1.push_back(c_int);
		 	res.push_back(temp1);
		 	temp1.clear();
		 	
		 	
		  } 
	 } 
	 char **a = new char *[n];
	 for(int i=0;i<n;i++)
	 {
	 	a[i] = new char[m];
	  } 
	  
	  for(int i=0;i<n;i++)
	  {
	  	for(int j=0;j<m;j++)
	  	{
	  		a[i][j] = '.';
		  }
	  }
	  //cout<<res.size()<<endl; 
	  for(int i=0;i<res.size();i++)
	  {
	  	 int  Min = 0;
	  	 int  Max = 0;
	  	 if(res[i].size()==4)//���߶β��� 
	  	 {
	  	 	if(res[i][0]==res[i][2])//���� 
			{
				int x = res[i][0];
				Min = res[i][1]<res[i][3]?res[i][1]:res[i][3];
				Max = res[i][1]>res[i][3]?res[i][1]:res[i][3];
			   	for(int k = Min;k<=Max;k++)
			   	{
			   		if(a[k][x]=='-'||a[k][x]=='+')  a[k][x] = '+';
			   		else
			   		{
			   			a[k][x] = '|';
					}
				}
			} 
			else //���� 
			{
				int y =res[i][1];
				Min = res[i][0]<res[i][2]?res[i][0]:res[i][2];
				Max = res[i][0]>res[i][2]?res[i][0]:res[i][2];
				for(int k=Min;k<=Max;k++)
				{
					if(a[y][k]=='|'||a[y][k]=='+') a[y][k] = '+';
					else
					{
						a[y][k] = '-';
					}
				 } 
				
			 } 
		 }
		 else if(res[i].size()==3)//������  ��������� 
		 {
		 	int x0 = res[i][0];
		 	int y0 = res[i][1];
		 	char p = res[i][2]+'A';
		 	if(a[y0][x0]!='-'&&a[y0][x0]!='+'&&a[y0][x0]!='|')  a[y0][x0] = p;  //��ʼ���������� 
		 	
		    queue<pair<int,int> > Tianchong;
		 	Tianchong.push(make_pair(x0,y0));
		 	while(!Tianchong.empty())
		 	{
		 		pair<int,int> temp = Tianchong.front();
		 		Tianchong.pop();
		 		int X0 = temp.first;
		 		int Y0 = temp.second;
		 		if(X0+1<m&&(a[Y0][X0+1]!='-'&&a[Y0][X0+1]!='+'&&a[Y0][X0+1]!='|')&&a[Y0][X0+1] != p)//������ɢ 
		 		{
		 			a[Y0][X0+1] = p;
					 Tianchong.push(make_pair(X0+1,Y0)); 
				 }
				 if(X0-1>=0&&(a[Y0][X0-1]!='-'&&a[Y0][X0-1]!='+'&&a[Y0][X0-1]!='|')&&a[Y0][X0-1]!=p)//������ɢ 
		 		{
		 			a[Y0][X0-1] = p;
					 Tianchong.push(make_pair(X0-1,Y0)); 
				 }
				  if(Y0+1<n&&(a[Y0+1][X0]!='-'&&a[Y0+1][X0]!='+'&&a[Y0+1][X0]!='|')&&a[Y0+1][X0] != p)//������ɢ 
		 		{
		 			a[Y0+1][X0] = p;
					 Tianchong.push(make_pair(X0,Y0+1)); 
				 }
				 
				 if(Y0-1>=0&&(a[Y0-1][X0]!='-'&&a[Y0-1][X0]!='+'&&a[Y0-1][X0]!='|')&&a[Y0-1][X0] !=p)//������ɢ 
		 		{
		 			a[Y0-1][X0] = p;
					 Tianchong.push(make_pair(X0,Y0-1)); 
				 }
			 }
		 	
		 	 


		 }
	
	  }
	  
	  for(int i=n-1;i>=0;i--)
	  {
	  	for(int j=0;j<m;j++)
	  	{
	  		cout<<a[i][j];
		  }
		  cout<<endl;
	  }
	 
	return 0; 
}
