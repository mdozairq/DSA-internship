//Sort Doubly Linkedlist
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};

void insertAtHead(node *&head, int val){
    node *n=new node(val);
    n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
}
void insert(node *&head, int val){
    node *n=new node(val);
    node *temp=head;
    if(head==NULL){
        n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node *head){
    node *temp=head;
    cout<<"NULL <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void sort(node *&head){
    node *currPtr=head;
    node *indexPtr;
    int temp;
    if(head==NULL){
        return;
    }
    while(currPtr->next!=NULL){
        indexPtr=currPtr->next;
        while(indexPtr!=NULL){
            if(currPtr->data>indexPtr->data){
                temp=currPtr->data;
                currPtr->data=indexPtr->data;
                indexPtr->data=temp;
            }
            indexPtr=indexPtr->next;
        }
        currPtr=currPtr->next;
    }

}

int main(){
    node *head=NULL;
    insert(head,3);
    insert(head,5);
    insert(head,1);
    insert(head,4);
    insert(head,2);
    insert(head,6);
    insertAtHead(head,7);
    cout<<"Unsorted Doubly Linked List : "<<endl;
    display(head);
    sort(head);
    cout<<"Sorted Doubly Linked List : "<<endl;
    display(head);
    return 0;
}