//2. Right view of a Tree (gfg)

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

vector<int> levelOrderTraversal(TreeNode *root){
	vector<int>ans;
	if(root==NULL)
		return ans;
	queue<TreeNode *> q;
	q.push(root);
    //q.push(NULL);
	while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            TreeNode *temp=q.front();
            q.pop();
            if(i==n){
                ans.push_back(temp->data);
            }
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
	return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    //root->right->left=new TreeNode(6);
    //root->right->right=new TreeNode(7);
    vector<int> lorder=levelOrderTraversal(root);
    for(auto i:lorder)
        cout<<i<<" ";

    return 0;
}