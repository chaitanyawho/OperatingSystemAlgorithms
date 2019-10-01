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
void SRTF(table* t){
    int elapsed = 0;
    int rem[t->siz];
    for(int i = 0;i<t->siz;i++){
        rem[i] = t->BT[i];
    }
    int complete = 0, min = 999999, shortest = 0, fin;
    int flag = 0;
    printf("SRTF\nGANTT CHART:\n");
    while(complete!=t->siz){
        for(int i = 0;i<t->siz;i++){
            if(t->AT[i]<=elapsed&&rem[i]<min&&rem[i]>0){
                min = rem[i];
                shortest = i;
                flag = 1;   
            }
        }
        
        if(!flag){
            elapsed++;
            continue;
        }
        printf("%d\tP%d\t", elapsed, shortest+1);
        rem[shortest]--;//shortest job being served one time lap
        min = rem[shortest];
        min = (min==0)?999999:min;
        if(rem[shortest]==0){//proc complete
            complete++;
            flag = 0;
            t->FT[shortest] = elapsed+1;
            t->TAT[shortest] = t->FT[shortest] - t->AT[shortest];
            t->WT[shortest] = t->TAT[shortest] - t->BT[shortest];
        }
        elapsed++;
    }
    printf("%d", elapsed);
    printf("\nTABLE:\n");
    printTable(t);
}
int main(){
    table * p = init();
    SRTF(p);
}