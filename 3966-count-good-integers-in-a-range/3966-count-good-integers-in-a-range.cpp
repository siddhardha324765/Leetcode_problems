class Solution {
public:
   
   long long dp[17][2][11][2];
    int k1;
   long long count(int ind,bool tight,int pre,bool start,string & s){
    if(s.size() == ind){
        return 1;
    }
    if(dp[ind][tight][pre][start] != -1){
        return dp[ind][tight][pre][start];
    }
    int maxi = (tight == true)? s[ind]-'0' : 9;
    long long ans =0;
    for(int st = 0; st<=maxi;st++){
        if(pre == 10 and st ==0 ){
            ans += count(ind+1,tight&&(st==maxi),pre,start,s);
        }
        else if(pre == 10 || abs(pre-st)<=k1){
            ans += count(ind+1,tight&&(st==maxi),st,false,s);
        }
    }
    return dp[ind][tight][pre][start] = ans;
   }


   // count(index,tight,prev,leading_zero,string)
   long long find(long long num){
    string s = to_string(num);
    memset(dp,-1,sizeof(dp));
    return count(0,1,10,1,s);
   }
    long long goodIntegers(long long l, long long r, int k) {
        
        k1=k;

        return find(r)-find(l-1);
    }
};