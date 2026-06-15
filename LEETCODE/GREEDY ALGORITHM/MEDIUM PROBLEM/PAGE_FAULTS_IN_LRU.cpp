/*
https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=page-faults-in-lru

Page Faults in LRU
In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm. 
Note:- Before solving this example revising the OS LRU cache mechanism is recommended.

We have to insert a newPage into memory if the newPage is not already present in the memory

if newPage is already present in the memory, we update its index in Map
if newPage is not present in memory, we check if memory is full or not
if memory is full
    we remove the least frequently used page and add the newPage with its index
if memory is not full
    we insert the newPage with its index
while inserting a newPage into Memory we increment the number of pageFaults
time complexity => O(n*logC)
space complexity => O(C)

*/

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        map<int,int> pagesInMemory;
        int maxSize = C;
        int pageFault = 0;
        for(int i=0;i<N;i++){
            int currPagesInMem = pagesInMemory.size();
            if(pagesInMemory.find(pages[i])!=pagesInMemory.end()){
                pagesInMemory[pages[i]] = i;
                continue;
            }
            if(currPagesInMem<maxSize){
                pagesInMemory[pages[i]] = i;
                currPagesInMem++;
            }
            else{
                int pageToDelete = 0, currMin=INT_MAX;
                for(auto& page : pagesInMemory){
                    if(page.second<currMin){
                        currMin = page.second;
                        pageToDelete = page.first;
                    }
                }
                pagesInMemory.erase(pageToDelete);
                pagesInMemory[pages[i]] = i;
            }
            pageFault++;
        }
        return pageFault;
    }
};