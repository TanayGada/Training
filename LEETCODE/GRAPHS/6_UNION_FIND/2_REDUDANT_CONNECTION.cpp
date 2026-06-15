// https://leetcode.com/problems/redundant-connection/editorial/
// graph is dynamic, hence DSU idea
// DFS Approach: for each new edge, check if vertices are already connected, means new edge creates a cycle
// tc -> O(N*N), sc -> O(N)
// DSU Approach: for any new edge, if ultimateParent are equal, means this edge forms a cycle
// tc -> O(N*4*alpha), sc -> O(N)
class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node])    return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    bool unionByRank(int u, int v){
        int ultParU = findUltimateParent(u);
        int ultParV = findUltimateParent(v);
        if(ultParU == ultParV)  return true;
        if(rank[ultParU] < rank[ultParV]){
            parent[ultParU] = ultParV;
        }
        else if(rank[ultParU] > rank[ultParV]){
            parent[ultParV] = ultParU;
        }
        else{
            parent[ultParV] = ultParU;
            rank[ultParU]++;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(vector<int>& edge : edges){
            if(dsu.unionByRank(edge[0], edge[1]))    return {edge[0], edge[1]};
        }
        return {-1, -1};
    }
};

        // 1   
        // 5   3
        //     4