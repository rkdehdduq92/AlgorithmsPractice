#include<iostream>
#include<cstdio>

using namespace std;
int maxcal, count;
int * baskets;
bool * eats;
int maxcalory=0;
bool promising(int index);
void puzzle(int i, int eatcalory);
int main(){
	cin>>maxcal>>count;
	baskets=new int[count+1];
	eats=new bool[count+1];
	for(int i=1; i<=count; i++){
		cin>>baskets[i];
	}
	puzzle(0, 0);
	cout<<maxcalory;
}
void puzzle(int i, int eatcalory){
	if(i<=count){
		if(eatcalory>maxcalory)
			maxcalory=eatcalory;
		if(eatcalory+baskets[i+1]<=maxcal){
			eats[i+1]=true;
			puzzle(i+1, eatcalory+baskets[i+1]);
		}
		eats[i+1]=false;
		puzzle(i+1, eatcalory);
	}
}

