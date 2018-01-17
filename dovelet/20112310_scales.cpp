#include<iostream>
#include<cstdio>
using namespace std;

int n;
int totweight=0;
int* weights;
bool * takes;
int count=0;

void scale(int num, int curweight);
int main(){
	cin>>n;
	weights=new int[n+1];
	takes=new bool[n+1];
	for(int i=1; i<=n; i++){
		cin>>weights[i];
		totweight+=weights[i];
		takes[i]=false;
	}
	if(totweight%2==1)
		cout<<"impossible"<<endl;
	else{
		scale(0, 0);
		cout<<count<<endl;
	}

}
void scale(int num, int curweight){
	if(num<=n){
		int leftweight=0;
		for(int j=num+1; j<=n; j++)
			leftweight+=weights[j];
		if(curweight<=(totweight/2)){
			if(curweight==(totweight/2)){
				count++;
			}
			else{
				if(curweight+weights[num+1]<=(totweight/2)){
					takes[num+1]=true;
					scale(num+1, curweight+weights[num+1]);
            	}
				takes[num+1]=false;
            	scale(num+1, curweight);
			}
		}
	}
}
