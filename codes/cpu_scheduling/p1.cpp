#include<iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef struct proinfo{
	int id=0;
	int at=0;
	mutable int bt=0;
	int pt=0;
}proinfo;

bool operator<(const proinfo& p1, const proinfo& p2){
    if(p1.at == p2.at){
        return p1.pt < p2.pt;
    }
    else {
        return p1.at < p2.at;
    }
}


void schedule(int n, priority_queue<proinfo, vector<proinfo>, less<proinfo> >& p_queue, int* wt){
	int tt = p_queue.top().at;
	int done = 0;//no of processes done
	while(done != n){
		p_queue.top().bt--;
		if(p_queue.top().bt == 0){
			cout<<"time:"<<tt<<"    "<<p_queue.top().id<<"\n"
			;wt[p_queue.top().id-1] = tt ;
			p_queue.pop();
			done++;
		}
		else {
			for(int i = 0; i < n; i++){
				if(i != p_queue.top().id - 1){
					if(p_queue.top().at <= tt && p_queue.top().pt < p_queue.top().pt){
						p_queue.push(p_queue.top());
						p_queue.pop();
					}
				}
			}
		}
		tt++;
	}
}

int main(){
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	proinfo a[n];
	int waiting_time[n] = {0};
	priority_queue<proinfo, vector<proinfo>, less<proinfo> > p_queue;
	for(int i = 0; i < n; i++){
		cout << "Enter the arrival time, burst time and priority of process " << i + 1 << ": ";
		cin >> a[i].at >> a[i].bt >> a[i].pt;
		a[i].id = i + 1;
		p_queue.push(a[i]);
	}
	schedule(n, p_queue, waiting_time);

//	cout << "\nProcess\t\tArrival Time\t\tBurst Time\t\tPriority\t\tWaiting Time\n";
//	for(int i = 0; i < n; i++){
//			waiting_time[i]=waiting_time[i]-(a[i].at+a[i].bt);
//		cout << "P[" << a[i].id << "]\t\t\t" << a[i].at << "\t\t\t" << a[i].bt << "\t\t\t" << a[i].pt << "\t\t\t" << waiting_time[i] << "\n";
//	}
}

