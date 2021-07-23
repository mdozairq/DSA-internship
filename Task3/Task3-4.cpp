// 4. Find given element in rotated sorted array.

#include <iostream> 
using namespace std;

int binSearch(int arr[], int l, int h, int ele){
    if(h<l){
        return -1;
    }

    while(l<=h){
        int mid = l + (h - l) / 2;
    
        if (arr[mid] == ele){
            return mid;
        }
        if (arr[mid] > ele){
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
}

int smallestElementIndex(int arr[], int l, int h){
    int last = arr[h];
    if(h<l){
        return -1;
    }
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
    return l;
}

    
int main() 
{ 
    int n,mid;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ele;
    cin>>ele;
    int l = 0;
    int h = n-1;
    int index = smallestElementIndex(arr, l, h);
    if(index == -1){
        mid=binSearch(arr, l, h, ele);
        if(mid == -1){
            cout<<"The given element is Not present in the given array."<<endl;
        }
        else
        cout<<"The given element is present at the index "<<mid<<" of the given array."<<endl; 
    }
    else if(arr[index] == ele){
        cout<<"The given element is present at the index "<<index<<" of the given array."<<endl;
    }
    else if(arr[index] <= ele)
    {
        mid=binSearch(arr, l, index-1, ele);
        if(mid == -1){
            cout<<"The given element is Not present in the given array."<<endl;
        }
        else
        cout<<"The given element is present at the index "<<mid<<" of the given array."<<endl;
    }
    else{
        mid=binSearch(arr, index+1, h, ele);
        if(mid == -1){
            cout<<"The given element is Not present in the given array."<<endl;
        }
        else
        cout<<"The given element is present at the index "<<mid<<" of the given array."<<endl; 
    }
  return 0; 
} 