#include<iostream>
#include<cstdlib>

using namespace std;
int max(int a, int b){
	return a>b? a:b;
}
int main(){
	int staircount;
	cin>>staircount;
	int scores[staircount];
	for(int i=0; i<staircount; i++){
		cin>>scores[i];
	}
	int first[staircount];
	int second[staircount];
	first[0]=scores[0];//first steps on first stair
	first[1]=scores[1];//first steps on second stair
	second[0]=0;//second steps on first floor(impossible)
	for(int i=1; i<staircount; i++){
		if(i==1)
			second[i]=scores[0]+scores[1];//second steps on second floor
		else{
			first[i]=max(first[i-2], second[i-2])+scores[i];
			//first steps on i-1th floor=get jump from i-3th floor
			second[i]=first[i-1]+scores[i];
			//second steps on i-1th floor=one step from i-2th floor
		}
	}
	/*cout<<endl;
	for(int i=0; i<staircount; i++){
		cout<<first[i]<<" "<<second[i]<<endl;
	}*/
	int result=max(first[staircount-1], second[staircount-1]);
	cout<<result<<endl;
}
