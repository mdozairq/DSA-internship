//implementation of Queue using linked list
#include<bits/stdc++.h>
using namespace std;

//defining a node
class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            data=val;
            next=NULL;
        }
};

//Defining a Queue
class Queue{
    Node *front;
    Node *rear;
    public:
        //constructor
        Queue(){
            front=NULL;
            rear=NULL;
        }
        //to check queue is empty or not
        bool isEmpty(){
            if(front==NULL)
                return true;
            return false;
        }
        //Inserting a element in the Queue
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
        //deleting a node from the queue
        void deQueue(){
            if(isEmpty()){
                cout<<"Queue is underflow";
                return;
            }
            Node *del=front;
            cout<<"Element deleted from the Queue : "<<del->data;
            front=front->next;
            delete del;
        }
        //to get the value at front
        int peek(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return -1;
            }
            return front->data;
        }
};