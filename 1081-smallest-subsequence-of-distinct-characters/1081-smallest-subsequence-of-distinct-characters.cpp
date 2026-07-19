class Solution {
public:
    string smallestSubsequence(string s) {
      string ans = "";
      unordered_map<char,int>mp;
      for(int i=0;i<s.size();i++){
        mp[s[i]] = i;
      }
      stack<char>st;
      unordered_map<char,bool>vis;
      for(int i=0;i<s.size();i++){
        if(vis[s[i]]){
            continue;
        }
        while(!st.empty() and st.top()>s[i] and mp[st.top()]>i){
            vis[st.top()] = false;
            st.pop();
        }
        st.push(s[i]);
        vis[s[i]] = true;
      }
      while(!st.empty()){
        ans += st.top();
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;    
    }
};