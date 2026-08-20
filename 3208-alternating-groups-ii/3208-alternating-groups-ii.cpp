class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt =0;
        int alter = 1;
        for(int i = 1; i < n+k-1 ; i++){
            if(colors[i%n] != colors[(i-1)%n]){
                alter++;
            }
            else{
                alter =1; 
                
            }
            if(alter>=k){
                cnt++;
            }
        }
        return cnt;
    }
};