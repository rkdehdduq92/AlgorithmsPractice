#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct temp{
	int min;
	int max;
};
void merge(int h, int m, temp *U, temp *V, temp *temps){
	int i=0, j=0, k=0;
	while(i<h&&j<m){
		if(U[i].max<V[j].max){
			temps[k].min=U[i].min;
			temps[k].max=U[i].max;
			i++;
		} else{
			temps[k].min=V[j].min;
			temps[k].max=V[j].max;
			j++;
		}
		k++;
	}
	if(i>=h){
		for(int a=j; a<m; a++){
			temps[k].min=V[a].min;
			temps[k].max=V[a].max;
			k++;
		}
	} else{
		for(int a=i; a<h; a++){
			temps[k].min=U[a].min;
			temps[k].max=U[a].max;
			k++;
		}
	}
}
void mergesort(temp *temps, int count){
	int h=count/2;
	int m=count-h;
	temp U[h];
	temp V[m];
	if(count>1){
		for(int i=0; i<h; i++){
			U[i].min=temps[i].min;
			U[i].max=temps[i].max;
		}
		for(int i=h; i<count; i++){
			V[i-h].min=temps[i].min;
			V[i-h].max=temps[i].max;
		}
		mergesort(U, h);
		mergesort(V, m);
		merge(h, m, U, V, temps);
	}
}
int main(){
	int count;
	cin>>count;
	temp temps[count];
	for(int i=0; i<count; i++){
		scanf("%d %d", &temps[i].min, &temps[i].max);
	}
	mergesort(temps, count);
	//cout<<endl;
	/*for(int i=0; i<count; i++){
		cout<<temps[i].min<<" "<<temps[i].max<<endl;
	}*/
	int pin=temps[0].max;
	int total=1;
	for(int i=0; i<count; i++){
		if(temps[i].min>pin||temps[i].max<pin){
			pin=temps[i].max;
			total++;
		}	
	}
	cout<<total<<endl;
}
