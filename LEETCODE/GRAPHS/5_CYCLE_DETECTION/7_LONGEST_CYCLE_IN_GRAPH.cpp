// revise this
// since atmost 1 outgoing edge is allowed, a node can be included in only 1 cycle

// 2 state coloring -> visited/not visited
// the moment, we get a node which is already visited in the current travesal, we check the current path for the length of cycle
// could use a map to store the instance where a particular node was visited to calculate the length of the cycle
class Solution {
public:
    void dfs(int node, vector<int>& marked, vector<int>& edges, int& maxSize, vector<int>& path){
        if(node==-1) return;
        if(marked[node]==1){
            int cnt = -1;
            for(int i=0; i<path.size(); i++)
                if(node == path[i]){
                    cnt = i;
                    break;
                }
            if(cnt==-1) return;
            maxSize = max(maxSize, (int)path.size()-cnt);
            return;
        }
        marked[node] = 1;
        path.push_back(node);
        dfs(edges[node], marked, edges, maxSize, path);
        return;
    }

    int longestCycle(vector<int>& edges) {
        int numNodes = edges.size();
        vector<int> marked(numNodes, 0);
        int maxSize = -1;
        for(int i=0; i<numNodes; i++){
            vector<int> path;
            if(marked[i]==0) dfs(i, marked, edges, maxSize, path);
        }
        return maxSize;
    }
};