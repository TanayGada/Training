/*
https://leetcode.com/problems/word-ladder-ii/description/

1. BFS for Shortest Path:
Use BFS to explore all possible transformations from the beginWord.
Maintain a depthMap to record the minimum number of transformations required to reach each word.
If the endWord is reached during BFS, the search stops, and the depth of the endWord is noted.

2. DFS for Path Construction:
Once the BFS is complete, use DFS to backtrack from the endWord to the beginWord, constructing all valid paths that match the minimum transformation depth recorded in depthMap.
Each valid path is stored in the result list.

3. Word Transformation:
For each word, generate all possible transformations by changing one letter at a time and check if the transformed word exists in the wordList.
*/



class Solution {
public:
    void bfs(string beginWord, string endWord, vector<string>& wordList, map<string, int>& depthMap){
        set<string> list;
        for(string s : wordList)    list.insert(s);
        queue<string> qt;
        depthMap[beginWord] = 1;
        list.erase(beginWord);
        qt.push(beginWord);
        int cnt = 1;
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                string ele = qt.front();
                qt.pop();
                if(ele==endWord) return;
                for(int i=0; i<ele.size(); i++){
                    string ele_copy = ele;
                    for(int j=0; j<26; j++){
                        if(('a'+j)==ele[i]) continue;
                        ele_copy[i] = 'a'+j;
                        if(list.count(ele_copy)){
                            qt.push(ele_copy);
                            depthMap[ele_copy] = cnt+1;
                            list.erase(ele_copy);
                        }
                    }
                }
            }
            cnt++;
        }
    }

    void dfs(string word, string beginWord, map<string, int> depthMap, vector<string> seq, vector<vector<string>>& ans){
        if(word==beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = depthMap[word];
        for(int i=0; i<word.size(); i++){
            string word_copy = word;
            for(int j=0; j<26; j++){
                word_copy[i] = 'a' + j;
                if(depthMap.count(word_copy) && depthMap[word_copy]==(steps-1)){  
                    seq.push_back(word_copy);
                    dfs(word_copy, beginWord, depthMap, seq, ans);
                    seq.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> depthMap;
        bfs(beginWord, endWord, wordList, depthMap);
        for(auto i : depthMap)  cout<<i.first<<", "<<i.second<<endl;
        vector<vector<string>> ans;
        vector<string> seq = {endWord};
        dfs(endWord, beginWord, depthMap, seq, ans);
        return ans;
    }
};