#include<iostream>
#include<cstdio>

using namespace std;

int n;
int ** map;
void danji(int i, int j, int count);
int main(){
	cin>>n;
	map=new int*[n];
	for(int i=0; i<n; i++){
		map[i]=new int[n];
		for(int j=0; j<n; j++){
			cin>>map[i][j];
		}
	}
	int count=2;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]==1){
				danji(i, j, count);
				count++;
			}
		}
	}

	//answer
	cout<<count-2<<endl;
	int counts[count+1];
	for(int i=2; i<count; i++){
		counts[i]=0;
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(map[j][k]==i)
					counts[i]++;
			}
		}
	}
	//sorting the answer
	for(int i=2; i<count; i++){
		for(int j=i+1; j<count; j++){
			if(counts[i]>counts[j]){
				int tmp=counts[i];
				counts[i]=counts[j];
				counts[j]=tmp;
			}
		}
	}
	for(int i=2; i<count; i++)
		cout<<counts[i]<<endl;
			

}
void danji(int i, int j, int count){
	map[i][j]=count;
	int di, dj;
	//4-direction check
	di=0;
	for(dj=-1; dj<=1; dj++){
		int nj=j+dj;
		if(0<=nj&&nj<n&&map[i][nj]==1)
			danji(i, nj, count);
	}
	dj=0;
	for(di=-1; di<=1; di++){
		int ni=i+di;
		if(0<=ni&&ni<n&&map[ni][j]==1)
			danji(ni, j, count);
	}
}
