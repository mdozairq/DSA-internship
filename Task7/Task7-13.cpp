//implementation of Queue using Stack
#include<bits/stdc++.h>
#define s stack<int>
using namespace std;

class Queue{
    int front;
    int rear;
    s s1;
    s s2;
    public:
        Queue(){
            front=-1;
            rear=-1;
        }
        void push(int val){
            s1.push(val);
            rear;
        }
        void pop(){
            if(s1.empty() && s2.empty())
                return;
            int st=s1.size();
            while(!s1.empty())
            {
                s2.push(s1.top());
                //cout<<s2.top()<<endl;
                s1.pop();
            }
            s2.pop();
            rear--;
        }
        int peek(){
            if(s2.empty())
                return -1;
            return s2.top();

        }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    
    return 0;
}