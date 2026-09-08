class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = min((long long)n, start * 1000 - 1);

            total += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return total;
    }
};