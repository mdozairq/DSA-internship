// 5. Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            count0++;
        else if(arr[i]==1)
            count1++;
        else if(arr[i]==2)
            count2++;
       }

    for(int i=0;i<n;i++){
        if(i<count0)
            arr[i]=0;
        else if(i>=count0 && i<count0+count1)
            arr[i]=1;
        else if(i>=count0+count1 && i<count0+count1+count2)
            arr[i]=2;        
        }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}