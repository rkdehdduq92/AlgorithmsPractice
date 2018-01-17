#include<iostream>
#include<cstdio>
using namespace std;

int n;
int min, max;
int main(){
	cin>>n;
	int coordinate[5001];
	for(int i=1; i<=5000; i++)
		coordinate[i]=0;
	int totalstart=5001, totalend=0;
	for(int i=1; i<=n; i++){
		int start, end, height;
		cin>>start;
		cin>>end;
		cin>>height;
		if(totalstart>start)
			totalstart=start;
		if(totalend<end)
			totalend=end;
		for(int j=start; j<=end; j++){
			if(height>coordinate[j])
				coordinate[j]=height;
		}
	}
	int i=totalstart;
	while(i<=totalend){
		if(i==totalend)
			break;
		int start, end, height;
		start=i;
		height=coordinate[i];
		while(height==coordinate[i]){
			i++;
		}
		int newheight;
		if(coordinate[i]<coordinate[i-1]){
			coordinate[i-1]=coordinate[i];
			i--;
		}
		//i--;
		end=i;
		cout<<start<<" "<<end<<" "<<height<<endl;
	}	


}
