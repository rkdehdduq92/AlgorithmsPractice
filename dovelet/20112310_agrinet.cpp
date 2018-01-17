#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;

int n=0;
int ** vertex;
struct cable{
	int start;
	int end;
	int weight;
};
queue <cable> lists;//list는 책에서의 F 역할
//cable* list;

int main(){
	cin>>n;
	vertex=new int*[n+1];
	for(int i=1; i<=n; i++){
		vertex[i]=new int[n+1];
		for(int j=1; j<=n; j++){
			cin>>vertex[i][j];
		}
	}

	int i, vnear;
	int min;
	cable e;
	int nearest[n+1];
	int distance[n+1];

	for(i=2; i<=n; i++){
		nearest[i]=1;
		distance[i]=vertex[1][i];
	}

	for(int j=1; j<n; j++){//repeat n-1 times
		min=100000;
		for(i=2; i<=n; i++){
			if(0<=distance[i]&&distance[i]<min){
				min=distance[i];
				vnear=i;
			}
		}
		for(i=1; i<=n; i++){
			for(int k=i+1; k<=n; k++){
				if(vertex[i][k]==min){
					e.start=i;
					e.end=k;
					e.weight=min;
				}
			}
		}
		lists.push(e);
		distance[vnear]=-1;
		for(i=2; i<=n; i++){
			if(vertex[i][vnear]<distance[i]){
				distance[i]=vertex[i][vnear];
				nearest[i]=vnear;
			}
		}

	}
	int count=0;
	for(i=1; i<n; i++){
		e=lists.front();
		//cout<<e.weight<<endl;
		count+=e.weight;
		lists.pop();
	}
	cout<<count<<endl;
}

