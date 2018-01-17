#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void quickSort(int arr[], int left, int right){
    int &pivot = arr[left];
    int i = left + 1;
    int j = right;

    while(i <= j){
        //find larger than pivot
        while(i <= right && arr[i] < pivot)i++;
        while(j >= left && arr[j] > pivot)j--;
        //finded! and swap the values.
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    //j that smaller than pivot swap the pivot.
    swap(pivot, arr[j]);
    if(left < j) quickSort(arr, left, j);
    if(i < right) quickSort(arr, i, right);
}
int print (int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ",";
    }
}
int main(){
    int arr[9] = {1,12, 5, 26, 7,14,3,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n);
    print(arr, n);
}

