#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int>refernce{62,12,100,119,2};
	sort(refernce.begin(),refernce.end());
	int n=92;
	int completed=0;
	int k=refernce.size();
	while(completed!=k)
	{
		int temp=0;
		for(int i=0;i<refernce.size();i++){
			if(refernce[i]<n&&refernce[i+1]>n){
				int a=n-refernce[i];
				int b=refernce[i+1]-n;
				temp=a>b?i+1:i;
                cout<<refernce[temp]<<"\n";
                n=refernce[temp];
				break;
				
			}
			if(i==refernce.size()-1){
			   cout<<refernce[i]<<"\n";
                n=refernce[i];
                	temp=i;
				break; 
			
			}
		}
		
		completed++;
		refernce.erase(refernce.begin()+temp);
	}
	
}

