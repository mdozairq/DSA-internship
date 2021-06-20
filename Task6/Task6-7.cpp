//
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
//insert Function
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
//to return require new node
node *nodeSum(node *head1, node *head2){
    node *sumNode=NULL;
    node *temp1=head1;
    node *temp2=head2;
    long long int sum,carry=0;
    while(temp1!=NULL && temp2!=NULL){
        cout<<temp1->data<<" + "<<temp2->data<<" = ";
        if(temp1==NULL)
            sum=temp2->data+carry;
        else if(head2==NULL)
            sum=temp1->data+carry;
        else
            sum=temp1->data+temp2->data+carry;
        if(sum>=10){
            sum=sum-10;
            carry=1;
        }
        else
            carry=0;
        cout<<sum<<endl;
        insert(sumNode,sum);
        if(temp1!=NULL)
        temp1=temp1->next;
        if(temp2!=NULL)
        temp2=temp2->next;
    }
    return sumNode;
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
    node *head1=NULL;
    node *head2=NULL;
    insert(head1,2);
    insert(head1,4);
    insert(head1,3);
    insert(head1,9);
    insert(head1,9);
    insert(head1,9);
    insert(head1,9);
    insert(head2,5);
    insert(head2,6);
    insert(head2,4);
    insert(head2,9);
    display(head1);
    display(head2);
    node *sN=nodeSum(head1,head2);
    display(sN);
    return 0;
}