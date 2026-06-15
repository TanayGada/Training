/*
https://leetcode.com/problems/course-schedule-ii/

Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

We need to return a topologicalSort sequence as output 
if it is not possible, we return an empty array
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> inDegree(numCourses,0);
        vector<int> topoSort;
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses; i++){
            if(inDegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto i : adjList[node]){
                inDegree[i]--;
                if(inDegree[i]==0)  q.push(i);
            }
        }
        if(topoSort.size()==numCourses)
        return topoSort;
        return {};
    }
};