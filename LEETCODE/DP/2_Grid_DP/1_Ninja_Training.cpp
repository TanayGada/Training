// link: https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=SUBMISSION
// we have 2 states, 1. current_day, 2. task_taken_prev_day
// for top down dp, 
// base case: for all tasks excluding prev_day task, whichever task is maximum, return it
// recurrence: max of curr_task_points + func(day-1, curr_task) for all tasks not equal to task_taken_prev_day

// recursion
int func(int day, int last_task, vector<vector<int>>& points){
    int maxi = -1e9;
    if(day==0){
        for(int i=0; i<3; i++){
            if(last_task!=i)    maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    for(int i=0; i<3; i++){
        int score = 0;
        if(last_task!=i){
            score = points[day][i] + func(day-1, i, points);
        }
        maxi = max(maxi, score);
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return func(n-1, 3, points);

}


//memoized
// tc -> O(n*4*3), sc -> O(n*4) + O(n)
int func(int day, int last_task, vector<vector<int>>& points, vector<vector<int>>& dp){
    int maxi = -1e9;
    if(day==0){
        for(int i=0; i<3; i++){
            if(last_task!=i)    maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if(dp[day][last_task]!=-1)  return dp[day][last_task];
    for(int i=0; i<3; i++){
        int score = 0;
        if(last_task!=i){
            score = points[day][i] + func(day-1, i, points, dp);
        }
        maxi = max(maxi, score);
    }
    return dp[day][last_task] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return func(n-1, 3, points, dp);

}

// tabulated
// tc -> O(n*4*3), sc -> O(n*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,0));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i!=j)    dp[0][i] = max(points[0][j], dp[0][i]);
        }
    }
    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));
    for(int day = 1; day<n; day++){
        for(int last=0; last<4; last++){
            for(int task=0; task<3; task++){
                if(task!=last) dp[day][last] = max(dp[day-1][task] + points[day][task], dp[day][last]);
            }
        }
    }
    return dp[n-1][3];
}

// memory optimization
// tc -> O(n*4*3), sc -> O(2*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4,0);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i!=j)    prev[i] = max(points[0][j], prev[i]);
        }
    }
    prev[3] = max(prev[0], max(prev[1], prev[2]));
    for(int day = 1; day<n; day++){
        vector<int> curr(4, 0);
        for(int last=0; last<4; last++){
            for(int task=0; task<3; task++){
                if(task!=last) curr[last] = max(prev[task] + points[day][task], curr[last]);
            }
        }
        prev = curr;
    }
    return prev[3];
}