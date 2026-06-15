/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

Undirected Graph Cycle
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

main idea here is to check if a node is already being visited through another node - if yes then cycle is present
we traverse the nodes by dfs

If a adjacentNode is visited and the adjacentNode is not parent of that node, we say a loop exists
adjList has 2 types of nodes - node which is its parent, node which it can traverse
if the node which it can traverse is already visited, then there is a cycle

summation of adjNodes ==summation of degree == 2E (undirected graph) == E(directed graph)
tc => O(n + 2e) + O(n)
sc => O(n) + O(n)
*/

class Solution {
    bool dfs(int node, int parent, vector<bool>& isVisited, vector<int> adj[]){
        isVisited[node] = true;
        for(int adjNode : adj[node]){
            if(!isVisited[adjNode]){
                if(dfs(adjNode, node, isVisited, adj))    return true;
            }
            else{
                if(adjNode != parent)   return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> isVisited(V, false);
        for(int i=0;i<V;i++){
            if(!isVisited[i] && dfs(i,-1,isVisited, adj))  return true;
        }
        return false;
    }
};