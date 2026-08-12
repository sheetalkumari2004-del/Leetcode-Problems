class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left =0;
        
        unordered_map<int, int> freq;
        int maxl =0;
        for(int right =0; right< nums.size(); right++){
            freq[nums[right]]++;
            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            maxl = max(maxl, right-left+1);
        }
          return maxl;
    }
};