class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i =0; i<n; i++){
            if(s[i]==s[(i+1)%n]){
                cnt++;
            }
        }
        if (k == cnt) {
            return n - cnt;
        }
         if (k == cnt - 1) {
            return cnt;
        }
        return 0;
    }
};