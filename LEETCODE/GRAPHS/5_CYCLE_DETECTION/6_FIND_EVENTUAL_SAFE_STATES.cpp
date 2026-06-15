// link: https://leetcode.com/problems/find-eventual-safe-states/submissions/1987484067/

// similar to course schedule 2
// identify nodes not forming a cycle -> dfs 0 - not visited,1 - visiting,2 - visited coloring

// tc -> O(v+e), sc -> O(v)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &marked, vector<int>& safeNodes){
        if(marked[node]==2) return false;
        if(marked[node]==1) return true;
        marked[node] = 1;
        for(int neighbor : graph[node]){
            if(dfs(neighbor, graph, marked, safeNodes)){
                return true;
            }
        }
        marked[node] = 2;
        safeNodes.push_back(node);
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> marked (graph.size()+1, 0);
        vector<int> safeNodes;
        for(int i=0; i<graph.size(); i++){
            if(marked[i]==0){
                dfs(i, graph, marked, safeNodes);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};