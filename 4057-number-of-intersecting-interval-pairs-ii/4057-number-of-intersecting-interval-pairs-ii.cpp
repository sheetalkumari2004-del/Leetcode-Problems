class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> temp = intervals;
        int n = temp.size();
        vector<int> st(n), ends(n);
        for(int i =0; i<n; i++){
            st[i] = temp[i][0];
            ends[i] = temp[i][1];
        }
        sort(st.begin(),st.end());
        sort(ends.begin(),ends.end());
        long long ni =0;
        for(int i=0;i<n;i++){
            int cnt = lower_bound(ends.begin(), ends.end(), st[i])
                        - ends.begin();
                        ni += cnt;

        }
        long long total = 1LL * n * (n - 1) / 2;
         return total - ni;
    }
};