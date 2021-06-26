//The celebrity problem //(VVIMP and Famous also)
#include<bits/stdc++.h>
#define s stack<int>
#define n 4
using namespace std;

int findCelebrity(int arr[n][n]){
    s st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    if(st.empty())
        return -1;
    
    while(st.size()>=2){
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(arr[i][j]==1){
            st.push(j);
        }
        else{
            st.push(i);
        } 
    }
    int c=st.top();
    st.pop();

    for(int i=0;i<n;i++){
        if((i!=c)&&(arr[i][c]==0 || arr[c][i]==1))
            return -1;
    }

    return c;
}
int main(){
    int ar[n][n]={{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 0, 0},{0, 0, 1, 0}};
    int id=findCelebrity(ar);
    cout<<id<<endl;
    return 0;
}