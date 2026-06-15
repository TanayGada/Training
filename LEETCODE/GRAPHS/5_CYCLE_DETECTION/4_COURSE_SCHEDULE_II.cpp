// https://leetcode.com/problems/course-schedule-ii/submissions/1986927853/
// extension of Course Schedule 1
// add the last(leaf) node of a path in ans
// reverse it

// tc -> V + E, sc -> V+E
class Solution {
    bool cycle(int currCourse, int numCourses, vector<vector<int>>& adjList, vector<int>& marked, vector<int>& path){
        if(marked[currCourse]==1)   return true;
        if(marked[currCourse]==2)   return false;
        marked[currCourse] = 1;
        for(int dependentCourse : adjList[currCourse]){
            if(cycle(dependentCourse, numCourses, adjList, marked, path)){
                return true;
            }
        }
        marked[currCourse] = 2;
        path.push_back(currCourse);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(vector<int> pairing : prerequisites){
            adjList[pairing[1]].push_back(pairing[0]);
        }
        vector<int> path;
        vector<int> marked(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(marked[i]==0){
                if(cycle(i, numCourses, adjList, marked, path))    return {};
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};