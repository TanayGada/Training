// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1840134519/
// pre -> root left right
// post-> left right root
// pre  -> 1,2,4,5,3,6,7
// post -> 4,5,2,6,7,3,1
// firstEle in pre & lastELe in post is the root(here 1)
// ele next to root in pre, is the root of the left subtree(here 2)
// all eles in post before the left subtree root are part of leftSubtree(here 4 5 2)


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& post){
        if(preStart > preEnd || postStart > postEnd)   return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd)    return root;
        int eleInLeft = post[preorder[preStart+1]]+1-postStart;
        int eleInRight = postEnd-postStart-eleInLeft+1;

        root -> left = buildTree(preorder, preStart+1, preStart+eleInLeft, postorder, postStart, postStart+eleInLeft, post);
        root -> right = buildTree(preorder, preStart+eleInLeft+1, preEnd, postorder, postStart+eleInLeft, postEnd-1 , post);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int> post;
        for(int i=0;i<postorder.size();i++) post[postorder[i]] = i;
        int preStart = 0, preEnd = preorder.size()-1;
        int postStart = 0, postEnd = postorder.size()-1;
        TreeNode* root = buildTree(preorder, preStart, preEnd, postorder, postStart, postEnd, post);
        return root;
    }  
};