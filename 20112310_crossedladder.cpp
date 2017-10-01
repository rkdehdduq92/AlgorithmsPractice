#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

double bisection(double x, double y, double low, double high, double c);
int main(){
	double x, y, c;
	cin>>x>>y>>c;
	double low=0;
	double high=x>y? y:x;
	double result=bisection(x, y, low, high, c);
	printf("%.3f\n", result);
}

double bisection(double x, double y, double low, double high, double c){
	double result=0;
	double mid;
	mid=(low+high)/2;
	result=c/sqrt(x*x-mid*mid)+c/sqrt(y*y-mid*mid)-1;
	if(result>0&&result<1.0e-7)
		return mid;
	else if(result>0)
		return bisection(x, y, low, mid, c);
	else if(result<0)
		return bisection(x, y, mid, high, c);

}
