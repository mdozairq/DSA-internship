//Top view of the Binary Tree

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

void fillMap(TreeNode* root, int d, int l,
             map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;
 
    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }
 
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
 
// function should print the topView of
// the binary tree
void topView(struct TreeNode* root)
{
 
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    map<int, pair<int, int> > m;
 
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
 
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}
int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    //root->right->right=new TreeNode(7);
    root->right->left->right=new TreeNode(8);
    root->right->left->right->right=new TreeNode(9);
    
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topView(root);
    /*for(auto i:lorder)
        cout<<i<<" ";*/

    return 0;
}

/*
             1
           /  \
          2    3
         / \  / 
        4   5 6  
               \
                8
                 \
                  9
*/
