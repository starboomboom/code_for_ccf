#include<iostream>
//»ð³µÊÛÆ± 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int use[20];
    for(int i=0;i<20;i++)
	{
		use[i] = 0;
	 } 
	 bool check[20][5];
	 for(int i=0;i<20;i++)
	 {
	 	for(int j=0;j<5;j++)
	 	{
	 		check[i][j] = true;
		 }
	 }
	 for(int i = 0;i<n;i++)
	 {
		bool flag = false; 
	 	for(int j = 0;j<20;j++)
	 	{

	 		if(use[j]+a[i]<=5)
	 		{
	 			flag = true;
	 			for(int k=0;k<a[i];k++)
	 			{
	 				int temp = use[j]+k;
	 				cout<<5*j+temp+1<<' ';
	 				check[j][temp] = false;
				 }
				 
				 cout<<endl;
				 use[j] = use[j]+a[i];
				 break;
			 }
		 }
		 
		 if(flag==false)
		 {
		 	int count = 0;
		 	for(int m = 0;m<20;m++)
		 	{
		 		for(int n=0;n<5;n++)
		 		{
		 			
		 			if(check[m][n]==true)
		 			{
		 				check[m][n]=false;
		 				cout<<5*m+n+1<<' ';
		 				count++;
		 				
					 }
					 if(count == a[i]) break;
				 }
				 if(count==a[i]) break;
			 }
			 
			 flag = true;
		 }
	 }
	return 0;
	
 } 
