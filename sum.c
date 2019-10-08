#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib1{
	int n;
	int * a;
};
void * fib(void * param){
	struct fib1 * ob = (struct fib1 *)param;
	int sum=0;
	for(int i = 0;i<ob->n;i++){
		sum+=ob->a[i];
	}
	return (void*)sum;
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
	pthread_join(thread,(void *)&sum);
	printf("Sum=%d\n",sum);
	return 0;
}