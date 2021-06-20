//implement heap Sort
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define itr(i,a,b) for(int i=a;i<b;i++)

void heapify(vi &a, int n, int i){
    int maxInx=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && a[l]>a[maxInx])
        maxInx=l;
    if(r<n && a[r]>a[maxInx])
        maxInx=r;

    if(maxInx != i){
        swap(a[i],a[maxInx]);
        heapify(a,n,maxInx);
    }
}
void heapSort(vi &a){
    int n=a.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(int i=n-1; i>0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    vi a(n);
    itr(i,0,n){
        cin>>a[i];
    }

    heapSort(a);
    itr(i,0,n){
        cout<<a[i]<<" ";
    }
    return 0;
}