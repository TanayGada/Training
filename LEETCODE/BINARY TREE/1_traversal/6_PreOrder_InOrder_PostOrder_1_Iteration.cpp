
// tc -> O(3n), sc -> O(4n)
class Solution {
public:
    vector<vector<int>> preInPostTraversal(TreeNode* root) {
        if(!root)  return {};
        vector<int> preOrder, inOrder, postOrder;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while (!st.empty()){
            auto it = st.top();
            st.pop();
            if (it.second == 1) {
                preOrder.push_back(it.first->data);
                it.second++;
                st.push(it); 
                if(it.first->left)  st.push({it.first->left, 1});
            }
            else if (it.second == 2) {
                inOrder.push_back(it.first->data);
                it.second++;
                st.push(it); 
                if(it.first->right)    st.push({it.first->right, 1});
            }
            else    postOrder.push_back(it.first->data);
        }
        vector<vector<int>> result;
        result.push_back(preOrder);
        result.push_back(inOrder);
        result.push_back(postOrder);
        return result;
    }
};
