// 16. Write a program in c to implement the priority bases scheduling algorithm
// A lower number means a higher priority

#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int p[20], bt[20], pr[20], wt[20], tat[20];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    // Sort processes by priority (selection sort)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[i])
            {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i] = p[j];   p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time    = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

/* ---------------- Output ----------------
   Enter number of processes: 4
   Enter burst time and priority for each process:
   P1: 10 3
   P2: 1 1
   P3: 2 4
   P4: 5 2

   Process Priority        Burst Time      Waiting Time    Turnaround Time
   P2      1               1               0               1
   P4      2               5               1               6
   P1      3               10              6               16
   P3      4               2               16              18

   Average Waiting Time    = 5.75
   Average Turnaround Time = 10.25
*/
