class Solution {
    int n, m;
    string source, pattern;
    vector<bool> canDelete;
    vector<vector<int>> dp;

public:
 int solve(int i, int j){
    if(i==n){
        if(j==m) return 0;

        return -1000000;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = -1000000;

     if(canDelete[i]) {

            int next = solve(i + 1, j);

            if (next != -1000000) {
                ans = max(ans, 1 + next);
            }
        }
        // Keep it without using it for pattern
        ans = max(ans, solve(i + 1, j));

        // Use it to match pattern[j]
        if (j < m && source[i] == pattern[j]) {

            ans = max(ans, solve(i + 1, j + 1));
        }

        return dp[i][j] = ans;
    
 }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        this->source = source;
        this->pattern = pattern;

        n = source.size();
        m = pattern.size();

        canDelete.assign(n, false);

        for (int idx : targetIndices) {
            canDelete[idx] = true;
        }

        dp.assign(n, vector<int>(m + 1, -1));

        return solve(0, 0);
    }
};