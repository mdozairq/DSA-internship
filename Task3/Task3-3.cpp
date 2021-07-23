// 3. Find minimum element in rotated sorted array.

#include <iostream> 
using namespace std; 
    
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int l = 0;
    int h = n-1;
    int last = arr[h];
    while(l<h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]>last) 
        {
            l=mid+1;
        } 
        else 
        {
            h=mid;
        }
    }
    cout<<arr[l]<<endl;
  return 0; 
} 