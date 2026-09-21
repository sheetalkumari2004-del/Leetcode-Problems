class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);

        for(int num: nums){
            int x = num%k;
            vector<long long> new_dp(k,0);
            new_dp[x]++;

            for(int r=0; r<k; r++){
                if(dp[r]>0){
                    int newrem = (r*x)%k;
                    new_dp[newrem]+=dp[r];
                }
            }
            for(int r=0; r<k; r++){
                ans[r]+=new_dp[r];
            }
            dp=new_dp;
        }
        return ans;
    }
};