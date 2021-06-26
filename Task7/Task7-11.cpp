//11. minimum number of deletion required to balance the parantesis

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
                    st.pop();
                    //count++;
                }
        }
        
    return st.size();
}

int main(){
    string ss;
    cin>>ss;
    cout<<"Minimum Number of deletion required to Balance the Parenthesis : "<<longestValidParentesis(ss)<<endl;
    return 0;
}
