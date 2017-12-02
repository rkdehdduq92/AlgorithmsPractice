#include<iostream>
using namespace std;
int main(){
	int count;
	cin>>count;
	int array[count];
	for(int i=0; i<count; i++){
		cin>>array[i];
	}

	int find;
	cin>>find;
	int low=0, high=count-1;
	int mid;
	bool found=false;
	while(low+1<high){
		mid=(low+high)/2;
		if(array[mid]==find){
			found=true;
			break;
		}
		else if(array[mid]<find)
			low=mid;
		else if(array[mid]>find)
			high=mid;
	}
	if(found){
		mid+=1;
		cout<<mid<<endl;
	}
	else
		cout<<"not found"<<endl;
}
