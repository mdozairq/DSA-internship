//5. Maximum area of histogram. //(This is also Famous problem)

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define s stack<int>
#define pi pair<int,int>
#define stp stack<pair<int,int>>

int maxAreaHistogram(vi a){
    int n=a.size();
    int ans=0,i=0;
    s stk;
    a.push_back(0);
    while(i<n){
        while(!stk.empty() and a[stk.top()]>a[i]){
            int t=stk.top();
            int h=a[t];
            stk.pop();
            if(stk.empty()){
                ans = max(ans, h*i);
            }
            else{
                int len=i-stk.top()-1;
                ans=max(ans,h*len);
            }
        }
        stk.push(i);
        i++;
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
    cout<<maxAreaHistogram(ar);
    return 0;
}

