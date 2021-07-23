// 5. Find given element in sorted array using ternary search

#include<iostream>
using namespace std;

int ternarySearch(int arr[], int l, int h, int ele) {
   if(l <= h) {
      int m1 = (l + (h - l) /3); 
      int m2 = (m1 + (h - l) /3); 
      if(arr[m1] == ele)
         return m1;
      if(arr[m2] == ele)
         return m2;
      if(ele < arr[m1])
         return ternarySearch(arr, l, m1-1, ele);
      if(ele > arr[m2])
         return ternarySearch(arr, m2+1, h, ele);
      return ternarySearch(arr, m1+1, m2-1, ele);
   }
   return -1;
}

int main() {
   int n, ele, index;
   cin >> n;
   int arr[n]; //create an array of size n
   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }

   cin >> ele;
   if((index = ternarySearch(arr, 0, n, ele)) >= 0)
      cout << "The given element is present at " << index << endl;
   else
      cout << "The given element is not present." << endl;
}