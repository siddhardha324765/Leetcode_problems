class Solution {
public:
    int divisibleGame(vector<int>& nums) {
           
        set<int>s;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    s.insert(nums[i]/j);
                    s.insert(j);
                }

            }
            if(nums[i]>1){
                s.insert(nums[i]);
            }
        }
        s.insert(2);

        long long score=LLONG_MIN;
        long long  k ;
        for(auto i : s){
            long long maxi=LLONG_MIN;
            long long curr = LLONG_MIN;
            for(int j=0;j<nums.size();j++){
                long long v = (nums[j]%i==0) ? nums[j] : -nums[j];
                if(curr<0){
                    curr = v;
                }
                else{
                    curr+=v;
                }
                maxi = max(maxi,curr);
            }
            if(score<maxi){
                score = maxi ;
                k = i;
            }
        }
        long long mod = 1000000007;
        return ((((score%mod)+mod)%mod)*k)%mod;
    }
};