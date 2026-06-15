// https://leetcode.com/problems/clone-graph/submissions/1949256775/

// dfs to clone graph including the neighbors and its neighbors
// graph here is given using adjacency list
// tc -> O(V*E), sc -> O(V)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(mp.count(node)){
            return mp[node];
        }
        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(Node* neighbor : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }   
};