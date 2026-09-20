class Solution {
public:
    int reverseDegree(string s) {
        int sum =0;
        for(int i=0;i<s.size(); i++){
            char ch = s[i];
            int num = 26 -(ch - 'a');
            
            sum += num*(i+1);
        }
        return sum;
    }
};