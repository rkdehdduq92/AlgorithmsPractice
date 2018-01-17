#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	char input[30];
	for(int i=0; i<=30; i++)
		input[i]=0;
	cin>>input;
	unsigned long long int decimal=1LL;
	unsigned long long int output=0LL;
	for(int i=29; i>=0; i--){
		if(input[i]=='0'){
			decimal*=2;
		}
		if(input[i]=='1'){
			output+=decimal;
			decimal*=2;
		}
	}
	cout<<output;


}
