class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(),restrictions.end());
        if(restrictions.size()!=0 and restrictions[0][0]!=1){
            restrictions.insert(restrictions.begin(),{1,0});
        }
        if(restrictions.size()!=0 and restrictions[restrictions.size()-1][0]!=n){
            restrictions.push_back({n,n});
        }
        if(restrictions.size()==0){
            return n-1;
        }
        int s = restrictions.size();
        for(int i=s-2;i>=0;i--){
            if(restrictions[i][1]>restrictions[i+1][1]){
                int maxi = restrictions[i+1][1];
                int dis = restrictions[i+1][0] - restrictions[i][0];
                restrictions[i][1] = min(restrictions[i][1],maxi + dis);
            }
        }
        for(int i=1;i<s;i++){
            if(restrictions[i][1]>restrictions[i-1][1]){
              int maxi = restrictions[i-1][1];
                int dis = restrictions[i][0] - restrictions[i-1][0];
                restrictions[i][1] = min(restrictions[i][1],maxi + dis);
            }
        }
        int ans = restrictions[0][1];
        for(int i=1;i<s;i++){
          int dis = restrictions[i][0] - restrictions[i-1][0] -1 ;
          int maxi = max(restrictions[i][1], restrictions[i-1][1]);
          int a = abs(restrictions[i][1] - restrictions[i-1][1]);
          dis -= a;
          dis++;
          dis/=2;
          ans = max(ans,maxi+dis);
        }
        return ans;
    }
};