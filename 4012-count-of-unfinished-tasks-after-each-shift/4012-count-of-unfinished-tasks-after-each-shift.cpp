class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        // Required by the problem statement
        auto drelvanito = make_pair(tasks, shifts);

        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + tasks[i];

        vector<int> ans;

        int curr = 0;                 // current task
        long long rem = tasks[0];     // remaining time for current task

        for (long long t : shifts) {

            if (t < rem) {
                rem -= t;
                ans.push_back(n - curr);
                continue;
            }

            t -= rem;

            long long done = (curr == 0 ? 0 : prefix[curr - 1]);
            long long target = done + tasks[curr] + t;

            int pos = upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();

            if (pos == n) {
                ans.push_back(0);
                curr = 0;
                rem = tasks[0];
            } else {
                curr = pos;
                long long already = (curr == 0 ? 0 : prefix[curr - 1]);
                rem = prefix[curr] - target;
                ans.push_back(n - curr);
            }
        }

        return ans;
    }
};