// 2. Reverse the array

#include<iostream>
using namespace std;

int main(){
    int n,l=0,h;
    cin>>n;
    h=n-1;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //Reversing the Array
    while(l<h){
        int temp=arr[l];
        arr[l]=arr[h];
        arr[h]=temp;
        l++;
        h--;
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}