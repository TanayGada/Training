// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// top view is first element of each column in vertical order traversal
// tc -> O(N), sc ->O(n) + O(n)
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(!root)   return {};
        map<int, int> mp; //col, val
        queue<pair<Node*, int>> q; //val, col
        q.push({root,0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int col = temp.second;
            if(mp[col]==0)  mp[col]= temp.first->data;
            
            if(temp.first->left)  q.push({temp.first->left, col-1});
            if(temp.first->right)  q.push({temp.first->right, col+1});
        }
        vector<int> ans;
        for(auto i : mp)    ans.push_back(i.second);
        return ans;
    }
};