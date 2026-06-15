/*
https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


DFS
In depth first search we traverse through whole depth of a particular element, then does the same for other elements if they haven't been visited
We use recursion to go to the depth of the tree and then return

We use 
an AdjacencyList (to get neighbors of a vertex), 
a visitedArray to mark elements which are already visited
an ansVector (to store BFS traversal)
Recursion to traverse through the depth of the tree

*/

class Solution {
  public:
    void dfs(vector<int> adj[], int start, vector<int>& ans, vector<bool> &isVisited){
        isVisited[start] = true;
        ans.push_back(start);
        for(auto adjNode : adj[start]){
            if(!isVisited[adjNode]){
                dfs(adj, adjNode, ans, isVisited);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> isVisited(V, false);
        int start = 0;
        vector<int> ans;
        dfs(adj, start, ans, isVisited);
        return ans;
    }
};