class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> grps;
        grps.push_back(nums);

        vector<int> power(15, 0);

        for (int bit = 14; bit >= 0; bit--) {

            // msb side, left -> right
            vector<vector<int>> next;

            int cnt = 0; // count of set bits

            for (int i = 0; i < grps.size(); i++) {

                vector<int> cur = grps[i];

                vector<int> ones;
                vector<int> zeros;

                for (int x : cur) {

                    if ((x & (1 << bit)) > 0) {
                        ones.push_back(x);
                    } 
                    else {
                        zeros.push_back(x);
                    }
                }

                // add ones first
                if (!ones.empty())
                    next.push_back(ones);

                // then zeros
                if (!zeros.empty())
                    next.push_back(zeros);

                cnt += ones.size();

                if (zeros.empty()) {
                    // all elements have this bit = 1
                    continue;
                }

                // We found some zeros.
                // Don't process later groups,
                // but copy them to next.
                for (int j = i + 1; j < grps.size(); j++) {
                    next.push_back(grps[j]);
                }

                break;
            }

            power[14 - bit] = cnt;

            grps = next;
        }

        return power;

    }
};