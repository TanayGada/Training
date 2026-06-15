// https://neetcode.io/problems/count-connected-components/solution

// we construct a DSU
// for all nodes in a connected component, ultParent is same
// if there are x connected components, there will be n vertices which have parent equal to themselves

// tc -> O(V + E*alpha(V)), sc -> O(V)
class Solution {
public:
    class DSU{
    public:
        vector<int> rank, size, parent;
        DSU(int n){
            rank.resize(n, 0);
            size.resize(n, 1);
            parent.resize(n);
            for(int i=0; i<n; i++) parent[i] = i;
        }

        int findUltimateParent(int n){
            if(parent[n]==n)    return n;
            return parent[n] = findUltimateParent(parent[n]);
        }

        void unionByRank(int u, int v){
            int ultParU = findUltimateParent(u);
            int ultParV = findUltimateParent(v);
            if(ultParU == ultParV)  return;
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
        }

        void unionBySize(int u, int v){
            int ultParU = findUltimateParent(u);
            int ultParV = findUltimateParent(v);
            if(ultParU == ultParV)  return;
            if(size[ultParU] < size[ultParV]){
                parent[ultParU] = ultParV;
                size[ultParV] += size[ultParU];
            }
            else{
                parent[ultParV] = ultParU;
                size[ultParU] += size[ultParV];
            }
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n+1);
        for(vector<int> edge : edges)   dsu.unionBySize(edge[0], edge[1]);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(dsu.parent[i]==i)    cnt++;
        }
        return cnt;
    }
};
