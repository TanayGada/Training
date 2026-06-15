/*
https://leetcode.com/problems/word-ladder/description/

Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Approach:
1. We use level order traversal (bfs)
2. in each iteration, we change 1 character of the currWord and check whether it exits in wordList or is it the endWord
eg. we have "hit"
we change 1st character from a to z and check whether it is available in wordList
ait, bit, cit, ...., zit
none of these is present in wordList
so we change i from a to z
hat, hbt, hct, hdt, ..., hzt
hot is present in wordList, so the ansSequence is => hit -> hot ->....
we check for aot, bot, cot, dot, eot, ..., zot
hit -> hot -> dot -> ...
hit -> hot -> lot -> ...
 1      2      3
So, the level at which we get endWord, is the min no of steps required 
similarly we reach the endWord

We use a queue for bfs and a set to search for elements in wordList
We push beginWord into queue with a counter maintaining the sequence number
We pop elements from queue and change its first letter from a to z and check if present in wordList
if present, we push that element in queue and pop that element from set
if the queue becomes empty and we dont get the endWord, we can say that its not possible
N =>  length(wordList)
tc => O(length(word)*26*N)
sc => O(N)
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> qt;
        qt.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!qt.empty()){
            string word = qt.front().first;
            int steps = qt.front().second;
            qt.pop();
            if(word==endWord)   return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        qt.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};


// his can be modeled as a graph problem where each word is a node, and there is an edge between two words if they differ by exactly one character.
// We need the shortest transformation sequence, which directly suggests using BFS, because BFS guarantees the shortest path in an unweighted graph.
// Instead of explicitly building the graph, we generate neighbors on the fly by changing each character of the current word from ‘a’ to ‘z’ and checking if the new word exists in the dictionary.
// We start BFS from beginWord, and for each word:
// - Try all possible one-letter transformations
// - If the transformed word exists in the dictionary, push it into the queue
// - Remove it from the set to avoid revisiting
// We continue level by level, and the level at which we first reach endWord gives the shortest transformation length.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> list;
        for(string s : wordList)    list.insert(s);
        queue<string> qt;
        qt.push(beginWord);
        int cnt = 1;
        while(!qt.empty()){
            int sz = qt.size();
            while(sz--){
                string ele = qt.front();
                qt.pop();
                if(ele==endWord)    return cnt;
                for(int i=0; i<ele.size(); i++){
                    string ele_copy = ele;
                    for(int j=0; j<26; j++){
                        ele_copy[i] = 'a'+j;
                        if(list.count(ele_copy)){
                            qt.push(ele_copy);
                            list.erase(ele_copy);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};