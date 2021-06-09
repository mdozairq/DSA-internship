// 2. Find given element in sorted array.

#include <iostream>
using namespace std;
 
int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int ele = 10;
    int l=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int h = n-1;
    while(l<=h){
        int mid = l + (h - l) / 2;
    
        if (arr[mid] == ele){
            cout << "Element is present";
            return 0;
        }
        if (arr[mid] > ele){
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << "Element is not present in array";              
    return 0;
}