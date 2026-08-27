class Solution {
public:
 vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {

            if (x % p == 0) {
                factors.push_back(p);

                // Remove all occurrences of p
                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        // If something greater than 1 is left,
        // it is a prime number
        if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
         int n = nums.size();

        // Store prime factors of every number
        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            factors[i] = getPrimeFactors(nums[i]);
        }


        // prime -> number of elements in current window
        unordered_map<int, int> freq;

        int left = 0;
        int distinct = 0;
        int ans = 0;


        // Sliding window
        for (int right = 0; right < n; right++) {

            // Add nums[right]
            for (int p : factors[right]) {

                // This prime was not present before
                if (freq[p] == 0) {
                    distinct++;
                }

                freq[p]++;
            }


            // If we have more than k distinct primes,
            // shrink the window
            while (distinct > k) {

                // Remove nums[left]
                for (int p : factors[left]) {

                    freq[p]--;

                    // No element in window contains this prime
                    if (freq[p] == 0) {
                        freq.erase(p);
                        distinct--;
                    }
                }

                left++;
            }


            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};