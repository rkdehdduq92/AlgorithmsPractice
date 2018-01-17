#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int N, Q;
	scanf("%d", &N);
	scanf("%d", &Q);
	int height[N];
	for(int i=0; i<N; i++){
		cin>>height[i];
	}
	for(int i=0; i<Q; i++){
		int low, high;
		scanf("%d", &low);
		scanf("%d", &high);
		int max=*max_element(height+low-1, height+high);
		int min=*min_element(height+low-1, height+high);
		cout<<max-min<<endl;
	}

}
