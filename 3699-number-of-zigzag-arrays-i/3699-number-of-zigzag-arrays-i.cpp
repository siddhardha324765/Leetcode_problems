class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r-l+1;
        long long mod = 1000000007;
       vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(r+1,0)));
        for(int i=l;i<=r;i++){
            dp[1][1][i] = 1;
            dp[1][0][i] =1;
        }
          vector<long long>p1(r+1);
            vector<long long>p2(r+1);

        for(int i=2;i<=n;i++){

            for(int j = l;j<=r;j++){
              p1[j] = dp[i-1][0][j];
              p2[j] = dp[i-1][1][j];
              if(j>l){
                 p1[j] = (p1[j]+p1[j-1])%mod;
                 p2[j] = (p2[j]+p2[j-1])%mod;
              }
            }
            long long tot1 = p1[r];
            long long tot2 = p2[r];
               for(int j=l;j<=r;j++){
                if(j>l){
                    dp[i][1][j] = p1[j-1];
                    p1[j-1] =0;
                }
                dp[i][0][j]=(tot2-p2[j]+mod)%mod;
                
                p2[j]=0;
            }

            p1[l]=0;
        }
        long long ans =0;
        for(int j=l;j<=r;j++){
            ans =(ans + dp[n][1][j] + dp[n][0][j])%mod;
        }
        return ans;
    }
};