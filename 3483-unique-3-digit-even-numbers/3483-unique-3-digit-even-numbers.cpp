class Solution {
public:
    int ans = 0;
    vector<int> digits;
    bool used[10] = {false};
    set<int> st;

    void solve(string &s) {
        // We have formed a 3-digit number
        if (s.size() == 3) {
            // Last digit must be even
            if ((s[2] - '0') % 2 == 0) {
                st.insert(stoi(s));
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            // This copy of the digit is already used
            if (used[i])
                continue;

            // First digit cannot be 0
            if (s.empty() && digits[i] == 0)
                continue;

            used[i] = true;
            s.push_back(digits[i] + '0');

            solve(s);

            // Backtrack
            s.pop_back();
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        this->digits = digits;

        string s = "";
        solve(s);

        return st.size();
    }
};