// we can only increase value at each node, make sure all node sum equals the addition of their children
// intuition: while going down, increase the children values so we make sure to never fall short, 
// then all we have to do is sum both children and replace it in parent.
// if children sum is less than parent, make children equal to parent
// if children sum is greater than parent, make parent equal to children sum
// recursively go left and right. Traversal type: DFS.
// when coming back up the tree, take children sum and replace it in parent.
// tc -> O(n), sc -> O(n)

void childrenSum(TreeNode* root){
    if(!root)   return;
    int children = 0;
    if(root->left)  children += root->left->val;
    if(root->right)  children += root->right->val;
    
    if(children >= root->val)   root->val = children;
    else{
        if(root->left)  root->left->val = root->val;
        if(root->right)  root->right->val = root->val;
    }
    
    childrenSum(root->left);
    childrenSum(root->right);    
    
    if(root->left)  root->val = root->left->val;
    if(root->right)  root->val += root->right->val;
    
}