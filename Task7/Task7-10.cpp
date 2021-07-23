//10. Longest valid parentesis
#include<bits/stdc++.h>
#define s stack<char>
using namespace std;

int longestValidParentesis(string p){
    s st;
    int count=0;
    for(int i=0;i<p.size();i++){
                if(p.at(i)=='(')
                    st.push(p.at(i));
                else{
                    if(!st.empty())
                    st.pop();
                    count++;
                }
        }
        
    return count;
}

int main(){
    string ss;
    cin>>ss;
    cout<<longestValidParentesis(ss)<<endl;
    return 0;
}
