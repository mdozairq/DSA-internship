// Reverse the linked list
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int val){
            data=val;
            next=NULL;
        }
};

void insert(node * &head, int val){
    node *n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node *reverseLinkedlist(node *head){
    node *nextPtr;
    node *currPtr = head;
    node *prevPtr = NULL;

    while(currPtr!=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr;
}
int main(){
    int val;
    node *head=NULL;
    bool flag=1,p;
    while(flag){
        cout<<"Press 1 to insert a Node else Press 0 :";
        cin>>p;
        if(p==1){
            cout<<"Enter the value in Node :";
            cin>>val;
            insert(head, val); 
        }
        else{
            break;
        }
    }
    display(head);
    cout<<"Reversed Linked List :"<<endl;
    node *revHead = reverseLinkedlist(head);
    display(revHead);
    return 0;
}