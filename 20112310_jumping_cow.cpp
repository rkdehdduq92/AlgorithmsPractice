#include<iostream>
#include<queue>
using namespace std;

int n;
int* plusd;
int* minusd;
queue<int> que;
int main(){
	cin>>n;
	plusd=new int[n];
	minusd=new int[n];
	int j;
	for(int i=0; i<n; i++){
		cin>>j;
		que.push(j);
	}

	bool trueisplus=true;
	int p=0, m=0;
	plusd[p]=que.front();
	que.pop();
	while(true){
		if(que.empty()){
			if(trueisplus)
				m--;
			if(!trueisplus){
				p--;
				m--;
			}
			break;
		}
		if(trueisplus){
			if(que.front()<plusd[p]){
				trueisplus=false;
				minusd[m]=que.front();
				que.pop();
				p++;
				continue;
			}
			else{
				plusd[p]=que.front();
				que.pop();
			}
		}
		if(!trueisplus){
			if(que.front()>minusd[m]){
				trueisplus=true;
				plusd[p]=que.front();
				que.pop();
				m++;
				continue;
			}
			else{
				minusd[m]=que.front();
				que.pop();
			}
		}
	}
	//cout<<p<<" "<<m<<endl;
	int result;
	/*for(int i=0; i<=p; i++)
		cout<<plusd[i]<<" ";
	cout<<endl;
	for(int i=0; i<=m; i++)
		cout<<minusd[i]<<" ";
	cout<<endl;*/
	for(int i=0; i<=p; i++)
		result+=plusd[i];
	for(int i=0; i<=m; i++)
		result-=minusd[i];
	cout<<result<<endl;
}
