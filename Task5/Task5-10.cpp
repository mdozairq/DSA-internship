//Insert a specific node from a given linked list
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

void insertSpecific(node * &head, int inx, int val){
    node* n=new node(val);
    if(inx<1){
        cout<<"Invalid Index"<<endl;
        return;
    }
    if(inx==1){
        n->next=head;
        head=n;
        return;
    }
    else{
        int count=1;
        node *temp=head;
        while(temp->next!=NULL){
            count++;
            if(count==inx){
                node *temp1=temp->next;
                temp->next=n;
                n->next=temp1;
            }
            temp=temp->next;
        }
    }  
}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int val,ind;
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
            flag=0;
            break;
        }
    }
    display(head);
    cout<<"Enter the index where you want to insert specifically : ";
    cin>>ind;
    cout<<"Enter the value at that index : ";
    cin>>val;
    insertSpecific(head,ind,val);
    cout<<"Linked List after Insertion of node at specific index : "<<endl;
    display(head);
    return 0;
}
