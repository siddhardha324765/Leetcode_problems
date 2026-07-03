class Solution {
public:

   bool check(vector<vector<pair<int,int>>>&adj,vector<bool>& online,int limit,long long &k){
     priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
     vector<long long>dis(online.size(),LLONG_MAX);
     dis[0]=0;
     pq.push({0,0});
     while(!pq.empty()){
         auto [total, node] = pq.top();
         pq.pop();
         if(total>k){
            continue;
         }
         if(node == online.size()-1){
            return 1;
         }
         for(auto &[v,w] : adj[node]){
            if(w<limit){
                continue;
            }
            if(dis[node] + w <dis[v]){
                dis[v] = dis[node] +w;
                pq.push({dis[v],v});
            }
         }

     }
     return 0;
   }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int  n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        int l=INT_MAX;
        int r=0;
       for(int i=0;i<edges.size();i++){
        if(online[edges[i][0]] and online[edges[i][1]]){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        l = min(l,edges[i][2]);
        r = max(r,edges[i][2]);
        }
       }
       if(!check(adj,online,l,k)){
        return -1;
       }
       int ans = -1;
       while(l<=r){
        int mid = (l+r)/2;
        if(check(adj,online,mid,k)){
            l=mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
       }
        return ans;
    }
};