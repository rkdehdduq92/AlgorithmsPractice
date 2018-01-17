#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int row, col;
	cin>>row>>col;
	int costs[row][col];
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>costs[i][j];
		}
	}
}
