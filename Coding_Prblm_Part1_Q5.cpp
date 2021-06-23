/* 
Sample Input : (input the day, month and year as separate integers)
Birth date : 25/9/1996
Present date : 21/9/2019

Sample Output : 
Years : 22, Months : 11, days : 26

Run the will_Grant() with 72 and 57 as input. 
The ouput will come "Not Granted" and "Granted", respectively.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int is_Leap_Year(int);  // to find out whether the years are leap years
void calculate(int,int,int,int,int,int); // to calculate the days and weeks of life
int is_Prime(int);  // to check which factors are prime and which are not
void will_Grant(int);  // to check if the will would be granted or not

int is_Leap_Year(int yr)
{
	// since only the century years perfectly divisible by 400 are leap years
	if((yr%4==0 && yr%100!=0) || (yr%400==0))
		return 1;
	else
		return 0;
}

void calculate(int b_d,int b_m,int b_y,int p_d,int p_m,int p_y)
{
	int i=0,p=0,q=0,days=0,mon=0,yr=0,tot_days=0,weeks=0;
	int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
	p=is_Leap_Year(b_y);
	q=is_Leap_Year(p_y);
	if(p || q)
	{
		for(i=0;i<2;i++)
			if(i==1)
				months[i]=29;
	}
	if(b_d>p_d)
	{
		p_d+=months[b_m-1];
		p_m-=1;
	}
	if(b_m>p_m)
	{
		p_m+=12;
		p_y-=1;
	}
	yr=p_y-b_y;
	mon=p_m-b_m;
	days=p_d-b_d;
	tot_days=(yr*365.242199+mon*30.417+days);
	printf("Total days : %d \n",tot_days);
	weeks=tot_days/7;
	will_Grant(57);
}

int is_Prime(int n)
{
	int i=0,flag=1;
	if(n==2 || n==3)
		return 1;
	else
	{
		for(i=2;i<=int(sqrt(n));i++)
		{
			if(n%i==0)
			{
				flag=0;
				break;
			}
		}
		return flag;
	}
}

void will_Grant(int w)
{
	int i=0,pf=0,npf=0,k=0;
	for(i=2;i<=w/2;i++)
	{
		if(w%i==0)
		{
			k=is_Prime(i);
			if(k)
				pf+=i;
			else
				npf+=i;
		}
	}
	if(pf>npf)
		printf("Granted. \n");
	else
		printf("Not granted. \n");
}

int main()
{
	int b_d=0,b_m=0,b_y=0,p_d=0,p_m=0,p_y=0;
	scanf("%d %d %d %d %d %d",&b_d,&b_m,&b_y,&p_d,&p_m,&p_y);
	calculate(b_d,b_m,b_y,p_d,p_m,p_y);
	return 0;
}
