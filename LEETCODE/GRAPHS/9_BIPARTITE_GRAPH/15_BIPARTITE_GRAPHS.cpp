/*
https://leetcode.com/problems/is-graph-bipartite/description/

Is Graph Bipartite?
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
Return true if and only if it is bipartite.

What is a bipartite graph?
Given a graph we need to color the graph with 2 colors such that no two adjacent nodes have the same color
even length cycle => bipartite graph
odd length cycle => not a bipartite graph 
linear graphs are always bipartite
I color a node with 0 and color all its adjNodes with 1
I color a node with 1 and color all its adjNodes with 0
If at any point, we get the node and adjacent of same color, we say it is not a bipartite graph

sc => O(V + V) => color & stack/queue
tc => O(V + 2E)
*/
class Solution {

private:
    bool possibleBFS(int start, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                if(color[graph[node][i]]==color[node])  return false;
                if(color[graph[node][i]]==-1){
                    q.push(graph[node][i]);
                    color[graph[node][i]] = !color[node];
                }
            }
        }
        return true;
    }

    bool possibleDFS(int node, vector<vector<int>>& graph, vector<int>& color){
        for(auto adj : graph[node]){
            if(color[adj]==color[node]) return false;
            if(color[adj]==-1){
                color[adj] = !color[node];
                if(!possibleDFS(adj, graph, color)) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i] = 0;
                // if(!possibleBFS(i, graph, color))  return false;
                if(!possibleDFS(i, graph, color))  return false;
            }
        }
        return true;
    }
};