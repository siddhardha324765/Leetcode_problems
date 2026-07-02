class Solution {
public:


    void dfs(vector<vector<int>>&dp,vector<vector<int>>&grid,int i,int j){
        if(i+1<dp.size() and grid[i+1][j]+dp[i][j]<dp[i+1][j]){
              dp[i+1][j] = grid[i+1][j]+dp[i][j];
              dfs(dp,grid,i+1,j);
        }
        if(i-1>=0 and grid[i-1][j]+dp[i][j]<dp[i-1][j]){
            dp[i-1][j] =  grid[i-1][j]+dp[i][j];
               dfs(dp,grid,i-1,j);
        }
        if(j-1>=0 and grid[i][j-1]+dp[i][j]<dp[i][j-1]){
            dp[i][j-1] = grid[i][j-1]+dp[i][j];
               dfs(dp,grid,i,j-1);
        }
         if(j+1<dp[0].size() and grid[i][j+1]+dp[i][j]<dp[i][j+1]){
            dp[i][j+1] = grid[i][j+1]+dp[i][j];
               dfs(dp,grid,i,j+1);
        }
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
       dp[0][0] = grid[0][0];
       dfs(dp,grid,0,0);
       return dp[n-1][m-1]<health; 
    }
};