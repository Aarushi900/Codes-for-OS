#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomArray(int arr[], int size, int total) { 
    for (int i = 0; i < size-1; i++) {
        int num = (rand() % (total-size + 1));
    	arr[i]=num+1;
        total -= num+1;
    }
    arr[size-1]=total;
    
}

int main() {
	int total;int size;
	cout<<"Enter total memory unit";
	cin>>total;
	cout<<"Enter no of segments";
	cin>>size;
    int arr[size];

    generateRandomArray(arr, size, total);
	int no_of_occupied;
	cout<<"Enter the number of occupied segments";
	cin>>no_of_occupied;
	cout<<"Enter the occupied segments";
	int occupied[no_of_occupied];
	int unoccupied[size-no_of_occupied];
	for(int i=0;i<no_of_occupied;i++){
		cin>>occupied[i];
	}
	int j=0,k=0;
	cout<<"Memory allocated";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"\n";
	}
	cout<<"External fragementation\n";
	cout<<"Segment	 ->		Memory\n";
	for(int i=1;i<=size;i++){
		if(i!=occupied[j])
			{
				unoccupied[k]=i;k++;
			}
		else
		j++;	
	}
	for(int i=0;i<size-no_of_occupied;i++){
			cout<<unoccupied[i]<<"			"<<arr[unoccupied[i]-1]<<"\n";}
		
	
	cout<<"Internal Fragmentation\n";
	cout<<"Segment	 ->		Memory\n";
	for(int i=0;i<no_of_occupied;i++){
		if(occupied[i]%2==0){
			cout<<occupied[i]<<"			"<<arr[i]*0.02<<"\n";
		}
		else{
			cout<<occupied[i]<<"			"<<arr[i]*0.01<<"\n";			
		}
	}	
	
}

