class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Initial number of active sections
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        // Augment with '1' at both ends
        string t = "1" + s + "1";

        int maxGain = 0;
        int i = 0;
        int m = t.size();

        while (i < m) {

            // Find a block of 0s
            if (t[i] == '0') {
                int leftZeros = 0;

                while (i < m && t[i] == '0') {
                    leftZeros++;
                    i++;
                }

                // Find the following block of 1s
                while (i < m && t[i] == '1') {
                    i++;
                }

                // Find the next block of 0s
                int rightZeros = 0;
                int j = i;

                while (j < m && t[j] == '0') {
                    rightZeros++;
                    j++;
                }

                // A valid trade needs zero blocks
                // on both sides of a 1-block
                if (rightZeros > 0) {
                    maxGain = max(maxGain,
                                  leftZeros + rightZeros);
                }
            } 
            else {
                i++;
            }
        }

        return ones + maxGain;
    }
};