class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n);
        int light =1;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                parent[i] = parent[i-1];
            }
            else{
                parent[i]=light++;
            }
        }
        int m = queries.size();
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int a=queries[i][0];
            int b = queries[i][1];
            if(parent[a]==parent[b]){
                ans[i] = true;
            }
        }
        return ans;
    }
};