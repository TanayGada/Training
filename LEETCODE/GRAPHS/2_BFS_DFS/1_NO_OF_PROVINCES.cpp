/*
https://leetcode.com/problems/number-of-provinces/

Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.


we need to find number of connected components or number of completely isolated components
we run bfs/dfs for each node, and mark nodes which are visited by BFS/DFS
The number of times, the bfs/dfs have been run uniquely is the number of provinces
*/


// n is number of cities, we are given adjancecy matrix representation

// bfs
// tc => O(n * n) -> for all n nodes, check all possible n neighbors
// sc => O(n) + O(n) => n for queue, n for visited
class Solution {
public:
    void bfs(int node, vector<bool>& visited,vector<vector<int>>& isConnected){
        queue<int> qt;
        qt.push(node);
        visited[node]=true;
        while(!qt.empty()){
            int ele = qt.front();
            qt.pop();
            for(int i=0; i<isConnected.size(); i++){
                if(isConnected[node][i] && !visited[i])
                {
                    qt.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt=0;
        vector<bool> visited(n+1, false);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                cnt++;
                bfs(i, visited, isConnected);
            }
        }
        return cnt;
    }
};

// dfs
// tc -> n * n -> for each node, we check other n neighbors
// sc -> n * n -> visited array and stack space
class Solution {
public:

    void dfs(int node, vector<int>& visited, vector<vector<int>>& isConnected){
        visited[node] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int no_of_provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                no_of_provinces++;
                dfs(i, visited, isConnected);
            }
        }    
        return no_of_provinces;
    }
};


// union find
