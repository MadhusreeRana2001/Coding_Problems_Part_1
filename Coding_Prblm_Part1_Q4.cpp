#include<stdio.h>
#include<string.h>

int is_Valid(char[]);  // to check if the input is valid or not
const char* calculate(char[]); // to calculate the product of even,odd position digits
void display(char []);  // to display the output of all the strings together

int is_Valid(char n[])
{
	int i=0,p=1,q=1,r=0,l=0;
	l=strlen(n);
	if(n[0]=='-')
		p=0;
	if(l>10)
		q=0;
	if(l!=0)
		for(i=0;i<l;i++)
			if(n[i]!='0')
			{
				r=1;
				break;
			}
	return p*q*r;
}

/* since, string literals are constants, hence, cannot be returned from a function
with its return type char*. */
const char* calculate(char n[])
{
	int i=0,l=0,k=0,p=1,q=1;
	int temp[10];
	k=is_Valid(n);
	if(k)
	{
		l=strlen(n);
		for(i=0;i<l;i++)
			temp[i]=int(n[i])-48;
		for(i=0;i<l;i++)
		{
			if(temp[i]!=0)
			{
				if(i%2)
					q*=temp[i];
				else
					p*=temp[i];
			}
		}
		if(p>=q)
			return "Magical ";
		else
			return "Dominant ";
	}
	else
		return "Error ";
}

void display(char f_o[])  // to clear the garbage value at the beginning of f_o
{
	int i=0;
	for(i=0;i<strlen(f_o);i++)
		if(i!=0)
			printf("%c",f_o[i]);
}

int main()
{
	int i=0,no=0;
	char n[20][20],f_o[100];
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		scanf(" %s",&n[i]);
		strcat(f_o,calculate(n[i]));
	}
	display(f_o);
	return 0;
}
