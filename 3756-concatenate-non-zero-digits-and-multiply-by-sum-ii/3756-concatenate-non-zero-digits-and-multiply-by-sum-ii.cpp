class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long mod = 1000000007;
        vector<long long>di(n+1);
        vector<long long>con(n+1);
        vector<int>ans(queries.size());
        vector<int>no_zero(n+1);
        vector<long long>pow(n+1,1);
        for(int i=1;i<=n;i++){
            pow[i] = (pow[i-1]*10)%mod;
        }
        for(int i=0;i<n;i++){
            int d = s[i]-'0';
            di[i+1]=di[i]+d;
            no_zero[i+1] = no_zero[i] + (d==0?0:1);
            if(d==0){
                con[i+1] = con[i];
            }
            else{
                con[i+1] = (con[i]*10 +d)%mod;
            }
        }
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int len=no_zero[r+1] - no_zero[l];
            long long t1 = con[l];
            long long t2 = con[r+1];
            long long v = (t2 - (t1*pow[len])%mod +mod)%mod;
            long long sum = di[r+1] - di[l];
            ans[i] = (v*sum)%mod;
        }
        return ans;
    }
};