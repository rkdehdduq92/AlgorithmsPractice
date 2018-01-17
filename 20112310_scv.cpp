#include<iostream>
#include<cstdio>
using namespace std;

int n;
int **map;
int max(int a, int b);
int main(){
	cin>>n;
	map=new int*[n];
	for(int i=0; i<n; i++){
		map[i]=new int[n];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>map[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==0)
				map[i][j]=map[i][j]+map[i][j-1];
			else if(j==0)
				map[i][j]=map[i][j]+map[i-1][j];
			else
				map[i][j]=map[i][j]+max(map[i-1][j], map[i][j-1]);
		}
	}
	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<map[n-1][n-1]<<endl;
}

int max(int a, int b){
	return a>b? a : b;
}
