#include <bits/stdc++.h>
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    int pid[n], bt[n], wt[n];

    cout << "Enter process IDs: ";
    for (int i = 0; i < n; i++) cin >> pid[i];

    cout << "Enter burst time: ";
    for (int i = 0; i < n; i++) cin >> bt[i];

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    float total_wt = 0, total_tat = 0;

    cout << "\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        int tat = bt[i] + wt[i];
        cout << pid[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat << endl;

        total_wt += wt[i];
        total_tat += tat;
    }

    cout << "\nAverage waiting time: " << total_wt / n << endl;
    cout << "Average turnaround time: " << total_tat / n << endl;

    return 0;
}
