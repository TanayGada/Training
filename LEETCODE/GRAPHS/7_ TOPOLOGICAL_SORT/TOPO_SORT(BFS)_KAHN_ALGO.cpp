/*
What is Topological Sort?
- it only exts on DAG (directed acyclic graph)
- Linear ordering of vertices such that, if there is an edge between u & v,
  u appears before v in that ordering
eg. 5 -> 0, 4 -> 0, 5 -> 2, 2 -> 3, 3 -> 1, 4 -> 1
there can be many such sequences such that u appears before v, 
5 4 2 3 1 0
5 2 4 3 1 0
4 5 2 3 1 0
We need only 1 such sequence

Why only Directed Acyclic Graph?
- if graph is undirected => 1 -> 2, 2 -> 1
  so there cant be a sequence where u is before v
- if graph has cycle => 1 -> 2, 2 -> 3, 3 -> 1
  there cant be a sequence such that u is before v

How will we implement it?
- bfs
- also known as kahn algorithm

What does Topological Sort using bfs states?
- We use a queue, inDegree array, finalSequence 
- Insert all node having inDegree 0 into queue
- while queue is not empty
    we remove topNode from queue
    we reduce the inDegree of adjNodes of Node
    if inDegree==0, we push that adjNode into finalSequence

tc => O(V + E)
sc => O(V + V + V) => queue, inDegree array, finalSequence 
*/

/*
https://www.geeksforgeeks.org/problems/topological-sort/1

Topological sort
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto aN : adj[i]){
	            inDegree[aN]++;
	        }
	    }
	    vector<int> topoSortSequence;
	    queue<int> q;
	    for(int i=0;i<V; i++){
	        if(inDegree[i]==0)  q.push(i);
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topoSortSequence.push_back(node);
	        for(auto adjNode : adj[node]){
	            inDegree[adjNode]--;
	            if(inDegree[adjNode]==0)    q.push(adjNode);
	        }
	    }
	    return topoSortSequence;
	}
};