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
- dfs

What does Topological Sort using dfs states?
- it gives us one of the sequence where u is before v
- we run a loop from 0 to V and run dfs for nodes not visited
- While dfs, if there is no further call available i.e no adjNode left to visit, we add node onto stack
- At the end, we pop out all elements from stack which gets us one of the sequence

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
	void dfs(int node, vector<bool>& visited, vector<int> adj[], stack<int>& st){
	    visited[node] = true;
	    for(auto a : adj[node]){
	        if(!visited[a])
	            dfs(a, visited, adj, st);
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<bool> visited(V,false);
	    vector<int> topo;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i, visited, adj, st);
	        }
	    }
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};
