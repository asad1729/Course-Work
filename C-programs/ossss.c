FCFS
#include <stdio.h>
#include <stdlib.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])
{
 int service_time[n];
 service_time[0] = at[0];
 wt[0] = 0;
 for (int i = 1; i < n ; i++)
 {
 service_time[i] = service_time[i-1] + bt[i-1];
 wt[i] = service_time[i] - at[i];
 if (wt[i] < 0)
 wt[i] = 0;
 }
}
void findTurnAroundTime(int processes[], int n, int bt[],int wt[], int 
tat[])
{
 for (int i = 0; i < n ; i++)
 tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[], int at[])
{
 int wt[n], tat[n];
 findWaitingTime(processes, n, bt, wt, at);
 findTurnAroundTime(processes, n, bt, wt, tat);
 printf("Processes Burst Time Arrival Time Waiting Time TurnAround Time\n");
 int total_wt = 0, total_tat = 0;
 for (int i = 0 ; i < n ; i++)
 {
 total_wt = total_wt + wt[i];
 total_tat = total_tat + tat[i];
 int compl_time = tat[i] + at[i];
 printf(" %d\t\t %d\t\t %d \t\t %d \t\t 
%d\n",i+1,bt[i],at[i],wt[i],tat[i],compl_time);
 }
 
 printf("\nAverage waiting time = %f",(float)total_wt / (float)n);
 printf("\nAverage turn around time = %f",(float)total_tat / 
(float)n);
}
int main(){
 
 int n;
 printf("Enter number of preocesses: ");
 scanf("%d",&n);
 int burst_time[n],arrival_time[n],processes[n];
 printf("Enter arrival time of each process: ");
 for(int i=0;i<n;i++)
 scanf("%d",&arrival_time[i]);
 printf("Enter burst time of each process: ");
 for(int i=0;i<n;i++)
 scanf("%d",&burst_time[i]);
 for(int i=0;i<n;i++)
 processes[i]=i+1;
 findavgTime(processes, n, burst_time, arrival_time);
 return 0;
}

***************************************************************************************************************************************
                                                                  SJF
[1:51 pm, 19/04/2022] BITM Ujjwal Mittal: #include<stdio.h>
void sort(int a[],int n){
 for(int i=0;i<n-1;i++){
 for(int j=0;j<n-i-1;j++){
 if(a[j]>a[j+1]){
 a[j] = a[j+1] + a[j];
 a[j+1] = a[j] - a[j+1];
 a[j] = a[j] - a[j+1];
 }
 }
 }
}
void findWaitingTime(int n, int bt[], int wt[])
{
 wt[0] = 0;
 for (int i = 1; i < n ; i++ )
 wt[i] = bt[i-1] + wt[i-1] ;
}
void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
 for (int i = 0; i < n ; i++)
 tat[i] = bt[i] + wt[i];
}
void findavgTime(int n, int bt[])
{
 int wt[n], tat[n], total_wt = 0, total_tat = 0;
 findWaitingTime(n, bt, wt);
 findTurnAroundTime(n, bt, wt, tat);
 printf("Burst time Waiting time Turn around time\n");
 for (int i=0; i<n; i++)
 {
 total_wt = total_wt + wt[i];
 total_tat = total_tat + tat[i];
 printf("%d ", bt[i] );
 print…
[1:52 pm, 19/04/2022] BITM Ujjwal Mittal: SRT
[1:52 pm, 19/04/2022] BITM Ujjwal Mittal: #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
struct process
{
 int processid;
 int burstt;
 int arrivalt;
};
void findWaitingTime(struct process proc[], int n, int wt[])
{
 int rt[n];
 for (int i = 0; i < n; i++)
 rt[i] = proc[i].burstt;
 int complete = 0, t = 0, minm = INT_MAX;
 int shortest = 0, finish_time;
 bool check = false;
 while (complete != n)
 {
 for (int j = 0; j < n; j++)
 {
 if ((proc[j].arrivalt <= t) && (rt[j] < minm) && rt[j] > 0)
 {
 minm = rt[j];
 shortest = j;
 check = true;
 }
 }
 if (check == false)
 {
 t++;
 continue;
 }
 rt[shortest]--;
 minm = rt[shortest];
 if (minm == 0)
 minm = INT_MAX;
 if (rt[shortest] == 0)
 {
 complete++;
 check = false;
 finish_time = t + 1;
 wt[shortest] = finish_time - proc[shortest].burstt -
proc[shortest].arrivalt;
 if (wt[shortest] < 0)
 wt[shortest] = 0;
 }
 t++;
 }
}
void findTurnAroundTime(struct process proc[], int n, int wt[], int 
tat[])
{
 for (int i = 0; i < n; i++)
 tat[i] = proc[i].burstt + wt[i];
}
void findavgTime(struct process proc[], int n)
{
 int wt[n], tat[n], total_wt = 0,
 total_tat = 0;
 findWaitingTime(proc, n, wt);
 findTurnAroundTime(proc, n, wt, tat);
 printf("processes\tBurst time\tWaiting time\tTT\n");
 for (int i = 0; i < n; i++)
 {
 total_wt = total_wt + wt[i];
 total_tat = total_tat + tat[i];
 printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].processid, 
proc[i].burstt, wt[i], tat[i]);
 }
 printf("\nAverage waiting time: %f", (float)total_wt / (float)n);
 printf("\nAverage turn around time: %f", (float)total_tat / (float)n);
}
int main()
{
 int n;
 printf("Enter the number of jobs you would like to execute\n");
 scanf("%d", &n);
 struct process proc[n];
 for (int i = 0; i < n; i++)
 {
 proc[i].processid = i + 1;
 printf("Enter the process %d arrival time ", i + 1);
 scanf("%d", &proc[i].arrivalt);
 printf("Enter the process %d burst time ", i + 1);
 scanf("%d", &proc[i].burstt);
 printf("\n");
 }
 findavgTime(proc, n);
 return 0;
}

***************************************************************************************************************************************
                                                            ROUND ROBIN
#include<stdio.h>
void main()
{
 int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], 
temp[10];
 float avg_wt, avg_tat;
 printf(" Total number of process in the system: ");
 scanf("%d", &NOP);
 y = NOP;
 for(i=0; i<NOP; i++)
 {
 printf("\n Enter the Arrival and Burst time of the Process[%d]\n", 
i+1);
 printf(" Arrival time is: ");
 scanf("%d", &at[i]);
 printf(" Burst time is: ");
 scanf("%d", &bt[i]);
 temp[i] = bt[i];
 }
 printf("Enter the Time Quantum for the process: ");
 scanf("%d", &quant);
 printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
 for(sum=0, i = 0; y!=0; )
 {
 if(temp[i] <= quant && temp[i] > 0)
 {
 sum = sum + temp[i];
 temp[i] = 0;
 count=1;
 }
 else if(temp[i] > 0)
 {
 temp[i] = temp[i] - quant;
 sum = sum + quant;
 }
 if(temp[i]==0 && count==1)
 {
 y--;
 printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t %d", i+1, bt[i], 
sum-at[i],
 sum-at[i]-bt[i]);
 wt = wt+sum-at[i]-bt[i]; 
 tat = tat+sum-at[i];
 count =0;
 }
 if(i==NOP-1)
 i=0;
 else if(at[i+1]<=sum)
 i++;
 else
 i=0;
 }
 avg_wt = wt * 1.0/NOP;
 avg_tat = tat * 1.0/NOP;
 printf("\n\n Average Turn Around Time: \t%f", avg_wt);
 printf("\n Average Waiting Time: \t%f", avg_tat);
}

***************************************************************************************************************************************
                                        Round Robin scheduling with context switching time = 0
#include<stdio.h>
void main()
{
 int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], 
temp[10];
 float avg_wt, avg_tat;
 printf(" Total number of process in the system: ");
 scanf("%d", &NOP);
 y = NOP;
 for(i=0; i<NOP; i++)
 {
 printf("\n Enter the Arrival and Burst time of the Process[%d]\n", 
i+1);
 printf(" Arrival time is: ");
 scanf("%d", &at[i]);
 printf(" Burst time is: ");
 scanf("%d", &bt[i]);
 temp[i] = bt[i];
 }
 printf("Enter the Time Quantum for the process: ");
 scanf("%d", &quant);
 printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
 for(sum=0, i = 0; y!=0; )
 {
 if(temp[i] <= quant && temp[i] > 0)
 {
 sum = sum + temp[i];
 temp[i] = 0;
 count=1;
 }
 else if(temp[i] > 0)
 {
 temp[i] = temp[i] - quant;
 sum = sum + quant;
 }
 if(temp[i]==0 && count==1)
 {
 y--;
 printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t %d", i+1, bt[i], 
sum-at[i],sum-at[i]-bt[i]);
 wt = wt+sum-at[i]-bt[i]; 
 tat = tat+sum-at[i];
 count =0;
 }
 if(i==NOP-1)
 i=0;
 else if(at[i+1]<=sum)
 i++;
 else
 i=0;
 }
 avg_wt = wt * 1.0/NOP;
 avg_tat = tat * 1.0/NOP;
 printf("\n\n Average Turn Around Time: \t%f", avg_wt);
 printf("\n Average Waiting Time: \t%f", avg_tat);
}

***************************************************************************************************************************************
                                          Round Robin with context switching time = 0.4 ms
#include<stdio.h>
int main()
{
 float NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], 
temp[10],contextSwitchTime=0.4;
 int i;
 float avg_wt, avg_tat;
 printf(" Total number of process in the system: ");
 scanf("%f", &NOP);
 y = NOP;
 for(i=0; i<NOP; i++)
 {
 printf("\n Enter the Arrival and Burst time of the Process[%d]\n", 
i+1);
 printf(" Arrival time is: ");
 scanf("%f", &at[i]);
 printf(" Burst time is: ");
 scanf("%f", &bt[i]);
 temp[i] = bt[i];
 }
 printf("Enter the Time Quantum for the process: ");
 scanf("%f", &quant);
 printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
 for(sum=0, i = 0; y!=0; )
 {
 if(temp[i] <= quant && temp[i] > 0)
 {
 sum = sum + temp[i];
 temp[i] = 0;
 count=1;
 }
 else if(temp[i] > 0)
 {
 temp[i] = temp[i] - quant;
 sum = sum + quant + contextSwitchTime;
 }
 if(temp[i]==0 && count==1)
 {
 y--;
 printf("\nProcess No[%d] \t\t %f\t\t %f\t\t %f", i+1, bt[i], sumat[i], sum-at[i]-bt[i]);
 wt = wt+sum-at[i]-bt[i]; 
 tat = tat+sum-at[i];
 count =0;
 }
 if(i==NOP-1)
 i=0;
 else if(at[i+1]<=sum)
 i++;
 else
 i=0;
 }
 avg_wt = wt * 1.0/NOP;
 avg_tat = tat * 1.0/NOP;
 printf("\n\n Average Turn Around Time: \t%f", avg_wt);
 printf("\n Average Waiting Time: \t%f", avg_tat);
}

***************************************************************************************************************************************
                                                                   First Fit
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (blockSize[j] >= processSize[i])
{
allocation[i] = j;
blockSize[j] -= processSize[i];
break;
}
}
}
printf("\nProcess No.\tProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t%d\t\t",i+1,processSize[i]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int processSize[25] =
{5760,4190,3290,2030,2550,6990,8940,740,3930,6890,6580,3820,9140,420,220,7540,
3210,1380,9850,3610,7540,
2710,8390,5950,760};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
firstFit(blockSize,m,processSize,n);
}

***************************************************************************************************************************************
                                                           Best Fit
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bestFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i=0; i<n; i++)
{
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
if (bestIdx != -1)
{
allocation[i] = bestIdx;
blockSize[bestIdx] -= processSize[i];
}
}
printf("\nProcess No.\tProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t%d\t\t",i+1,processSize[i]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int processSize[25] =
{5760,4190,3290,2030,2550,6990,8940,740,3930,6890,6580,3820,9140,420,220,7540,
3210,1380,9850,3610,7540,
2710,8390,5950,760};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
bestFit(blockSize,m,processSize,n);
}

***************************************************************************************************************************************
                                                 First fit Using Shortest Job First:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(int jobs[][2], int n){
int x,y,j;
for(int i=1;i<n;i++){
x = jobs[i][0];
y = jobs[i][1];
j=i-1;
while(j>=0 && jobs[j][0]>x){
jobs[j+1][0] = jobs[j][0];
jobs[j+1][1] = jobs[j][1];
j--;
}
jobs[j+1][0] = x;
jobs[j+1][1] = y;
}
}
void firstFit(int blockSize[], int m, int jobs[][2], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (blockSize[j] >= jobs[i][1])
{
allocation[i] = j;
blockSize[j] -= jobs[i][1];
break;
}
}
}
printf("\nProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t",jobs[i][1]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int jobs[25][2] = {
{5,5760},{4,4190},{8,3290},{2,2030},{2,2550},{6,6990},
{8,8940},{10,740},{7,3930},{6,6890},{5,6580},{8,3820},
{9,9140},{10,420},{10,220},{7,7540},{3,3210},{1,1380},
{9,9850},{3,3610},{7,7540},{2,2710},{8,8390},
{5,5950},{10,760}
};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
sort(jobs,n);
firstFit(blockSize,m,jobs,n);
}

***************************************************************************************************************************************
                                                 Best Fit Using Shortest Job First:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(int jobs[][2], int n){
int x,y,j;
for(int i=1;i<n;i++){
x = jobs[i][0];
y = jobs[i][1];
j=i-1;
while(j>=0 && jobs[j][0]>x){
jobs[j+1][0] = jobs[j][0];
jobs[j+1][1] = jobs[j][1];
j--;
}
jobs[j+1][0] = x;
jobs[j+1][1] = y;
}
}
void bestFit(int blockSize[], int m, int jobs[][2], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i=0; i<n; i++)
{
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >=jobs[i][1])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
if (bestIdx != -1)
{
allocation[i] = bestIdx;
blockSize[bestIdx] -= jobs[i][1];
}
}
printf("\nProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t",jobs[i][1]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int jobs[25][2] = {
{5,5760},{4,4190},{8,3290},{2,2030},{2,2550},{6,6990},
{8,8940},{10,740},{7,3930},{6,6890},{5,6580},{8,3820},
{9,9140},{10,420},{10,220},{7,7540},{3,3210},{1,1380},
{9,9850},{3,3610},{7,7540},{2,2710},{8,8390},
{5,5950},{10,760}
};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
sort(jobs,n);
bestFit(blockSize,m,jobs,n);
}

***************************************************************************************************************************************
                                                      First Fit Using Smallest Job First:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(int process[],int n){
int x,j;
for(int i=1;i<n;i++){
x = process[i];
j=i-1;
while(j>=0 && process[j]>x){
process[j+1] = process[j];
j--;
}
process[j+1] = x;
}
}
void firstFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (blockSize[j] >= processSize[i])
{
allocation[i] = j;
blockSize[j] -= processSize[i];
break;
}
}
}
printf("\nProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t",processSize[i]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int processSize[25] =
{5760,4190,3290,2030,2550,6990,8940,740,3930,6890,6580,3820,9140,420,220,7540,
3210,1380,9850,3610,7540,2710,8390,5950,760};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
sort(processSize,n);
firstFit(blockSize,m,processSize,n);
}

***************************************************************************************************************************************
                                                         Best Fit Using Smallest Job First:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(int process[],int n){
int x,j;
for(int i=1;i<n;i++){
x = process[i];
j=i-1;
while(j>=0 && process[j]>x){
process[j+1] = process[j];
j--;
}
process[j+1] = x;
}
}
void bestFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i=0; i<n; i++)
{
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
if (bestIdx != -1)
{
allocation[i] = bestIdx;
blockSize[bestIdx] -= processSize[i];
}
}
printf("\nProcess No.\tProcess Size\tBlock no.\n");
for (int i = 0; i < n; i++)
{
printf(" %d\t\t",processSize[i]);
if (allocation[i] != -1)
printf("%d",allocation[i]+1);
else
printf("Not Allocated");
printf("\n");
}
}
int main(){
int processSize[25] =
{5760,4190,3290,2030,2550,6990,8940,740,3930,6890,6580,3820,9140,420,220,7540,
3210,1380,9850,3610,7540,
2710,8390,5950,760};
int blockSize[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
int n=25,m=10;
sort(processSize,n);
bestFit(blockSize,m,processSize,n);
}

***************************************************************************************************************************************
                               FIFO Page Replacement Algorithm   Page Size: 100, Main memory: 200
#include <stdio.h>
int main(){
int n = 12, pageSize = 100, m = 2,flag,k=-1,hit=0,x;
int request[12] = {10,11,104,170,73,309,185,245,246,434,458,364};
int frame[2] = {-1,-1};
for(int i=0;i<n;i++){
flag=0;
for(int j=0;j<m;j++){
if(request[i]<=(frame[j]+1)*pageSize &&
request[i]>frame[j]*pageSize){
flag=1;
break;
}
}
if(flag)
hit++;
else{
x = request[i]/pageSize;
frame[(k+1)%m] = x;
k = (k+1)%m;
}
}
printf("\nFrequency is %d hit per 12 number of requests.\n\n",hit);
}