#include<iostream>
#include<cstdio>
using namespace std;
int find(int i, int* setone){
	if(setone[i]==i)
		return i;
	else
		return setone[i]=find(setone[i], setone);
}
void uni(int i, int j, int* setone, int* settwo){
	i=find(i, setone);
	j=find(j, setone);
	if(i==j)
		return;
	if(settwo[i]<settwo[j])
		setone[i]=j;
	else{
		setone[j]=i;
		if(settwo[i]==settwo[j])
			settwo[i]++;
	}
}
int main(){
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	int setone[n+1];
	int settwo[n+1];
	for(int k=1; k<=n; k++){
		setone[k]=k;
		settwo[k]=0;
	}
	for(int k=0; k<m; k++){
		scanf("%d %d", &i, &j);
		uni(i, j, setone, settwo);
	}
	int count[n+1];
	int cnt=0;
	for(int k=1; k<=n; k++){
		count[k]=0;
		setone[k]=find(setone[k], setone);
		count[setone[k]]++;
		if(count[k]!=0)
			cnt++;
	}
	cout<<cnt<<endl;
}
