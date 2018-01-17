#include<iostream>
#include<cstdio>

using namespace std;

struct connect{
	int start;
	int end;
	bool check;
};
connect* network;
bool* infected;
int num, connum;
void bfs(int i);
int main(){
	cin>>num;
	cin>>connum;
	network=new connect[connum];
	infected=new bool[num+1];
	for(int i=1; i<=num; i++){
		infected[i]=false;
	}
	for(int i=0; i<connum; i++){
		cin>>network[i].start;
		cin>>network[i].end;
		network[i].check=false;
	}
	bfs(1);
	int count=0;
	for(int i=1; i<=num; i++){
		if(infected[i])
			count++;
	}
	cout<<count-1<<endl;
}
void bfs(int i){
	infected[i]=true;
	for(int j=0; j<connum; j++){
		if(!network[j].check){
			if(network[j].start==i){
				network[j].check=true;
				bfs(network[j].end);
			}
			if(network[j].end==i){
				network[j].check=true;
				bfs(network[j].start);
			}
		}
	}
}
