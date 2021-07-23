//4. Bottom view of a Tree (gfg)

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
void bottomView(TreeNode *root)
{
    if (root == NULL)
        return;
 
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
 
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;
 
    // Queue to store tree nodes in level
    // order traversal
    queue<TreeNode *> q;
 
    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item
 
    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item
 
        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;
 
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;
 
        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
 
        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
 
    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
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
    //topView(root);
    /*for(auto i:lorder)
        cout<<i<<" ";*/

    return 0;
}
