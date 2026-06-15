/*
DETECT A CYCLE IN DIRECTED GRAPH

We need to maintain a visited array to keep track of nodes visited on a particular path
We also need to maintain a visited array to keep track of nodes visited overall so that we dont apply a search algo on those
We can easily maintain a visitedArray for nodes in a particular path using recursion in dfs

On a same path, If a node is being visited again, then we say a cycle exits
tc => O(V + E)
sc => O(V + V)
*/

class Solution{
    bool dfs(int node, vector<bool>& visited, vector<bool>& pathVisited, vector<int> adjList[]){
        visited[node] = true;
        pathVisited[node] = true;
        for(auto adj : adjList[node]){
            if(pathVisited[adj])  return true;
            if(!visited[node]){
                if(dfs(adj, visited, pathVisited, adjList)) return true;
                
            }
        }
        pathVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adjList[]){
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, visited, pathVisited, adjList)){
                    return true;
                }
            }
        }
        return false;
    }
};