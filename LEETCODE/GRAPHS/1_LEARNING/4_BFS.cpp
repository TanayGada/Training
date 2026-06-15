/*
There are two types of traversal techniques
1. BFS (Breath First Search)
2. DFS (Depth First Search)

In breath first search we traverse all elements at a particular level then we go to next level 
In short, we start from a node and get all its neighbor, as all neighbors are at distance 1 from the startNode
Then we repeat the same process for all its neighbors

We use a 
Queue DS (to store neighbors), 
an AdjacencyList (to get neighbors of a vertex), 
a visitedArray to mark elements which are already visited
an ansVector (to store BFS traversal)

*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> que;
        que.push(0);
        vector<int> ans;
        vector<bool> isVisited(V,false);
        isVisited[0] = true;
        ans.push_back(0);
        while(!que.empty()){
            int j = 0;
            int i = que.front();
            que.pop();
            while(j<adj[i].size()){
                int neighbor = adj[i][j];
                if(!isVisited[neighbor]){
                    ans.push_back(neighbor);
                    que.push(neighbor);    
                    isVisited[neighbor] = true;
                }
                j++;
            }
        }
        return ans;
    }
};