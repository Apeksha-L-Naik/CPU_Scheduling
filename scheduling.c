#include<stdio.h>
#include<stdlib.h>
void fcfs(int processes[], int n, int bt[]){    
    int wt[n],tat[n],total_wt=0,total_tat=0;
    wt[0]=0;
    for(int i = 1; i < n; i++){
        wt[i] = bt[i-1] + wt[i-1];
        total_wt += wt[i];
    }
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
    }
    printf("\n");
    printf("First-come, First-served\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
    printf("\n");
}
void sjf(int processes[], int n, int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0,i,j;
    for(i=0;i<n;i++){
        int pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos])
                pos=j;
        }
        int temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
    }
       wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=0;
        for(j=0;j<i;j++){
 wt[i]+=bt[j];
        }
        total_wt+=wt[i];   
    }
     for(i=0;i<n;i++){
        //turnaround time of individual processes
        tat[i]=bt[i]+wt[i]; 
        //total turnaround time
        total_tat+=tat[i];   
    }    
  printf("\n");
    printf("Shortest Job First\n"); 
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
    printf("\n");
}
void rr(int processes[], int n, int bt[],int quantum){
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0; 
	while (1) { 
		int completed=1; 
		for (int i = 0 ; i < n; i++) { 
			if (rem_bt[i] > 0) { 
				completed=0; 
				if (rem_bt[i] > quantum) { 
					t += quantum; 

					rem_bt[i] -= quantum; 
				} 
				else{ 
					t = t + rem_bt[i]; 

					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (completed) 
		break; 
	} 
    	for (int i = 0; i < n ; i++) 
		   tat[i] = bt[i] + wt[i]; 
    printf( "PN\tBT\t WT \tTAT\n");
	for (int i=0; i<n; i++) { 
		total_wt = total_wt + wt[i]; 
                         total_tat = total_tat + tat[i]; 
		 printf("%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
	} 
       printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);      
} 
void priority(int processes[], int n, int bt[],int pri[]){
   int i,k,j;
   int wt[n],tat[n],total_wt=0,total_tat=0;
   for(i=0;i<n;i++)  {
    for(k=i+1;k<n;k++){
        if(pri[i]>pri[k]){
            int temp=processes[i];
            processes[i]=processes[k];
            processes[k]=temp;
            temp=bt[i];
            bt[i]=bt[k];
            bt[k]=temp;
            temp=pri[i];
            pri[i]=pri[k];
            pri[k]=temp;
        }}}
      wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j]; }
        total_wt+=wt[i];   
    }
     for(i=0;i<n;i++){
        //turnaround time of individual processes
        tat[i]=bt[i]+wt[i]; 
        //total turnaround time
        total_tat+=tat[i];   }    
    printf("\n");
    printf("Priority Scheduling\n");
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i],pri[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
    printf("\n");
}
int main(){ 
    int ch;
            printf("\n\t—- Scheduling Algorithms —-\n");
         int i, n;
        printf("Enter the number of processess:");
        scanf("%d", &n);
    
        int processes[n];
        int bt[n];
        int pri[n];
        int quantum;
    
        printf("Enter the burst time for each process:\n");
        for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;
    }
    while(1){
        printf("\n\t1. FCFS\n\t2. SJF\n\t3. RoundRobin\n\t4. Priority\n\t5. Exit");
        printf("\n\t Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:fcfs(processes,n,bt);
                   break;
            case 2:sjf(processes,n,bt);
                   break;
            case 3: 
            printf("enter Quantum:");
            scanf("%d",&quantum);
            rr(processes,n,bt,quantum);
                   break;
            case 4:
            printf("Enter priority\n");
            for(i=0;i<n;i++) {
                scanf("%d",&pri[i]);
            }
            priority(processes,n,bt,pri);
                   break;       
            case 5: exit(0);
                   break;
            default:printf("Invalid");
                    break;                           
        }
    }
 return 0;
}
