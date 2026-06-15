// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/1840043106/ 
// place 1st element of pre as root, then split the pre and in for left and right subtree 
// in -> left root right
// in -> for an element, all elements to left are in leftsubtree and all element to right are in right subtree
// we get the no of elements in left and right subtree
// pre -> root left right
// pre -> we get left and right subtree elements
// tc -> O(n) and sc -> O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& in){
        if(preStart > preEnd || inStart > inEnd)    return NULL;

        int rootNode = preorder[preStart];
        TreeNode* root = new TreeNode(rootNode);
        int eleInLeftSubtree = in[rootNode]-inStart;
        int eleInRightSubtree = inEnd-in[rootNode];
        root->left = buildTree(preorder, preStart+1, preStart+eleInLeftSubtree, inorder, inStart, in[rootNode]-1, in);
        root->right = buildTree(preorder, preStart+eleInLeftSubtree+1, preEnd, inorder, in[rootNode]+1, inEnd, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> in;
        for(int i=0; i<inorder.size(); i++)    in[inorder[i]] = i;
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = preorder.size()-1;
        TreeNode* root = buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd, in);
        return root;
    }
};