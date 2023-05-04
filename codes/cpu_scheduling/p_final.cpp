#include<bits/stdc++.h>
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};


int main() {
	
    int n;
    struct process p[100];
    float avg_waiting_time;
    float avg_turnaround_time;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int burst_remaining[100];
    int is_completed[100]={0};
    //memset(is_completed,0,sizeof(is_completed));

    cout<<"Enter the number of processes: ";
    cin>>n;
	//entering the information of processes
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        cout<<endl;
    }
	//declaring the variables used
    int current_time = 0;
    int done = 0;//number of processes executed completed
    int prev = 0;//
    
    while(done != n) {
        int idx = -1;//stores the value of index of process which will be go for execution 
        int mp = -1;//stores the value of highest priority among the processes in ready queue
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(p[i].priority > mp) //getting the highest priority from ready queue
				{
                    mp = p[i].priority;
                    idx = i;
                }
            }
        }
        
        //executing idx process
        if(idx != -1) //checking if there is even a process in ready queue
		{
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
            
            if(burst_remaining[idx] == 0) //if the process has completed
			{
                p[idx].completion_time = current_time;
                p[idx].turnaround_time=p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                
                //calculating TAT and TWT
                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;//marking the process as completed
                done++;
            }
        }
        else {
             current_time++;
        }  
    }
    
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;

    cout<<endl<<endl;
    

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"WT\t"<<"TAT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].priority<<"\t"<<p[i].waiting_time<<"\t"<<p[i].turnaround_time<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;


}

