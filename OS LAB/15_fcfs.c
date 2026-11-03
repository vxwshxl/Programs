// 15. Write A Program in c to implement the FCFS Algorithm

#include <stdio.h>

int main()
{
    int n, i;
    int bt[20], wt[20], tat[20];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // First process does not wait
    wt[0] = 0;

    // Each process waits for all the ones before it
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time    = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

/* ---------------- Output ----------------
   Enter number of processes: 3
   Enter burst time for each process:
   P1: 5
   P2: 3
   P3: 8

   Process Burst Time      Waiting Time    Turnaround Time
   P1      5               0               5
   P2      3               5               8
   P3      8               8               16

   Average Waiting Time    = 4.33
   Average Turnaround Time = 9.67
*/
