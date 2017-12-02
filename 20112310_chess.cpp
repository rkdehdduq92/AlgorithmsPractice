#include<iostream>

using namespace std;

int main(){
	int wscore[30];
	int bscore[30];
	for(int i=0; i<30; i++){
		cin>>wscore[i];
		cin>>bscore[i];
	}
	int scores[2][30];
	//scores[0][n]:nth player goes to white team, scores[1][n]:nth player goes to black team
	scores[0][0]=wscore[0];
	scores[1][0]=bscore[0];
}
