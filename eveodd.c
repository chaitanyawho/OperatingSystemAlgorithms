#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib1{
	int n;
	int *a;
	int evesum;
	int oddsum;
};
void * fib(void * param){
	struct fib1 * ob = (struct fib1 *)param;
	int sum=0;
	ob->evesum = 0;
	ob->oddsum = 0;
	for(int i = 0;i<ob->n;i++){
		if(ob->a[i]%2==0)ob->evesum+=ob->a[i];
		else{ 
			ob->oddsum+=ob->a[i];
		}
	}

}
int main(int argc, char const *argv[])
{
	pthread_t thread;
	struct fib1 * ob = (struct fib1 *)malloc(sizeof(struct fib1)*1);
	scanf("%d",&ob->n);
	ob->a = (int *)malloc(sizeof(int)*ob->n);
	for(int i =0;i<ob->n;i++){
		scanf("%d",&ob->a[i]);
	}
	int sum;
	pthread_create(&thread,0,&fib,ob);
	pthread_join(thread,0);
	printf("Even Sum=%d\n",ob->evesum);
	printf("Odd sum=%d\n",ob->oddsum);
	return 0;
}