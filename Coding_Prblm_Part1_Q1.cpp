#include<stdio.h>

void calculate(int,int []);  // to calculate the frequency of each given denomination

void calculate(int n, int arr[10])
{
	int i=0,r=n;
	int temp[10];
	if(n>0 && n<=25000)
	{
		for(i=0;i<10;i++)
		{
			if(r==0)
			{
				for(;i<10;i++)
					temp[i]=0;
				break;
			}
			else if(r>=arr[i])
			{
				n=r/arr[i];
				r%=arr[i];
				temp[i]=n;
			}
			else
			{
				temp[i]=0;
				continue;
			}
		}
		for(i=0;i<10;i++)
			printf("%d ",temp[i]);
	}
	else
		printf("Error");
}

int main()
{
	int n=0;
	int arr[]={2000,500,200,100,50,20,10,5,2,1};
	scanf("%d",&n);
	calculate(n,arr);
	return 0;
}
