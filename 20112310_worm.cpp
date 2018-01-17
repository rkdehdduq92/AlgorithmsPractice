#include<iostream>
#include<cstdio>
using namespace std;

int a, b, d, n;
int main(){
	cin>>a;
	cin>>b;
	cin>>d;
	cin>>n;
	int count[n+1];
	count[0]=1;
	for(int i=1; i<=n; i++){
		count[i]=count[i-1];
		if(i-a>=0){
			count[i]+=count[i-a];
		}
		if(i-b>=0){
			count[i]-=count[i-b];
		}
		count[i]=count[i]%1000;
	}
	/*for(int i=1; i<=n; i++){
		cout<<count[i]<<endl;
	}*/
	if(n-d>=0)
		cout<<(count[n]-count[n-d]+2000)%1000<<endl;
	else
		cout<<(count[n]+2000)%1000<<endl;
}
