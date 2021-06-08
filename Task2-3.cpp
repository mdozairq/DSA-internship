// 3. Find the maximum and minimum element in an array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max=0,min;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }

    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
        else if(max>arr[i]){
            min=arr[i];
        }
    }
cout<<"Maximum Element in Array :"<<max<<endl;
cout<<"Minimum Element in Array :"<<min<<endl;
return 0;
}