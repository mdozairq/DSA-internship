//6. Rain water trapping. //(Imp problem)

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define s stack<int>

int trapRain(vi a, int n){
    s st;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
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
    int ans=trapRain(ar,n);
    cout<<ans<<" ";
    return 0;
}