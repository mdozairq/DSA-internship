// 4. Find the "Kth" max and min element of an array

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int max,min;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    sort(arr, arr + n);
    max = arr[n-k];
    min = arr[k-1];

    cout<<"Maximum Kth Element in the Array :"<<max<<endl;
    cout<<"Minimum Kth Element in the Array :"<<min<<endl;

    return 0;
}
