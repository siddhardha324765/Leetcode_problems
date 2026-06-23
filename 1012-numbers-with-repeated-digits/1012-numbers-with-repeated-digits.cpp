class Solution {
public:
   
   int dp[11][2][2][1024][2];

    int count(int ind,bool tight,bool repeat,int mask,bool start,string &s){
        if(ind == s.size()){
            return repeat;
        }
        if(dp[ind][tight][repeat][mask][start] != -1 ){
            return dp[ind][tight][repeat][mask][start];
        }
        // if(repeat){
        //     return 0;
        // }
        int ans = 0;
        int maxi = (tight == true)? s[ind]-'0' : 9;
        for(int i=0;i<=maxi;i++){
            if(i == 0 and start){
              ans += count(ind+1,tight && (i==maxi),repeat,mask,1,s);
            }
            else{
                  bool ch = (mask >> i) & 1;
                  ans += count(ind+1,tight && (i==maxi), repeat | ch,mask | (1 << i),0,s);
            }
        }
     return dp[ind][tight][repeat][mask][start] = ans;
    }
   

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return count(0,1,0,0,1,s);
    }
};