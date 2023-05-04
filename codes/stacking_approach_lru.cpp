#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int>reference{3,3,3,0,0,0,1,1,1};
	int n;
	cin>>n;
	vector<int>stack(n,-1);
	vector<char>fault;
	int faults;
	for(int i=0;i<reference.size();i++){
		if(stack.size()<n){
			stack.insert(stack.begin(),reference[i]);
			fault.push_back('F');
			faults++;
		}
		else{
		    vector<int>::iterator it=find(stack.begin(),stack.end(),reference[i]);
		    if(it==stack.end()){
			stack.pop_back();
			stack.insert(stack.begin(),reference[i]);
		    fault.push_back('F');
			faults++;
		    }
			else{
			    stack.erase(it);
			    stack.insert(stack.begin(),reference[i]);
			    fault.push_back('H');
			}
			}
			cout<<"stack is:\n";
	for(int i=0;i<stack.size();i++){
	    cout<<stack[i]<<"\n";
	}
		}
	

	cout<<"Number of page faults: "<<faults<<"\n";
	cout<<"Instances of hits and faults for this string:";
	for(int i=0;i<reference.size();i++){
	    cout<<fault[i]<<"   ";
	}
}
