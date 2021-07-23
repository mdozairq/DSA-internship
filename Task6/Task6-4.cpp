//Implementation of Doubly LinkedList
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

void deletion(node *&head, int pos){
    node *temp=head;
    int count=1;
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}

int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insertAtHead(head,7);
    display(head);
    int pos;
    cout<<"Enter the position of node you want to delete :";
    cin>>pos;
    deletion(head,pos);
    display(head);
    return 0;
}