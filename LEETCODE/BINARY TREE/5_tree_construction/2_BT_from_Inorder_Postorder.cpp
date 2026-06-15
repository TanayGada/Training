// in -> left root right
// post -> left right root
// make a root with last ele of post
// find the length of left and right subtree from in, split post into left and right
// tc -> O(n), sc -> O(n)
class Solution {
public:
    TreeNode* getTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& in){
        if(inStart>inEnd || postStart>postEnd)   return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int eleInLeft = in[postorder[postEnd]]-inStart;
        int eleInRight = inEnd - in[postorder[postEnd]];
        root->left = getTree(inorder, inStart, in[postorder[postEnd]]-1, postorder, postStart, postStart+eleInLeft-1, in);
        root->right = getTree(inorder, in[postorder[postEnd]]+1, inEnd, postorder, postStart+eleInLeft ,postEnd-1, in);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> in;
        for(int i=0; i<inorder.size(); i++) in[inorder[i]] = i;
        int inStart = 0, inEnd = inorder.size()-1;
        int postStart = 0, postEnd = postorder.size()-1;
        TreeNode* root = getTree(inorder, inStart, inEnd, postorder, postStart, postEnd, in);
        return root;
    }
};