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
void FCFS(table* t){
    int elapsed = 0;
     printf("FCFS\nGANTT CHART:\n%d\t", elapsed);
    for(int i = 0;i<t->siz;i++){
        t->FT[i] = elapsed + t->BT[i];
        elapsed+=t->BT[i];  
        printf("P%d\t%d\t",(i+1), elapsed);
        t->TAT[i] = t->FT[i] - t->AT[i];
        t->WT[i] = t->TAT[i] - t->BT[i];
    }
    printf("\n");
    printTable(t);

}
int main(){
    table * p = init();
    FCFS(p);
}