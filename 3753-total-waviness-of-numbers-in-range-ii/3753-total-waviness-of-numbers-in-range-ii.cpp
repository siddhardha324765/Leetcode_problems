class Solution {
public:

// ind = 17 , tight = 0|1 , start = 0|1 , pre = 0 to 10 , end = 0 to 2 , wave = 0 to 15

 
   long long dp[17][2][2][11][3][17];

   long long count(int ind,bool tight,bool start,int pre,int end,int wave,string & s){
     if(ind == s.size()){
        return wave;
     }
     if(dp[ind][tight][start][pre][end][wave] != -1){
        return dp[ind][tight][start][pre][end][wave];
     }
     long long ans = 0;
     int maxi = (tight)? s[ind]-'0' : 9 ;
     for(int i=0;i<=maxi;i++){
         if(i == 0 and start){
            ans += count(ind+1,tight and (i==maxi),start,pre,end,wave,s);
         }
         else if(start){
            ans += count(ind+1,tight and (i==maxi),0,i,0,wave,s);
         }
         else{
            if(i<pre){
                if(end == 2){
                    ans += count(ind+1,tight and (i==maxi),0,i,1,wave+1,s);
                }
                else{
                    ans += count(ind+1,tight and (i==maxi),0,i,1,wave,s);
                }
            }
            else if(i>pre){
                if(end == 1){
                    ans += count(ind+1,tight and (i==maxi),0,i,2,wave+1,s);
                }
                else{
                    ans += count(ind+1,tight and (i==maxi),0,i,2,wave,s);
                }
            }
            else{
                ans += count(ind+1,tight and (i==maxi),0,i,0,wave,s);
            }
         }
     }

     return dp[ind][tight][start][pre][end][wave] = ans;
   }


    long long find(long long num){
        string s = to_string(num);
        memset(dp,-1,sizeof(dp));
        return count(0,1,1,10,0,0,s);

    }

    long long totalWaviness(long long num1, long long num2) {
        return find(num2) - find(num1-1);
    }
};