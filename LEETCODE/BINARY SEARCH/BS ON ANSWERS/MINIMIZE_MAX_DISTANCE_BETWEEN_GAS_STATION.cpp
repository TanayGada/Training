/*
link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

Minimize Max Distance to Gas Station
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.


arr => 1 13 17 23   k=5
gap =>  12 4  6
max gap = 12
so first element will be placed between 1 and 13 so new gap is 6

arr => 1 x 13 17 23
gap =>  6 6  4  6
max gap = 12
so second element will be placed between 1 and x or x and 13 or 17 or 23 so new gap is 4

arr => 1 x x 13 17 23
gap =>  4 4 4  4  6
max gap = 6

arr => 1 x x 13 17 x 23
gap =>  4 4 4  4  3 3
max gap = 4

arr => 1 x x x 13 17 x 23
gap =>  3 3 3 3  4  3 3
max gap = 4

arr => 1 x x x 13 x 17 x 23
gap =>  3 3 3 3  2 2  3 3
max gap = 3

for every k, we find the max gap and place 1k in that gap
*/

//tc = O(n^2) and sc = O(n-1) solution 
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); 
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

//tc = O(nlogn) and sc = O(n-1) solution 
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); 
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    //insert the first n-1 elements into pq
    //with respective distance values:
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }
    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        //insert the current gas station:
        howMany[secInd]++;
        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}



//tc => O(nlogn) solution => Binary Search
/*
Whenever there is ans in decimal (long double)
There is a different skeleton for Binary Search
a long double has precision of upto 1e-6
int low = x, high = y;
long double diff = 1e-6;
while(high-low>=diff){
    int mid = low + (high-low)/2;
    if(condition){
        low = mid;
    }
    else{
        high = mid;
    }
}
return ans;
*/

    class Solution {
  private:
    int getCntOfStations(long double mid, vector<int>&stations){
        int cntOfStations = 0;
        for(int i=0;i<stations.size()-1;i++){
            int x = (stations[i+1]-stations[i])/mid;
            if((x*mid)==(stations[i+1]-stations[i])){
                x--;
            }
            cntOfStations+=x;
        }
        return cntOfStations;
    }
    
  public:
    long double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        long double low = 0, high = 0;
        for(int i=0;i<stations.size()-1;i++){
            high = max(high,(long double) (stations[i+1] - stations[i]));
        }
        long double diff = 1e-6;
        long double ans = 0;
        while(high-low>diff){
            long double mid = low + (high-low)/2.0;
            int cntOfStations = getCntOfStations(mid, stations);
            if(cntOfStations>k){
                low = mid;
                ans = max(ans, mid);
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};