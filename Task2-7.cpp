// 7. Find the Union and Intersection of the two sorted arrays.

#include<iostream>
using namespace std;

int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
       i++; 
    else if (arr2[j] < arr1[i]) 
       j++; 
    else 
    { 
       cout << arr2[j] << " "; 
       i++; 
       j++; 
    } 
  } 
} 

int printUnion(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
       cout << arr1[i++] << " "; 
      
    else if (arr2[j] < arr1[i]) 
       cout << arr2[j++] << " "; 
      
    else
    { 
       cout << arr2[j++] << " "; 
       i++; 
    } 
  } 
  
  while(i < m) 
     cout << arr1[i++] << " "; 
  
  while(j < n) 
    cout << arr2[j++] << " "; 
} 

int main(){
    int m;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int n;
    cin>>n;
    int arr2[n];
    int count = 0;
    
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"Union elements in The Array :";
    printUnion(arr1, arr2, m, n);
    cout<<"Intersected elements in The Array :";
    printIntersection(arr1, arr2, m, n);
    
    return 0;
}