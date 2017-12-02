#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int clothes[N];
	for(int i=0; i<N; i++){
		cin>>clothes[i];
	}
	int heat;
	cin>>heat;
	int minute=0;
	while(1){
		bool alldried=true;
		for(int i=0; i<N; i++){
			if(clothes[i]!=0)
				alldried=false;
		}
		if(alldried)
			break;

		int radiator=0;
		for(int i=0; i<N; i++){
			if(clothes[radiator]<clothes[i])
				radiator=i;
		}
		if(clothes[radiator]!=0){
			clothes[radiator]-=heat;
			if(clothes[radiator]<0)
				clothes[radiator]=0;
		}
		for(int i=0; i<N; i++){
			if(i!=radiator){
				if(clothes[i]!=0)
					clothes[i]-=1;
			}
		}
		minute+=1;
	}
	cout<<minute<<endl;

}
