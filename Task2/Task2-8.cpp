// 8. Given an array of digits check if the array is palindrome or not.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],l=0,h=n-1;
    int count = 0;
    bool flag=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(l<h){
        if(arr[l]==arr[h]){
            flag=1;
            l++;
            h--;
        }
        else
            flag=0;
            break;
    }
    if(flag==1)
    cout<<"It is the Pallindrome Array";
    else
    cout<<"It is Not the Pallindrome Array";

    return 0;
}