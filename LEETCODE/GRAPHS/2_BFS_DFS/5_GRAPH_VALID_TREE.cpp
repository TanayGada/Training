// https://neetcode.io/problems/valid-tree/history?submissionIndex=0
// for a tree
// 1. there should be no cycle
// 2. there shoudl be only 1 connected component
// while detecting cycle, we can have visited array, even if 1 node is not visited at the end, means there is more than 1 components



// tc -> O(V+E) + O(V)
// sc -> O(V) + O(V)
class Solution {
public:
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adjList){
        visited[node] = true;
        for(int neighbor : adjList[node]){
            if(neighbor!=parent){
                if(visited[neighbor])    return true;
                else dfs(neighbor, node, visited, adjList);
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n);
        if(dfs(0, -1, visited, adjList)){
            return false;
        }
        for(int i=0; i<n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
