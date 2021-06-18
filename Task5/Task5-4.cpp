//Intersection of linked list

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};
void insert(node * &head, int val){
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

int countNode(node *head){
    int c=0;
    while(head != NULL){
        c++;
        head=head->next;
    }
    return c;
}
 
int insectionPoint(node *head1, node *head2){
    int l1 = countNode(head1);
    int l2 = countNode(head2);
    node *temp1 = head1;
    node *temp2 = head2;

    if(l1>l2){
        for(int i=0;i<l1-l2;i++){
            temp1 = temp1->next;
            }
    }
    if(l2>l1){
    for(int i=0;i<l2-l1;i++){
        temp2 = temp2->next;
        }
    }

    while(temp1!=NULL and temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

void display(node *head){
    node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    node *newNode;
    insert(head1, 0);
    insert(head1, 1);
    insert(head2, 2);
    insert(head1, 3);
    insert(head2, 4);
    head2->next->next=head1;
    insert(head1, 5);
    insert(head1, 11);
    insert(head1, 6);
    insert(head1, 7);
    insert(head1, 8);
    insert(head1, 9);

    display(head2);
    display(head1);

    cout<<"Point of Intersection : "<<insectionPoint(head1,head2);

    return 0;

}