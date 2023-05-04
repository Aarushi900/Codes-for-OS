#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of processes:";
	cin>>n;
	int a[n][n];
	vector<int>edges_start;
	vector<int>edges_end;
	int k=0;
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
				edges_start[k]=i;
				edges_end[k]=j;
				k++;
			}
		}
	}
	cout<<"/nEges are:";
	for(int i=0;i<edges_start.size();i++){
		cout<<"Edge is from process "<<edges_start[i]<<"to "<<edges_end[i];
	}
	int no_of_resources=edges_start.size();
	int m=n+no_of_resources;
	int wfg[n+no_of_resources][n+no_of_resources];
	for(int i=0;i<m;i++){
		wfg[edges_start[i]][n+i]=1;
		wfg[n+i][edges_end[i]]=1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++){
			if(a[i][j]!=1)
				cout<<0<<"\t";
			else
				cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
}
