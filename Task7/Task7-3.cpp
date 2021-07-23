//1. Nearest Smaller to Right

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define s stack<int>

vi findNearestGreaterLeft(vi &a, int n){
    vi ans(n);
    s stk;
    stk.push(0);
    ans[0]=-1;
    if(n==0){
        return ans;
    }

    for(int i=1;i<n;i++){
        while(stk.empty()!=true && a[stk.top()]<=a[i])
            stk.pop();
        if(stk.empty()==true){
            ans[i]=-1;
            //stk.push(i);
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
    vi ans=findNearestGreaterLeft(ar,n);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}