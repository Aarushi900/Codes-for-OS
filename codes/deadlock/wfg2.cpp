#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of processes:";
	cin>>n;
	int a[n][n];
	vector<int>edges_start;
	vector<int>edges_end;
// 	int k=0;
	cout<<"\nEnter the value of matrix:";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"\nEnter the value of a"<<i<<j;
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				edges_start.push_back(i);
				edges_end.push_back(j);
			}
		}
	}
	cout<<"Eges are:\n";
	for(int i=0;i<edges_start.size();i++){
		cout<<"Edge is from process "<<edges_start[i]<<"to "<<edges_end[i]<<"\n";
	}
	int no_of_resources=edges_start.size();
	int m=n+no_of_resources;
	int wfg[n+no_of_resources][n+no_of_resources];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++){
			wfg[i][j]=0;
		}
		cout<<"\n";
	}
	for(int i=0;i<no_of_resources;i++){
		int l=edges_start[i];
		int k=edges_end[i];
		wfg[l][n+i]=1;
		wfg[n+i][k]=1;
	}
	cout<<"   ";
	for(int i=0;i<m;i++){
		if(i<n)
		cout<<"P"<<i+1<<"\t";
		else
		cout<<"R"<<i+1-n<<"\t";
	}
	cout<<"\n";
	for(int i=0;i<m;i++)
	{
		if(i<n)
		cout<<"P"<<i+1<<" ";
		else
		cout<<"R"<<i+1-n<<" ";
		for(int j=0;j<m;j++){
			cout<<wfg[i][j]<<"\t";
		}
	
		cout<<"\n";
		
	}
	
}
