class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        
        long long maxi =0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long g = gcd(nums[i], nums[j]);
                long long st = (1LL * nums[i] * nums[j]) / (g * g);
                maxi = max(maxi, st);
            }
        }
        return maxi;
    }
};