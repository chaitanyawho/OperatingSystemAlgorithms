#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct{
    int *AT;
    int *BT;
    int *priority;
    int * FT;
    int *TAT;
    int * WT;
    int siz;
}table;
table* init(){
    table* t = (table *)malloc(sizeof(table));
    scanf("%d",&(t->siz));
    t->AT = (int *)malloc(t->siz*sizeof(int));
    t->BT = (int *)malloc(t->siz*sizeof(int));
    t->priority = (int *)malloc(t->siz*sizeof(int));
    t->WT = (int *)malloc(t->siz*sizeof(int));
    //  t->FT = (int *)malloc(t->siz*sizeof(int));
    t->TAT = t->FT = (int *)malloc(t->siz*sizeof(int));
    printf("Enter all arrival times.\n");
    for(int i = 0;i<t->siz;i++)
        scanf("%d", &(t->AT[i]));

    printf("Enter all burst times.\n");
    for(int i = 0;i<t->siz;i++)
        scanf("%d", &(t->BT[i]));

    printf("Enter all priorities.\n");
    for(int i = 0;i<t->siz;i++)
        scanf("%d", &(t->priority[i]));
    return t;
}
void printTable(table* t){
    printf("BT\tP\tAT\tFT\tTAT\tWT\n");
    double awt = 0;
    double att = 0;
    for(int i = 0;i<t->siz;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",t->BT[i], t->priority[i], t->AT[i], t->FT[i], t->TAT[i], t->WT[i]);
        awt+=t->WT[i];
        att+=t->TAT[i];
    }
    awt/=t->siz;
    att/=t->siz;
    printf("Average waiting time = %f\nAverage turnaround time = %f\n", awt, att);
}
void RoundRobin(table *t){
    int elapsed = 0;
    int quantum = 10;
    int rem[t->siz];
    int flag = 1;
    
    for(int i = 0;i<t->siz;i++)
        rem[i] = t->BT[i];
    printf("ROUND ROBIN\nGANTT CHART:\n%d\t",elapsed);
    while(1){
        flag = 1;
        for(int i = 0;i<t->siz;i++){
            if(rem[i]>0&&t->AT[i]<=elapsed){
                flag = 0;
                if(rem[i]>quantum){
                    elapsed+=quantum;
                    rem[i]-=quantum;
                    printf("P%d\t%d\t", i+1, elapsed);
                   

                    if(rem[i]==0){//finished process i
                        t->FT[i] = elapsed;
                        t->TAT[i] = t->FT[i] - t->AT[i];
                        t->WT[i] = t->TAT[i] - t->BT[i];
                    }
                }
                else{
                    elapsed+=rem[i];
                    printf("P%d\t%d\t",i+1, elapsed);
                    //WT for i is elapsed time minus time taken  for process i
                    rem[i] = 0;
                    //finished process i
                    t->FT[i] = elapsed;
                    t->TAT[i] = t->FT[i] - t->AT[i];
                    t->WT[i] = t->TAT[i] - t->BT[i];
                
                }
            }
        }
        if(flag)
            break;
    }
    printf("\nTABLE:\n");
    printTable(t);
}
int main(){
    table * p = init();
    RoundRobin(p);
}