class Solution {
public:
    
   // ind =  32 , tight = 0|1 , prev = 0|1
    int dp[32][2][2];

   int count(int ind,bool tight,bool pre,string &s){
    if(ind == s.size()){
        return 1;
    }
    if(dp[ind][tight][pre] != -1){
        return dp[ind][tight][pre];
    }
    int maxi = (tight == true)? s[ind]-'0' : 1;
    int ans =0;
    for(int i=0;i<=maxi;i++){
        if(i==1 and pre==1){
            continue;
        }
        ans += count(ind+1,tight and (i==maxi),i,s);
    }
    return dp[ind][tight][pre] = ans;
   }



    int findIntegers(int n) {
        string s="";
        while(n!=0){
            s+= (n%2)+'0';
            n=n/2;
        }
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));

        return count(0,1,0,s);
    }
};