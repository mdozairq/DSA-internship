//Implementation of Queue using Linked List

#include<bits/stdc++.h>
using namespace std;

//Defining the class node
class Node{
    public:
        int data;
        Node *next;
        //Constructor for Node
        Node(int val){
            data=val;
            next=NULL;
        }
};

//Defining the class Queue
class Queue{
    Node *front;
    Node *rear;
    public:
        //Constructor for Queue
        Queue(){
            front=NULL;
            rear=NULL;
        }
        //to check the Queue is empty or not
        bool isEmpty(){
            if(front==NULL){
                return true;
            }
            return false;
        }
        //to Insert element in the Queue
        void enQueue(int val){
            Node *n=new Node(val);
            if(isEmpty()){
                front=n;
                rear=n;
                return;
            }
            rear->next=n;
            rear=n;
        }
        //to Delete an element from the Queue
        void deQueue(){
            if(isEmpty()){
                cout<<"Queue is Underflow";
            }
            Node *todelete=front;
            cout<<"Deleted Element : "<<todelete->data;
            front=front->next;
            delete todelete;
        }
        //to get the element in the front
        int peek(){
            if(isEmpty()){
                cout<<"No element in the Queue";
                return -1;
            }
            cout<<front->data<<endl;
        }
};
//Main Function
int main(){
    Queue q;//creating object
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.peek();
    q.deQueue();
    q.peek();
    q.deQueue();
    q.peek();
    return 0;
}

/*
Time Complexiety : O(1) for enQueue and deQueue both as there is no loop used.
Space Complexiety : O(1)
*/