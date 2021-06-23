#include<stdio.h>

int is_Leap_Year(int);  // to check if the given year is a leap year
int is_Max(float[]);  // to check if the price of non-veg is the maximum price or not 
int is_Valid(float[],int,int);  // to check if the given input is valid or not
void calculate(float[],int,int,int);  // to calculate the daily and monthly expenses

int is_Leap_Year(int yr)
{
	// since only the century years perfectly divisible by 400 are leap years
	if((yr%4==0 && yr%100!=0) || (yr%400==0))
		return 1;
	else
		return 0;
}

int is_Max(float prices[])
{
	int i=0,flag=1;
	float max=prices[1];
	for(i=0;i<5;i++)
	{
		if(prices[i]>max)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

int is_Valid(float prices[5], int month, int yr)
{
	int p=0,q=1,r=1;
	p=is_Max(prices);
	if(month<=0 || month>11)
		q=0;
	if(yr<=0)
		r=0;
	return p*q*r;
}

void calculate(float prices[5], int month, int yr, int k)
{
	if(k)
	{
		int i=0,p=0;
		int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
		double de=0.0,me=0.0;
		p=is_Leap_Year(yr);
		if(p)
		{
			for(i=0;i<2;i++)
				if(i==1)
					months[i]=29;
		}
		for(i=0;i<5;i++)
			de+=prices[i];
		me=de*months[month-1];
		printf("%f %f",de,me);
	}
	else
		printf("Error");
}

int main()
{
	int i=0,month=0,yr=0,k=0;
	float prices[5];
	for(i=0;i<5;i++)
		scanf("%f",&prices[i]);
	scanf("%d",&month);
	scanf("%d",&yr);
	k=is_Valid(prices,month,yr);
	calculate(prices,month,yr,k);
	return 0;
}
