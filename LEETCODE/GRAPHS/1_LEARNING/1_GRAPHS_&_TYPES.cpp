/*
Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
•	An undirected graph on  n  vertices can have edges between any pair of vertices.
•	The number of pairs of vertices (i.e., potential edges) in a graph with  n  vertices is given by the combination formula  \binom{n}{2} , which is  \frac{n(n-1)}{2} .
•	Each of these possible edges can either be present or absent in a graph. So, for each pair of vertices, there are 2 choices (edge present or absent).
*/

class Solution {
  public:
    long long count(int n) {
        // your code here
        int s = (n*(n-1))/2;
        return pow(2, s);
    }
};