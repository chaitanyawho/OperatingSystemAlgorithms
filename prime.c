#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib1{
	int l;
	int r;
	int * a;
	int k;
};
int isPrime(int n){
	int flag = 1;
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}
void * fib(void * param){
	struct fib1 * ob = (struct fib1 *)param;
	ob->k =0;
	for(int i = ob->l;i<ob->r;i++){
		if(isPrime(i)==1){
			ob->a[ob->k++]=i;
		}
	}

}
int main(int argc, char const *argv[])
{
	pthread_t thread;
	struct fib1 * ob = (struct fib1 *)malloc(sizeof(struct fib1)*1);
	scanf("%d",&ob->l);
	scanf("%d",&ob->r);
	ob->a = (int *)malloc(sizeof(int)*(ob->r));
	int sum;
	pthread_create(&thread,0,&fib,ob);
	pthread_join(thread,0);
	for(int i = 0;i<ob->k;i++){
		printf("%d\n",ob->a[i]);
	}
	return 0;
}