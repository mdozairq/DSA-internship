//1. Detect cycle in a linked list.

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

void insert(node *&head, int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
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
void createCycle(node *&head, int pos){
    node *temp=head;
    node *cycleNode;
    int count=0;
    while(temp->next!=NULL){
        if(count==pos){
            cycleNode=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=cycleNode;
}

bool detectCycle(node *head){
    bool flag=false;
    node *walk=head;
    node *run=head;
    while(run!=NULL && run->next!=NULL){
        run=run->next;
        if(run==walk){
            flag=true;
            break;
        }
        walk=walk->next;
        run=run->next;
    }
    return flag;
}
void removeCycle(node *&head){
    node *walk=head;
    node *run=head;
    do{
        walk=walk->next;
        run=run->next->next;
    }while(walk!=run);
    int point;
    run=head;
    while(run->next!=walk->next){
        run=run->next;
        walk=walk->next;
    }

    point=run->data;
    cout<<"Point at which Cycle Starts :"<<point<<endl;
    walk->next=NULL;
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
    createCycle(head,3);
    if(detectCycle(head)==true){
        cout<<"The given List is Cyclic"<<endl;
    }
    else{
        cout<<"The given List is not Cyclic"<<endl;
    }
    removeCycle(head);
    display(head);
    if(detectCycle(head)==true){
        cout<<"The given List is Cyclic"<<endl;
    }
    else{
        cout<<"The given List is not Cyclic"<<endl;
    }
    return 0;
}
