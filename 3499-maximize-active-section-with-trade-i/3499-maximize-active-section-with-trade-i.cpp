class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>>a;
        int i=0;
        // int j=0;
        int ans =0;
        int  u=0;
        while(i<s.size()){
          int  j =i;
          while(j<s.size() and s[j]==s[i]){
            j++;
          }
          if(s[i]=='1'){
            u += (j-i);
            ans = max(ans,u);
          }
          a.push_back({i,j-1});
          i=j;

        }
        for(int i=1;i<a.size()-1;i++){
             if(s[a[i].first]=='1' and s[a[i].first-1]=='0' and s[a[i].second+1]=='0'){
                ans = max(ans,(a[i-1].second-a[i-1].first+1)+(a[i+1].second-a[i+1].first+1)+u);
             }
        }
        return ans;
    }
};