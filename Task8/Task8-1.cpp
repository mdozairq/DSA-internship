//5. Boundary traversal of a Tree (gfg)
//6. Diagnoal traversal of a tree (gfg)
//7. Convert binary tree to doubly linked list (leetcode as well as gfg)
//8. check if root to leaf path exists for a given sum it will return true and false leetcode	sum = 1

#include<bits/stdc++.h>
using namespace std;

class BTnode{
    public:
        int data;
        BTnode *left;
        BTnode *right;    
        BTnode(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};
void insert(BTnode *&root, int val){
    BTnode *n=new BTnode(val);
    if(root==NULL){
        root=n;
        return;
    }
    if(root->data<val){
		return insert(root->right, val);
	}
	else if(root->data==val){
		return;
	}
    else{
		return insert(root->left, val);
	}
}

void preOrderHelper(BTnode *root, vector<int>& ans){
	if(root==NULL)
		return;
	ans.push_back(root->data);
	preOrderHelper(root->left, ans);
	preOrderHelper(root->right, ans);
}

vector<int> preOrder(BTnode *root){
	vector<int>ans;
	preOrderHelper(root,ans);
	return ans;
}


void inOrderHelper(BTnode *root, vector<int>& ans){
	if(root==NULL)
		return;
	inOrderHelper(root->left, ans);
	ans.push_back(root->data);
	inOrderHelper(root->right, ans);
}

vector<int> inOrder(BTnode *root){
	vector<int>ans;
	inOrderHelper(root,ans);
	return ans;
}

void postOrderHelper(BTnode *root, vector<int>& ans){
	if(root==NULL)
		return;
	postOrderHelper(root->left, ans);
	postOrderHelper(root->right, ans);
	ans.push_back(root->data);
}

vector<int> postOrder(BTnode *root){
	vector<int>ans;
	postOrderHelper(root,ans);
	return ans;
}

vector<int> levelOrderTraversal(BTnode *root){
	vector<int>ans;
	if(root==NULL)
		return ans;
	queue<BTnode *> q;
	q.push(root);
    q.push(NULL);
	while(!q.empty()){
        BTnode *temp=q.front();
        q.pop();
        if(temp!=NULL){
            ans.push_back(temp->data);
            if(temp->left!=NULL)
                q.push(temp->left);
            else{
            //if(temp->right!=NULL)
                q.push(temp->right);}
        }
        else if(!q.empty())
                q.push(NULL);
	}
	return ans;
}


int main(){
    int val;
    cin>>val;
    BTnode *root=NULL;
    insert(root,10);
    insert(root,8);
    insert(root,11);
    insert(root, 2);
    insert(root, 5);
    insert(root, 3);
    vector<int> inO=levelOrderTraversal(root);
    for(auto i:inO)
        cout<<i<<" ";
    return 0;
}