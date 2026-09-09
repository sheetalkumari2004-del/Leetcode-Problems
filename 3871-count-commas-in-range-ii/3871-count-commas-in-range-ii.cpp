class Solution {
public:
    long long countCommas(long long n) {
        long long start  = 1000;
        long long commas = 1;
        long long total = 0;
        while(start <= n){
            long long end = min(n, start*1000-1);
            total += (end-start+1)*commas;
            start *= 1000;
            commas++;
        }
        return total;
    }
    
};