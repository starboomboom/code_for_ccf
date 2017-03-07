#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[15][10];
	int b[4][4];
	int c;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>a[i][j];
		}
	 } 
	 
	 for(int i=0;i<4;i++)
	 {
	 	for(int j=0;j<4;j++)
	 	{
	 		cin>>b[i][j];
		 }
	 }
	 
	 cin>>c;//列数
	
	int t[21][10];
	for(int i = 0;i<3;i++)
	{
		for(int j=0;j<10;j++)
		{
			t[i][j] = 0;
		}
	}
	
	for(int i = 3;i<18;i++)
	{
		for(int j=0;j<10;j++)
		{
			t[i][j] = a[i-3][j];
		}
	}
	
	 for(int i=18;i<21;i++)
	 {
	 	for(int j=0;j<10;j++)
	 	{
	 		t[i][j] = 0;
		 }
	 }
	 
	 
	 int k = c-1;
	 
	 int h = 0;
	 bool flag = false;
	 while(h<18)
	 {
	 
	 	int sum = 0;
	 	for(int i=h;i<h+4;i++)
	 	{
	 		for(int j = k;j<k+4;j++)
	 		{

	 			if(b[i-h][j-k]*t[i][j]==1)
	 			{
	 				flag = true;
	 				break;
				 }
		 	}
		 	if(flag)
		 	{
		 		break;
			 }

		 	
	 	}
	 	if(flag)
	 	{
	 		break;
		 }
	 	
	 	h++;
	 
	}
	

	if(h==18)//说明没有任何阻拦 
	{
		int k2 = 0;
		while(true)
		{
			if(b[3-k2][0]==0&&b[3-k2][1]==0&&b[3-k2][2]==0&&b[3-k2][3]==0)
			{
				k2++;
			}
			else
			{
				break;
			}
		}
		
		//cout<<"k2 = "<<k2<<endl; 
		for(int i=14+k2;i<18;i++)
		{
			for(int j=k;j<k+4;j++)
			{
				t[i][j]  = b[i-14-k2][j-k];
			}
		}
		
	}
	else if(h<18)
	{
		
		for(int i=h-1;i<h+3;i++)
		{
			for(int j=k;j<k+4;j++)
			{
				if(t[i][j]==0&&b[i-h+1][j-k]==1)
				{
					t[i][j]=1;
				}
			}
		}
		
	 } 
	 
	 for(int i=3;i<18;i++)
	 {
	 	for(int j=0;j<10;j++)
	 	{
	 		cout<<t[i][j]<<' ';
		 }
		 cout<<endl;
	 }
	
	
	return 0;
 } 
