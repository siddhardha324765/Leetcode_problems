class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans =0;
        int  n = intervals.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    continue;
                }
                int a = intervals[i][0];
                int b = intervals[i][1];
                int c = intervals[j][0];
                int d = intervals[j][1];
                if(c<=a and b<=d){
                    ans++;
                    break;
                }
            }
        }
        return n-ans;
    }
};