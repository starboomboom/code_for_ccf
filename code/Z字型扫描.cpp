#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int **a = new int *[n];
	for(int i=0;i<n;i++)
	{
		a[i] = new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	int k = 0;
	while(k<2*n-1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i+j==k)
				{
					if(k%2==1)
					{
						cout<<a[i][j]<<' ';
					}
					else
					{
						cout<<a[j][i]<<' ';
					}
					
					
				}
				else if(i+j>k)
				{
					break;
				}
			}
		}
		k++;
	}
	
	for(int i=0;i<n;i++)
	{
		delete [] a[i];
		
	} 
	delete []a;
	
	return 0; 
 } 
