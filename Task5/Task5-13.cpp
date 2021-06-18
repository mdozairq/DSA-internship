//given a linked list arrange it in the below fashion
//	L0->Ln-1->L1->Ln-2->L2->Ln-3->null;
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
//count the LinkedList
int countNode(node *head){
    int c=0;
    while(head != NULL){
        c++;
        head=head->next;
    }
    return c;
}
//display function
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//reverse the list
node *reverseLinkedlist(node *head){
    node *nextPtr;
    node *currPtr = head;
    node *prevPtr = NULL;

    while(currPtr!=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr;
}
//merge the to list
node *mergeList(node *head1, node *head2,int i){
    node *result;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(i==1){
        result=head1;
        result->next=mergeList(head1->next,head2,0);
    }
    else{   
        result=head2;
        result->next=mergeList(head1,head2->next,1);
    }
    return result;
}
//to split the list and return
node *split(node *head){
    node *walker=head;
    node *runner=head->next;

    while(runner!=NULL){
        runner=runner->next;
        if(runner==NULL){
            break;
        }
        walker=walker->next;
        runner=runner->next;
    }

    node *halfList1=head;
    node *halfList2=walker->next;
    walker->next=NULL;
    node *revHalf = reverseLinkedlist(halfList2);
    node *newList=mergeList(halfList1,revHalf,1);
    return newList;

}


//main Function
int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    node *newNode=split(head);
    display(newNode);
    return 0;
}