//Implementation of MIN STACK
#include<bits/stdc++.h>
using namespace std;
#define sp stack<pair<int,int>>
#define s stack<int>
#define vp vector<pair<int,int>>
#define v vector<int>
#define n 6

class MinStack{
    public:
        int top;
        int i;
        int s1[n];
        int s2[n];
        
        MinStack(){
            top=-1;
            i=-1;
            s1[n]={0};
            s2[n]={0};
        }

        bool empty(){
            if(top==-1){
                return true;
            }
            return false;
        }

        void push(int val){
            if(empty()){
                top=i=0;
                s1[i]=val;
                s2[i]=val;
                return;
            }
            else{
                i++;
                if(s2[top]>val){
                    s1[i]=val;
                    s2[i]=val;
                    top++;
                }
                else
                {
                    s1[i]=val;
                    s2[i]=s2[top];
                    top++;
                }
            }
        }

        void pop(){
            if(!empty()){
                top--;
            }
            else{
                cout<<"Stack Undeflow"<<endl;
                return;  
            }
        }

        int Top(){
            if(empty()){
               cout<<"Stack Undeflow"<<endl;
                return -1; 
            }
            else
                return s1[top];
        }

        int getMin(){
            if(empty()){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else
                return s2[top];
        }
};


int main(){
    MinStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(-3);
    ms.push(4);
    ms.push(-5);
    ms.push(6);
    ms.pop();
    ms.pop();
    /*for(int i=0;i<n;i++){
        cout<<ms.s1[i]<<" "<<ms.s2[i]<<endl;
    };*/
    cout<<ms.getMin()<<endl;

    return 0;
}