class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size()*grid[0].size();
        k=k%n;
        if(k==0){
            return grid;
        }
        vector<int>arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
      
        while(k!=0){
            k--;
            
            vector<int> arr1;
              arr1.push_back(arr[arr.size()-1]);
            for(int i=0;i<arr.size()-1;i++){
                arr1.push_back(arr[i]);
            }
          
            arr={};
             for(int i=0;i<arr1.size();i++){
                arr.push_back(arr1[i]);
            }
            
        }
        vector<vector<int>>a;
        int cnt=0;
        vector<int>arr1;
         for(int i=0;i<arr.size();i++){
           if(cnt%grid[0].size()==0&&cnt!=0){
                 a.push_back(arr1);
                 arr1={};
                 cnt=1;
                 arr1.push_back(arr[i]);
           }
           else{
             arr1.push_back(arr[i]);
             cnt++;
           }
            }
             a.push_back(arr1);
        return a;
    }
};