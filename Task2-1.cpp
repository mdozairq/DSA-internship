// Questions on arrays:
// 1. Find length of an array

#include<iostream>
using namespace std;

int main(){

    int arr[]={1,4,8,9,3,2};

    int length_of_Array = sizeof(arr)/sizeof(arr[0]);//finding the size of array
    cout<<length_of_Array<<endl;
    return 0;
}