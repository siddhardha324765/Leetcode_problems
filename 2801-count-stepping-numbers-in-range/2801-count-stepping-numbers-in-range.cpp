class Solution {
public:
 
   // index  = 101 , tight = 0|1 , prev = 0 to 9 , start = 0|1 , form = 0|1
   long long mod = 1000000007;
   long long dp[102][11][2][2][2];
   
   long long count(int ind,int pre,bool tight,bool start,bool form ,string &s){
    if(ind ==s.size()){
         return form && !start;
    }
    // if(!form){
    //     return 0;
    // }
    if( dp[ind][pre][tight][start][form] != -1){
        return dp[ind][pre][tight][start][form];
    }
    int maxi = (tight == true)? s[ind]-'0' : 9;
    long long ans = 0;
    for(int i=0;i<=maxi;i++){
        if(start and i==0){
            ans += count(ind+1,pre,tight and (i == maxi),start,form,s);
        }
        else{
             bool ok;

                if (pre == 10) {
                    ok = true;   // first real digit always ok
                } else {
                    ok = form && (abs(pre - i) == 1);
                }
            ans += count(ind+1,i,tight and (i==maxi),0,ok,s);
        }
        ans = ans % mod;
    }
    return dp[ind][pre][tight][start][form] = ans;
   }
    
    long long find(string l){
        memset(dp,-1,sizeof(dp));
       return  count(0,10,1,1,1,l);

    }
   
    int countSteppingNumbers(string low, string high) {
      bool flag = true;
      for(int i=0;i<low.size()-1;i++){
        if(!(abs((low[i]-'0') - (low[i+1]-'0')) == 1)){
            flag = false;
            break;
        }
      }
     int a = 0;
      if(flag){
        a = 1;
      }
      
        return ((find(high) - find(low))%mod + a + mod)%mod;
    }
};