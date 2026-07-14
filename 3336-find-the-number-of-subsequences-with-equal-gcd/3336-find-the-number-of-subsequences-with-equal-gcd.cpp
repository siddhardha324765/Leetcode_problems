class Solution {
public:
    int mod = 1000000007;
    // ind = 201 , s1 = 201 , s2 = 201;
    int dp[201][201][201];
    
    int dfs(int ind,int s1,int s2,vector<int>&nums){
        if(ind == nums.size()){
            if(s1==s2 and s1!=0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][s1][s2]!=-1){
            return dp[ind][s1][s2];
        }
        long long ans =0;
        if(s1==0){
            ans = (ans + dfs(ind+1,nums[ind],s2,nums))%mod;
        }
        else{
            ans = (ans + dfs(ind+1,gcd(nums[ind],s1),s2,nums))%mod;
        }
        if(s2==0){
            ans = (ans + dfs(ind+1,s1,nums[ind],nums))%mod;
        }
        else{
            ans = (ans + dfs(ind+1,s1,gcd(nums[ind],s2),nums))%mod;
        }
        ans =(ans+dfs(ind+1,s1,s2,nums))%mod;
        return dp[ind][s1][s2] = ans;
    }


    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return  dfs(0,0,0,nums)%mod;

    }
};