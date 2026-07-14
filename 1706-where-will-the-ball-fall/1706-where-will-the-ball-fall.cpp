class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int size = grid.size();
        int n = grid[0].size();
        vector<int>ans(n,-1);
        for(int j=0;j<n;j++)
        {
            int row = 0;
            int col =j;
            while(row!=size and col!=n){
                if(grid[row][col]==1){
                    if(col+1<n and grid[row][col+1]==1){
                        row++;
                         col++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(col-1>=0 and grid[row][col-1]==-1){
                        row++;
                        col--;
                    }
                    else{
                        break;
                    }
                }
            }
            // cout<<row<<" ";
            if(row==size){
                ans[j] = col; 
            }
        }
        return ans;
    }
};