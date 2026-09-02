class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum =0, maxi = 0, mini = 0, minsum =0;
        for(int i =0; i<nums.size(); i++){
            maxsum+=nums[i];
            maxi = max(maxi, maxsum);
            if(maxsum<0) {
                maxsum =0;
            }
            minsum += nums[i];
            mini = min(mini, minsum);
            if(minsum>0){ 
                minsum=0;
            }
            
        }
        return max(maxi, abs(mini));

    }
};