#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int xsize, ysize;
int xstart, ystart;
int numofbeep;
int* vindex
struct xy{
	int x, y;
	int distance;
	bool check;
};
xy* beepers;

void beeper(int i);
bool promising(int i);
int main(){
	cin>>xsize;
	cin>>ysize;
	cin>>xstart;
	cin>>ystart;
	cin>>numofbeep;
	beepers=new xy[numofbeep];
	vindex=new int[numofbeep];
	for(int i=0; i<numofbeep; i++){
		cin>>beepers[i].x;
		cin>>beepers[i].y;
		beepers[i].distance=0;
		beepers[i].check=false;
	}
	beeper(0);
}
void beeper(int i){
	if(i<=numofbeep){
		
	}
}
