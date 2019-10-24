#include<stdio.h>
int search(int x,int pq[],int ref[],int q)
{
	for(int i=0;i<q;i++)
	{
		if(pq[i]==x)
		{
			ref[i]=1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[30],pq[10],n,q,miss,flag,j,k=0,ref[10]={0};
	printf("Enter n and q: ");
	scanf("%d %d",&n,&q);
	printf("Enter array: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(j=0;j<q;j++)
	{
		pq[j]=arr[j];
		miss++;
	}
	for(int i=j;i<n;i++)
	{
		flag=1;
		if(search(arr[i],pq,ref,q))
			continue;
		while(flag)
		{
			if(ref[k]==1)
			{
				ref[k]=0;
				k=(k+1)%q;
			}
			else
			{
				pq[k]=arr[i];
				k=(k+1)%q;
				miss++;
				flag=0;
			}
		}
	}
	float rate=(float)(n-miss)/n;
	printf("Fault: %d Hit Rate:%f\n",miss,rate);
}