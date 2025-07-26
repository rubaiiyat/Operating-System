#include <bits/stdc++.h>
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    int bt[n], p[n], wt[n], tat[20], total=0, totalIT=0;
    float avg_wt=0, avg_tat=0;

    cout<<"Enter brust times:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>bt[i];
        p[i]=i+1;
    }

    for (int i = 0; i < n-1; i++)
    {
        int pos=i;
        for (int j = i+1; j < n; j++)
        {
            if(bt[j] < bt[pos]) pos=j;
        }

        swap(bt[i],bt[pos]);
        swap(p[i],p[pos]);
    }

    wt[0]=0;
    for (int i = 1; i < n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        avg_wt+=wt[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        tat[i]=wt[i] + bt[i];
        avg_tat+=tat[i];
    }

    cout<<"\nProcess\t Brust Time\t Waiting Time\t Turnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout<<"\nAverage waiting time: "<<avg_wt/n<<endl;
    cout<<"Average turnaround time: "<<avg_tat/n<<endl;
    
    
    

    
    return 0;
}