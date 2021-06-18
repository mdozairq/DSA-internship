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

node* deletion(node *head, int val){
    node *temp=head;
    if(head==NULL){
        return NULL;
    }

    if(temp->next == NULL || temp->data==val){
        node* todelete=temp;
        head=head->next;
        delete todelete;
        return head;
    }

    while (temp->next->data != val)
    {
        temp=temp->next;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
    return head;
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
            flag=0;
        }
    }
    display(head);
    cout<<"Enter the node you want to delete : ";
    cin>>val;
    head=deletion(head, val);
    cout<<"Linked list after Deletion of specific node: ";
    display(head);

    return 0;
}