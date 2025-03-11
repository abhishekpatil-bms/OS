#include<stdio.h>
#include<stdlib.h>

void input(int n, int bt[]){
    printf("Enter brust times for times processes: \n");
    for(int i=0; i < n; i++){
        printf("process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
}
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int bt[n], wt[n], tt[n];
    float avg_wt = 0, avg_tt = 0;
    input(n, bt);
    wt[0] = 0;
    tt[0] = bt[0]; 
    for(int i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tt[i] = wt[i] + bt[i];
    }

    for(int i = 0; i < n; i++){
        avg_wt = avg_wt + wt[i];
        avg_tt = avg_tt + tt[i];
    }
    avg_wt = avg_wt/n;
    avg_tt = avg_tt/n;

    printf("\nProcess    Burst time    Waiting time    Turnaround time\n");
    for(int i = 0; i < n; i++){
        printf("  %d            %d               %d              %d\n", i+1,bt[i],wt[i],tt[i]);
    }
    printf("\nAverage Waiting time: %.2f\nAverage Turn around time: %.2f",avg_wt,avg_tt);
    return 0;
}
