#include<stdio.h>
# include<math.h>
int t;
int main()
{
scanf("%d",&t);
 int i,j,a,sum=0;
while(t--)
{
	sum=0;
	scanf("%d",&a);
	j=(int)sqrt(a);
	for(i=1;i*i<a;i++)
		if(a%i==0) sum+=i+a/i;
			
	if(j * j == a)sum+=j;	
	
	//if(a==0)
	//printf("0\n");
	//else
	printf("%d\n",sum-a);
}
return 0;
}


