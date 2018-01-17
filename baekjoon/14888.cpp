#include<iostream>
#include<cstdio>
using namespace std;

int N;
int * nums;
int * opers;
int maxnum, minnum;
void calculate(int n, int cal);
int calc(int c, int n, int i);
int main(){
	cin>>N;
	nums=new int[N];
	opers=new int[4];
	for(int i=0; i<N; i++)
		cin>>nums[i];
	cin>>opers[0]>>opers[1]>>opers[2]>>opers[3];
	maxnum=-1000000001;
	minnum=1000000001;
	calculate(1, nums[0]);
	cout<<maxnum<<endl;
	cout<<minnum<<endl;
}
void calculate(int n, int cal){
	if(n>=N){
		maxnum=(cal>maxnum)? cal: maxnum;
		minnum=(cal<minnum)? cal: minnum;
	}
	for(int i=0; i<4; i++){
		if(opers[i]>0){
			opers[i]--;
			calculate(n+1, calc(cal, nums[n], i));
			opers[i]++;
		}
	}
}
int calc(int c, int n, int i){
	if(i==0)
		return c+n;
	if(i==1)
		return c-n;
	if(i==2)
		return c*n;
	if(i==3)
		return c/n;
}



