// link: https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=SUBMISSION


// backtrack on the dp table to get the LCS
// if s1[ind1]==s2[ind2], take that and ind1--, ind2--;
// if s1[ind1]!=s2[ind2], take the max of dp[ind1-1][ind2] and dp[ind1][ind2-1] and go to that state
// tc -> O(n*m), sc -> O(n*m)
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for(int ind1 = 1; ind1<=n; ind1++){
		for(int ind2 = 1; ind2<=m; ind2++){
			if(s1[ind1-1]==s2[ind2-1])	dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
			else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
		}
	}
	string lcs = "";
	int i=n, j=m;
	while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--; j--;
        }else if(dp[i-1][j]>dp[i][j-1])	i--;
        else j--;
    }
	reverse(lcs.begin(), lcs.end());
	return lcs;
}