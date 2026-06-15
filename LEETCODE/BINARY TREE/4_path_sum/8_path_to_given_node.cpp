// https://www.interviewbit.com/problems/path-to-given-node/
// if node is found, no nothing further
// tc -> O(n), sc -> O(n)

bool getPath(TreeNode* root, int B, vector<int>& path){
    if(!root)   return false;
    path.push_back(root->val);
    if(root->val==B)    return true;
    if(getPath(root->left, B, path) || getPath(root->right, B, path))   return true;
    path.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    getPath(A, B, path);
    return path;
}