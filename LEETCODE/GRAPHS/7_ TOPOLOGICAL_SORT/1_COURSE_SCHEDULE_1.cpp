/*
https://leetcode.com/problems/course-schedule/description/

Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

We have been given prerequisites, so we can construct a adjList and then try to generate a topologicalSort sequence
if we are able to generate a topologicalSort sequence, we can conclude that courses can be scheduled
Or else we can also determine if its not possible then there should be a cycle or its should be a undirected graph

tc => O(V + E)
sc => O(V) +  O(V + E)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        int cnt = 0;
        queue<int> q;
        for(int i=0;i<numCourses; i++){
            if(inDegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto i : adjList[node]){
                inDegree[i]--;
                if(inDegree[i]==0)  q.push(i);
            }
        }
        if(cnt<numCourses)  return 0;
        return 1;
    }
};