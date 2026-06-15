/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Directed Graph Cycle
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

We can use kahn algorithm for the above
As we know Kahn Algo is used for only Directed Acyclic Graphs
hence if we get all elements in topologicalSortSequence at the end, we say that cycle does not exits
To further optimize the code, we can maintain a count of elements included in the sequence instead of maintaining the sequence itself
If the cnt < V, we say there is a cycle

sc => O(V) + O(V) => inDegree, queue
tc => O(V + E)
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto adjNode : adj[i]){
                inDegree[adjNode]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0)  q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto adjNode : adj[node]){
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0)    q.push(adjNode);
            }
        }
        if(cnt<V)   return true;
        return false;
    }
};