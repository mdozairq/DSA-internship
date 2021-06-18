//Reverse a linked list in the group of k
#include <bits/stdc++.h> 
using namespace std; 

class node { 
public: 
	int data; 
	node* next;
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

node* reverseK(node * &head, int k){
    node *prevPtr=NULL;
    node *currPtr=head;
    node *nextPtr;

    int count=0;
    while(currPtr!=NULL && count<k){
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
        count++;
    }
    if(nextPtr!=NULL){
    head->next=reverseK(nextPtr, k);
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
    cout<<"Enter the value of K : ";
    cin>>val;
    cout<<"Linked List reversed in group of K :"<<endl;
    node *revHead = reverseK(head,val);
    display(revHead);
    return 0;
}