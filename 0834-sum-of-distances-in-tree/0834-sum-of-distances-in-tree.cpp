class Solution {
public:

     void dfs(int node,vector<pair<int,int>>&down,vector<int>&dp,vector<vector<int>>&adj,vector<bool>&flag){
        if(adj[node].size()==1 and flag[adj[node][0]]==1){
             down[node] = {0,1};
             return ;
        }
        for(int i=0;i<adj[node].size();i++){
            if(!flag[adj[node][i]]){
                flag[adj[node][i]]  = true;
            dfs(adj[node][i],down,dp,adj,flag);
            down[node].first+=(down[adj[node][i]].first + down[adj[node][i]].second);
            down[node].second+=down[adj[node][i]].second;
            }
        }
        down[node].second++;
        dp[node] = down[node].first;
     }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>up(n);
        vector<pair<int,int>>down(n);
        vector<int>dp(n);
        vector<bool>flag(n);
        //down_node , ans , nodes
        flag[0] = true;
        dfs(0,down,dp,adj,flag);
     //   cout<<dp[0]<<" ";
        up[0]=dp[0];
        for(int i=0;i<n;i++){
           // cout<<down[i].first<<" "<<down[i].second<<endl;
            flag[i] = false;
        }
        flag[0]= true;
        queue<pair<int,int>>q;
        for(int i=0;i<adj[0].size();i++){
            flag[adj[0][i]] = true;
             q.push({adj[0][i],0});
        }
        while(!q.empty()){
            auto [n1,n2] = q.front();
            q.pop();
            int upper = up[n2];
            upper -= (down[n1].first + down[n1].second);
            up[n1] = down[n1].first + upper + (n - down[n1].second);
            for(int i=0;i<adj[n1].size();i++){
                if(!flag[adj[n1][i]]){
                    flag[adj[n1][i]] = true;
                    q.push({adj[n1][i],n1});
                }
            }
        }
        return up;
    }
};