#include<iostream>
#include<cstdio>

using namespace std;

int n=0;
int* a;
bool* b;
int k=0;

bool dfs(int i, int sum);
int main(){
	cin>>n;
	a=new int[n];
	b=new bool[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>k;
	if(dfs(0, 0)){
		cout<<"yes"<<endl;
		for(int i=0; i<n; i++)
			cout<<b[i];
		cout<<endl;
	}
	else
		cout<<"no"<<endl;
}
bool dfs(int i, int sum){
	if(i==n)
		return sum==k;
	b[i]=false;
	if(dfs(i+1, sum)){
		return true;
	}
	b[i]=true;
	if(dfs(i+1, sum+a[i])){
		return true;
	}
	return false;
}


