#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
void sort(int min[], int max[], int count){
    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            if(max[i]>max[j]){
                /*int temp;
                temp=max[i];
                max[i]=max[j];
                max[j]=temp;
                temp=min[i];
                min[i]=min[j];
                min[j]=temp;*/
                swap(max[i], max[j]);
                swap(min[i], min[j]);
 
            }
        }
    }
}
int main(){
    int count;
    cin>>count;
    int min[count];
    int max[count];
    for(int i=0; i<count; i++){
        cin>>min[i];
        cin>>max[i];
    }
    sort(min, max, count);
	cout<<endl;
    for(int i=0; i<count; i++){
        cout<<min[i]<<" "<<max[i]<<endl;
    }
    int pin=max[0];
    int total=1;
    for(int i=0; i<count; i++){
        if(min[i]<=pin&&max[i]>=pin){
        } else{
            pin=max[i];
			cout<<pin<<endl;
            total++;
        }
    }
    cout<<total<<endl;
}
