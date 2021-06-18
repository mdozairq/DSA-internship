//merge linkedlist alternatively
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
node *mergeRecursive(node *head1, node *head2,int i){
    node *mergedList;
    if(head1==NULL)
    {
       return head2;
    }
    if(head2==NULL){
        return head1;
    }
    ;
    if(i==1){
        mergedList=head1;
        mergedList->next=mergeRecursive(head1->next,head2,0);
    }
    else{   
        mergedList=head2;
        mergedList->next=mergeRecursive(head1,head2->next,1);
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
    node *newNode=mergeRecursive(head1,head2,1);
    display(newNode);
    return 0;
}
