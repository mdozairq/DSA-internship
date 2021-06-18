//Sort a linkedlist
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

node* MergeSortedList(node* lst1, node* lst2) 
{ 
	node* result = NULL; 

	// Base Cases
	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 

	// recursively merging two lists
	if (lst1->data <= lst2->data) { 
		result = lst1; 
		result->next = MergeSortedList(lst1->next, lst2); 
	} 
	else { 
		result = lst2; 
		result->next = MergeSortedList(lst1, lst2->next); 
	} 
	return result; 
} 

void SplitList(node* source, node** front, node** back) 
{ 
	node* ptr1; 
	node* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 


	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 

	*front = source; 
	*back = ptr2->next; 
	ptr2->next = NULL; 
} 


void MergeSort(node** thead) 
{ 
	node* head = *thead; 
	node* ptr1; 
	node* ptr2; 

  // Base Case
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	// Splitting list
	SplitList(head, &ptr1, &ptr2); 

	// Recursively sorting two lists.
	MergeSort(&ptr1); 
	MergeSort(&ptr2); 

	// Sorted List.
	*thead = MergeSortedList(ptr1, ptr2); 
} 

// Driver Program.
int main() 
{ 
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
    
	cout << "Unsorted Linked List: "; 
	display(head);  
	MergeSort(&head); 
	cout << "Sorted Linked List: "; 
	display(head); 

	return 0; 
} 