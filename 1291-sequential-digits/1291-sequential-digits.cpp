class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        long long l = low;
        long long h = high;
        vector<int>ans;
        for(int i=1;i<=9;i++){
          long long num=i;
          if(l<=num and num<=h){
            ans.push_back(num);
          }
          while(num<=high){
            if(num%10==9){
                break;
            }
            int u = num%10;
            u++;
            num = num*10 + u;
            if(l<=num and num<=h){
            ans.push_back(num);
          }
          }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};