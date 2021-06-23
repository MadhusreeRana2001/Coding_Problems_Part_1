#include<stdio.h>

int is_Valid(int, int[]);  // to check if the input is valid or not
void calculate(int, int[]);  // to calculate the total no. of eggs

int is_Valid(int n, int age[])
{
	int i=0,p=1,q=1;
	if(n<0)
		p=0;
	if(n>0)
	{
		for(i=0;i<n;i++)
		{
			if(age[i]==0)
			{
				q=0;
				break;
			}
		}
	}
	return p*q;
}

void calculate(int n, int age[])
{
	int i=0,k=0,p=0,q=0;
	k=is_Valid(n,age);
	if(k)
	{
		if(n==0)
			p=0;
		else
		{
			for(i=0;i<n;i++)
			{
				if(age[i]>=52)
					p+=16;
				else if(age[i]>=49 && age[i]<=51)
				{
					q=52-age[i];
					p+=(4-q)*4;
				}
				else
					continue;
			}
		}
		printf("%d",p);
	}
	else
		printf("Error");
}

int main()
{
	int i=0,n=0,k=0;
	int age[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&age[i]);
	calculate(n,age);
	return 0;
}
