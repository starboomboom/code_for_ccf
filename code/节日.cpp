#include<iostream>
using namespace std;
bool is_leapYear(int y)
{
	return ((y%4==0)&&(y%100!=0)||(y%400==0)) ;
 } 
int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 int Week_Day(int y,int month)//某一年的月份是 
 {
 	int count = 0;
 	for(int i = 1850;i<y;i++)
	 {
	 	if(is_leapYear(i))
	 	{
	 		count++;
		 }
	  } 
	  
	  int day = (y-1850)*365+count;//到y年一月一日的日期数

	  if(is_leapYear(y))
	  {
	  	m[1] =29;
	   }
	   else
	   {
	   	m[1] = 28;
	   }
	   if(month==1) day =day;
	   else
	   {
	   		for(int i=0;i<month-1;i++)
	   		{
	   			day+=m[i];
			   }
		} 
		
		int week_d = (day%7+2)%7;
		if(week_d==0) week_d = 7; 
		
		return week_d;
	   
	   
	   
	  
 }
int main()
{
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	
	for(int kk = y1;kk<=y2;kk++)
	{
	
	
	int G = Week_Day(kk,a);
	
	
	int day = 0;
	if(G<=c)
	 {
		day = 1+(c-G)+7*(b-1);
	  }
	  else 
	  {
	  	day = c+8-G+7*(b-1);
	  }

	  if(is_leapYear(kk)) m[1] =29;
	  else
	  	 m[1] = 28;
	  	 
	  if(day>m[a-1])  cout<<"none"<<endl;
	  else
	  {
	  	cout<<kk<<"/";
	  	if(a<10) cout<<"0"<<a<<"/";
	  	else
	  	{
	  		cout<<a<<"/";
		}
		  
		if(day<10) cout<<"0"<<day;
		else
		  	cout<<day;
		cout<<endl; 
		
	  }
	  	
}
	return 0;
 } 
