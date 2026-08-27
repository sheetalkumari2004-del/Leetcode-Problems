class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
         vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        long long prev = (long long)lower - 1;

        for (int x : nums) {

            // Ignore numbers outside [lower, upper]
            if (x < lower || x > upper)
                continue;

            // There is a missing range between prev and x
            if ((long long)x - prev > 1) {
                ans.push_back({
                    (int)(prev + 1),
                    x - 1
                });
            }

            // Move prev to current number
            prev = x;
        }

        // Check for missing numbers after the last element
        if (prev < upper) {
            ans.push_back({
                (int)(prev + 1),
                upper
            });
        }

        return ans;
    }
};