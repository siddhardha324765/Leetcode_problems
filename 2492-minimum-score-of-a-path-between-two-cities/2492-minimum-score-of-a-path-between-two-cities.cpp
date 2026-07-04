class Solution {
public:
    
    void dfs(vector<vector<pair<int,int>>>&adj,vector<bool>&flag,int ind,vector<int>&a){
        for(int i=0;i<adj[ind].size();i++){
            if(!flag[adj[ind][i].first]){
                flag[adj[ind][i].first]=1;
                a.push_back(adj[ind][i].first);
                dfs(adj,flag,adj[ind][i].first,a);
            }
        }
        return ;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>p(n+1,INT_MAX);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
             p[roads[i][0]]=min(p[roads[i][0]],roads[i][2]);
               p[roads[i][1]]=min(p[roads[i][1]],roads[i][2]);
        }
       vector<bool>flag(n,false);
       vector<int>a;
      int ans=INT_MAX;
        flag[1]=1;
        a.push_back(1);
        dfs(adj,flag,1,a);
         for(int i=0;i<a.size();i++){
            ans=min(ans,p[a[i]]);
         }
        return ans;
    }
};