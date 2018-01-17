#include<iostream>

using namespace std;

int count(int** fscore, int col, int find, int numv){
	int result=0;
	for(int i=0; i<numv; i++){
		if(fscore[col][i]==find)
			result=i;
	}
	return result;
}
int max(int *scores, int i, int j){//return max value between scores[0]~scores[j-1] 
	int max=-999999;
	for(i; i<j; i++){
		if(scores[i]>max)
			max=scores[i];
	}
	return max;

}
int main(){
	int numf, numv;//num of flowers, vases
	cin>>numf;
	cin>>numv;
	int vases[numv];
	int fscore[numf][numv];
	for(int i=0; i<numf; i++){
		for(int j=0; j<numv; j++){
			cin>>fscore[i][j];
		}
	}
	int result=-999999;
	int scores[numf][numv];
	//scores[i][j]=max value when ith flower was in jth vase
	for(int i=0; i<numf; i++){
		for(int j=0; j<numv; j++){
			scores[i][j]=0;
		}
	}
	for(int i=0; i<numv; i++){
		scores[0][i]=fscore[0][i];
	}
	for(int i=1; i<numf; i++){
		for(int j=0; j<numv; j++){
			if(j<i)
				scores[i][j]=0;
			else
				scores[i][j]=max(scores[i-1], i-1, j)+fscore[i][j];
		}
	}
	/*for(int i=0; i<numf; i++){
		for(int j=0; j<numv; j++){
			cout<<scores[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<max(scores[numf-1],numf-1, numv)<<endl;

}
