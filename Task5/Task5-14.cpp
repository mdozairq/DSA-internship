//merge two sorted linked list
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

node *mergeSorted(node *head1, node *head2){
    node *head3=new node(-1);
    node *ptr1=head1;
    node *ptr2=head2;
    node *ptr3=head3;

    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }

    return head3->next;
}

node *mergeRecursive(node *head1, node *head2){
    node *mergedList;
    if(head1==NULL)
    {
       return head2;
    }
    if(head2==NULL){
        return head1;
    }
        if(head1->data<head2->data){
            mergedList=head1;
            mergedList->next=mergeRecursive(head1->next,head2);
        }
        else{
            mergedList=head2;
            mergedList->next=mergeRecursive(head1,head2->next);
        }
        return mergedList;
}

int main(){
    node *head1=NULL;
    node *head2=NULL;
    insert(head1,1);
    insert(head1,4);
    insert(head1,5);
    insert(head1,7);
    insert(head2,2);
    insert(head2,3);
    insert(head2,6);
    display(head1);
    display(head2);
    node *newNode=mergeRecursive(head1,head2);
    display(newNode);
    return 0;
}
