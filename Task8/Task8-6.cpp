//Verical oreder traversal
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

void findMinMax(TreeNode *node, int *min, int *max, int hd)
{
    // Base case
    if (node == NULL) return;
  
    // Update min and max
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;
  
    // Recur for left and right subtrees
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}
  
// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void printVerticalLine(TreeNode *node, int line_no, int hd)
{
    // Base case
    if (node == NULL) return;
  
    // If this node is on the given line number
    if (hd == line_no)
        cout << node->data << " ";
  
    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}
  
// The main function that prints a given binary tree in
// vertical order
void verticalOrder(TreeNode *root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
  
    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << endl;
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
    
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
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
