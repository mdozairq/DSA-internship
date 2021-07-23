//1. Nearest Smallest to left

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define s stack<int>

vi findNearestSmaller(vi &a, int n){
    vi ans(n);
    s stk;
    stk.push(n-1);
    ans[n-1]=-1;
    if(n==0){
        return ans;
    }

    for(int i=n-2;i>=0;i--){
        while(!stk.empty() && a[stk.top()]>=a[i])
            stk.pop();
        if(stk.empty()==true){
            ans[i]=-1;
            //continue;
        }
        else
        ans[i]=a[stk.top()];
        stk.push(i);
    }
    return ans; 
}

int main(){
    int n;
    cin>>n;
    vi ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    vi ans=findNearestSmaller(ar,n);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}