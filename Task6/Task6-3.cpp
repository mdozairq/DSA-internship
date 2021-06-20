//Imolementation of Radix Sort
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define itr(i,a,b) for(int i=a;i<b;i++)

int getMax(vi &a){
    int n=a.size();
    int mx=a[0];
    
    itr(i,0,n)
        mx=max(a[i],mx);
    return mx;
}
void countSort(vi &a, int n, int pos){
    vi b(n),count(10);
    int i;
    count[10]={0};
    itr(i,0,n){
        ++count[(a[i]/pos)%10];
    }
    itr(i,1,10){
        count[i]+=count[i-1];
    }
    //making output array
    for(i=n-1;i>=0;i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    itr(i,0,n){
        a[i]=b[i];
    }
}
void radixSort(vi &a){
    int n=a.size();
    int mx=getMax(a);
    int pos;
    for(pos=1; mx/pos>0; pos*=10){
        countSort(a,n,pos);
    }
}  
int main(){
    int n;
    cin>>n;
    vi s(n);
    itr(i,0,n){
        cin>>s[i];
    }
    radixSort(s);
    itr(i,0,n)
        cout<<s[i]<<" ";
    return 0;
}