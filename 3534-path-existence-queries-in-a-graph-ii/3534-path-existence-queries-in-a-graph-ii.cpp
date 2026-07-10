class Solution {
public:

  
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            a[i]={nums[i],i};
        }
        sort(a.begin(),a.end());
        vector<int>parent(n);
        for(int i=0;i<n;i++){
        parent[a[i].second] = i;
        }
        vector<vector<int>>dp(n,vector<int>(18,-1));
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n and a[j].first - a[i].first<=maxDiff){
                j++;
            }
            dp[i][0] = j-1;
            
        }
        for(int i=1;i<18;i++){
            for(int j=0;j<n;j++){
                int  k  = dp[j][i-1];
                if(k==-1){
                    continue;
                }
               dp[j][i] =  dp[k][i-1];
            }
        }
        //     for(int j=0;j<n;j++){  
        // for(int i=0;i<18;i++){
        //         cout<<dp[j][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        int m  = queries.size();
        vector<int>ans(m);
        for(int i = 0 ;i < m ;i++){
            int u = parent[queries[i][0]];
            int v = parent[queries[i][1]];
            if(u==v){
                ans[i] = 0;
                continue;
            }
           if(u>v){
                 swap(u,v);
           }
       
        int an=0;
        for(int i=17;i>=0;i--){
            if(dp[u][i] < v){
              u = dp[u][i];
              an += pow(2,i);
            }
        }

         if(dp[u][0] >= v){
           an++;
           }
           else{
             an = -1;
           }
          ans[i] = an;
        }

        return ans;
    }
};