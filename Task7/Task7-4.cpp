//4. Stock Span Problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define s stack<int>
#define pi pair<int,int>
#define stp stack<pair<int,int>>

vi stockSpan(vi &a){
    vi ans;
    stp stk;
    for(auto i: a){
        int days=1;
        while(!stk.empty() and stk.top().first<=i){
            days +=stk.top().second;
            stk.pop();
        }
        stk.push({i,days});
        ans.push_back(days);
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
    vi ans=stockSpan(ar);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}