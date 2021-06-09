// 1. Find given element in given array (might be unsorted)
#include<iostream>
using namespace std;

int main(){
    int n,l=0,h;
    cin>>n;
    h=n-1;
    int arr[n];
    bool flag;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ele;
    cin>>ele;

    for(int i=0; i<n; i++){
        if(arr[i]==ele){
            flag=1;
            break;
        }
    }

    if(flag==1)
        cout<<"The Given Element is present"<<endl;
    else
        cout<<"The Given Element is Not present"<<endl;
        
    return 0;
}