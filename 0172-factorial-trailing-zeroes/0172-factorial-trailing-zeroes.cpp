class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        int a=5;
        while(1){
          if(n>=a){
            ans+=(n/a);
            a=a*5;
          }
          else{
            return ans;
          }
        }
        return 0;
    }
};