// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// divide problem as left boundary, leaf nodes, right boundary
void leftSideDFS(Node* curr, vector<int>& traversal){
    while(curr){
        if(!curr->right && !curr->left) return;
        traversal.push_back(curr->data);
        if(curr->left)  curr = curr->left;
        else curr = curr->right;
    }
}

void rightSideDFS(Node* curr, vector<int>& traversal){
    if(!curr)   return;
    rightSideDFS(curr->right, traversal);
    if(!curr->right)    rightSideDFS(curr->left, traversal);
    if(curr->right || curr->left) traversal.push_back(curr->data);
}

void bottomDFS(Node* curr, vector<int>& traversal){
    if(!curr)   return;
    if(!curr->right && !curr->left) traversal.push_back(curr->data);
    bottomDFS(curr->left, traversal);
    bottomDFS(curr->right, traversal);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root)   return {};
        vector<int> traversal = {root->data};
        leftSideDFS(root->left, traversal);
        if(root->right || root->left)   bottomDFS(root, traversal);
        rightSideDFS(root->right, traversal);
        return traversal;
    }
};