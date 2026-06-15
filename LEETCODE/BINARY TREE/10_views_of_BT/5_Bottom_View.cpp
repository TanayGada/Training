//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// last node in each vertical order
// tc -> O(n), sc ->O(n) + O(n)
// level order(iteratiive) and not recursive
// for recursive, order is not fixed, need to keep track of height too

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        if(!root)   return {};
        map<int, int> mp;   //col, val
        queue<pair<Node*, int>> qt; // node, col
        qt.push({root, 0});
        while(!qt.empty()){
            auto temp = qt.front();
            qt.pop();
            Node* curr = temp.first;
            int col = temp.second;
            mp[col] = curr->data;
            if(curr->left)  qt.push({curr->left, col-1});
            if(curr->right)  qt.push({curr->right, col+1});
        }
        vector<int> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};