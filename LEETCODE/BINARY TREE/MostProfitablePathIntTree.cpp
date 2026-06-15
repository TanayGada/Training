/*
approach 1: 1 dfs + 1 bfs
bob have to reach root node and has only 1 path to do so (i.e. path of bob is fixed)
so we use dfs to get bob to root node
we store the time at which bob visits nodes in its path

Alice is at rootNode and needs to reach leafNode
there can be many paths
we use dfs to get the path which give maxEarnings
we check aliceTime and bobTime for reaching a node
if its same we divide by 2
*/
class Solution {

    vector<vector<int>> adjacentList;
    vector<bool> visited;
    map<int,int> bobPath;

    // The path taken by bob to reach node 0 and the times it takes to get there
    bool findBobPath(int sourceNode, int time){
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;

        if(sourceNode == 0) return true;

        for(int adjacentNode : adjacentList[sourceNode]){
            if(!visited[adjacentNode]){
                if(findBobPath(adjacentNode, time+1))   return true;
            }
        }
        bobPath.erase(sourceNode);
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(), maxIncome = INT_MIN;
        adjacentList.resize(n);
        visited.assign(n, false);

        for(int i=0; i<edges.size();i++){
            adjacentList[edges[i][0]].push_back(edges[i][1]);
            adjacentList[edges[i][1]].push_back(edges[i][0]);
        }

        findBobPath(bob,0);

        // BFS for alice 
        queue<vector<int>> nodeQueue;
        nodeQueue.push({0,0,0});
        visited.assign(n, false);
        while(!nodeQueue.empty()){
            int sourceNode = nodeQueue.front()[0];
            int time = nodeQueue.front()[1];
            int income = nodeQueue.front()[2];

            if((bobPath.find(sourceNode) == bobPath.end()) || time < bobPath[sourceNode]){
                income += amount[sourceNode];
            }

            else if(time == bobPath[sourceNode]){
                income += (amount[sourceNode]/2);
            }

            if((adjacentList[sourceNode].size() == 1) && (sourceNode != 0)){
                maxIncome = max(maxIncome, income);
            }

            for(int adjacentNode : adjacentList[sourceNode]){
                if(!visited[adjacentNode]){
                    nodeQueue.push({adjacentNode, time+1, income});
                }
            }

            visited[sourceNode] = true;
            nodeQueue.pop();
        }
        return maxIncome;
    }
};


