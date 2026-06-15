// https://leetcode.com/problems/course-schedule/
// goal -> detect cycles -> deadlock -> courses cannot be scheduled
// approach 
// 0 -> not visited
// 1 -> current path
// 2 -> visited
// if 2 -> ignore
// while traversing if 1 -> cycle detected

// tc -> V + E, sc -> V+E
class Solution {
    bool cycle(int currCourse, int numCourses, vector<vector<int>>& adjList, vector<int>& marked){
        if(marked[currCourse]==1){
            return true;
        }
        if(marked[currCourse]==2)  return false;
        marked[currCourse] = 1;
        for(int dependentCourse : adjList[currCourse]){
            if(cycle(dependentCourse, numCourses, adjList, marked)){
                return true;
            }
        }
        marked[currCourse] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(vector<int> pairing : prerequisites){
            adjList[pairing[1]].push_back(pairing[0]);
        }
        vector<int> marked(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(marked[i]==0){
                if(cycle(i, numCourses, adjList, marked))    return false;
            }
        }
        return true;
    }
};