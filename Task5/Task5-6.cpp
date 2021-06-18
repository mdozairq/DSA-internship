//check whether the given linked list is palindrome or not.

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

void checkPalindrome(node *head){
    stack<int> s;
    bool flag=true;
    node *temp=head;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }

    while(head!=NULL){
        int ele=s.top();
        s.pop();
        //cout<<"top:"<<ele<<"   node:"<<temp->data<<endl;
        if(ele != head->data){
            flag=false;
            break;
        }
        head = head->next;
    }

    if(flag == true){
        cout<<"The Given Linkedlist is Palindrome "<<endl;
    }
    else{
        cout<<"The Given Linkedlist is Not Palindrome "<<endl;
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
    checkPalindrome(head);
    return 0;
}
