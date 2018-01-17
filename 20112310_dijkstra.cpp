#include<iostream>
#include<cstdio>
using namespace std;

int** W;
int n;

int main(){
	cin>>n;
	W=new int*[n+1];
	for(int i=0; i<=n; i++){
		W[i]=new int[n+1];
		for(int j=0; j<=n; j++){
			W[i][j]=101;
		}
	}

	int m;
	cin>>m;
	int start;
	cin>>start;

	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a;
		cin>>b;
		cin>>c;
		W[a][b]=c;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<W[i][j]<<" ";
		}
		cout<<endl;
	}
}
