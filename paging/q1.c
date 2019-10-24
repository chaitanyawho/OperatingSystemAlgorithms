#include <stdio.h>
int fifo(int arr[],int n,int q) {
	int pq[q],j,miss = 0,flag;
	for(j=0; j<q; j++) {
		pq[j] = arr[j];
		miss++;
	}
	int k=0;
	for(int i=j; i<n; i++) {
		flag = 0;
		for(j=0; j<q; j++) {
			if(pq[j] == arr[i]) {
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		miss++;
		pq[k] = arr[i];
		k = (k+1)%q;
	}
	return miss;
}
int opt(int arr[],int n,int q) {
	int pq[q],j,k,ind,max,miss = 0,flag = 0;
	for(j=0; j<q; j++) {
		pq[j] = arr[j];
		miss++;
	}
	for(int i=j; i<n; i++) {
		flag = 0;
		for(j=0; j<q; j++){
			if(pq[j] == arr[i]){
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		miss++;
		max = 0,ind = 0;
		for(j=0; j<q; j++){
			for(k=i+1; k<n; k++)
				if(arr[k] == pq[j])
					break;
			if(k>max){
				max = k;
				ind = j;
			}
		}
		pq[ind] = arr[i];
	}
	return miss;
}
int lru(int arr[],int n,int q){
	int pq[q],j,k,ind,min,miss = 0,flag = 0;
	for(j=0; j<q; j++){
		pq[j] = arr[j];
		miss++;
	}
	for(int i=j; i<n; i++){
		flag = 0;
		for(j=0; j<q; j++){
			if(pq[j] == arr[i]){
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		miss++;
		min = 100,ind = 0;
		for(j=0; j<q; j++){
			for(k=i-1; k>=0; k--)
				if(arr[k] == pq[j])
					break;
			if(k<min){
				min = k;
				ind = j;
			}
		}
		pq[ind] = arr[i];
	}
	return miss;
}
int main() {
	int arr[30],n,q,miss;
	printf("Enter n and q: ");
	scanf("%d %d",&n,&q);
	printf("Enter array: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	miss = fifo(arr,n,q);
	printf("FIFO:\nPage Fault: %d\nPage Hit: %d\n",miss,n-miss);
	miss = opt(arr,n,q);
	printf("Optimal:\nPage Fault: %d\nPage Hit: %d\n",miss,n-miss);
	miss = lru(arr,n,q);
	printf("LRU:\nPage Fault: %d\nPage Hit: %d\n",miss,n-miss);
}