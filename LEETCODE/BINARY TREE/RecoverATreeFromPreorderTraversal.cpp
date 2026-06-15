/*
https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22

We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
If a node has only one child, that child is guaranteed to be the left child.
Given the output traversal of this traversal, recover the tree and return its root.

Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

We maintain a stack and store <ele,depth>
we check treeDepth(from topOfStack) and inputEleDepth(from input)
if (treeDepth<inputEleDepth)    
    if(left==NULL)  left = inputEle
    else right = inputEle
else pop elements from stack
*/

class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> st;
            TreeNode* root = nullptr;
            int i = 0, n = traversal.size();
            while(i < n){
                int depth = 0;
                //calculate depth of current Ele from input string
                while(i<n && traversal[i]=='-'){
                    depth++;
                    i++;
                }

                //calculate ele from input string
                string ele = "";
                while(i<n && traversal[i]!='-'){
                    ele += traversal[i];
                    i++;
                }
                TreeNode* node = new TreeNode(stoi(ele));
                while(st.size()>depth) st.pop();
                
                if(!st.empty()){
                    TreeNode* topNode = st.top();
                    if(!topNode->left){
                        topNode->left = node;
                    }
                    else{
                        topNode->right = node;
                    }
                }
                st.push(node);
            }
            while(st.size()>1)  st.pop();
            return st.top();
        }
    };