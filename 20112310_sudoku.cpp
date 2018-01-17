#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

char sudoku[9][9];
vector <pair<int, int> > zeroposition;

void promising(int index);
int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>sudoku[i][j];
			if(sudoku[i][j]=='0')
				zeroposition.push_back(make_pair(i, j));
		}
	}
	promising(0);
}

bool finish=false;
void promising(int index){
	if(index>=zeroposition.size()){
        for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
                cout<<sudoku[i][j];
            }
            cout<<endl;
        }
        finish=true;
    }
	if(finish)
		return;
	int x=zeroposition[index].first;
	int y=zeroposition[index].second;
	for(int i=1; i<=9; i++){
		bool isavailable=true;
		char convert=i+48;
		for(int j=0; j<9; j++){
			if(sudoku[x][j]==convert||sudoku[j][y]==convert)
				isavailable=false;
		}
		for(int j=(x/3)*3; j<(x/3)*3+3; j++){
			for(int k=(y/3)*3; k<(y/3)*3+3; k++){
				if(sudoku[j][k]==convert)
					isavailable=false;
			}
		}
		if(!isavailable)
			continue;
		else{
			sudoku[x][y]=convert;
		}
		promising(index+1);
	}
	sudoku[x][y]='0';
}
