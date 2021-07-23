//Implementation of Circular LinkedList
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
    }
};
//inset at Head
void insertAtHead(node *&head, int val){
    node *n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
//insert Function
void insert(node * &head, int val){
    node *n=new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteAthead(node *&head){
    node *temp=head;
    while(temp!=head){
        temp=temp->next;
    }
    node *todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}
///deletion function
void deletion(node *&head, int pos){
    int count=1;
    if(pos==1){
        deleteAthead(head);
        return;
    }
    node *todelete;
    node *temp=head;
    while(count!=pos-1){
        count++;
        temp=temp->next;
    }
    todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node *head){
    node *temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<endl;
}
int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    deletion(head,4);
    display(head);
    //display(newNode);
    return 0;
}
