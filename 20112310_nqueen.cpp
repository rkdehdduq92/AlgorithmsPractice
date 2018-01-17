#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, count=0;
int* col;

void queens(int i);
bool promising(int i);
int main(void){
	cin>>n;
	col=new int[n+1];
	for(int i=1; i<=n; i++)
		col[i]=0;
	queens(0);
	cout<<count<<endl;
}
void queens(int i){
	int j;
	if(promising(i)){
		if(i==n){
			if(count<3){
				for(j=1; j<=n; j++)
					cout<<col[j]<<" ";
				cout<<endl;
			}
			count++;
		}
		else{
			for(j=1; j<=n; j++){
				col[i+1]=j;
				queens(i+1);
			}
		}
	}
}
bool promising(int i){
	int k=1;
	bool promise=true;

	while(k<i && promise){
		if((col[i]==col[k])||(abs(col[i]-col[k])==i-k))
			promise=false;
		k++;
	}
	return promise;
}
