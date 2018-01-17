#include<iostream>
#include<cstdio>

using namespace std;

int n=0, m=0;
char** nm;

void dfs(int n, int m);
int main(){
	int count=0;
	cin>>n;
	cin>>m;
	nm=new char*[n];
	for(int i=0; i<n; i++){
		nm[i]=new char[m];
		for(int j=0; j<m; j++){
			cin>>nm[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(nm[i][j]=='W'){
				dfs(i, j);
				count++;
			}
		}
	}
	cout<<count<<endl;

}
void dfs(int n, int m){
	nm[n][m]='.';
	for(int dx=-1; dx<=1; dx++){
		for(int dy=-1; dy<=1; dy++){
			int nx=n+dx;
			int ny=m+dy;
			if(0<=nx&&nx<n&&0<=dy&&ny<m&&nm[nx][ny]=='W')
				dfs(nx, ny);
		}
	}
}

