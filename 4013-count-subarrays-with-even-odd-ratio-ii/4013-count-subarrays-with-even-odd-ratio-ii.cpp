class Solution {
public:
        struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int sum(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }

        int queryGE(int idx) {
            return sum(n) - sum(idx - 1);
        }
    };

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> allT;
        allT.push_back(0);

        long long even = 0, odd = 0;

        for (int x : nums) {
            if (x % 2 == 0)
                even++;
            else
                odd++;
            allT.push_back(1LL * b * even - 1LL * a * odd);
        }

        vector<long long> vals = allT;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        auto getIndex = [&](long long x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        vector<long long> pending;
        pending.push_back(0);

        long long ans = 0;
        even = odd = 0;
        long long T = 0;

        for (int x : nums) {

            if (x % 2) {
                odd++;
                T -= a;

                // Prefixes with fewer odd elements become eligible
                for (long long v : pending)
                    ft.add(getIndex(v), 1);

                pending.clear();
            } else {
                even++;
                T += b;
            }

            ans += ft.queryGE(getIndex(T));

            pending.push_back(T);
        }

        return ans;
        
    }
};