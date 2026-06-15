/*
link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

N meetings in one room
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

we sort according to the end time of meetings
and then select meetings with startTime > previous meeting endTime
*/

truct meeting{
    int start;
    int end;
    int pos;
};

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(struct meeting a, struct meeting b){
        return a.end<b.end;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, comp);
        int prevMeetEnd = meet[0].end;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(meet[i].start>prevMeetEnd){
                cnt++;
                prevMeetEnd = meet[i].end;
            }
        }
        return cnt;
    }
};