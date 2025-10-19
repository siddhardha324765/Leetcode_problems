class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int ans=0;
        for(int i=0;i<nums.size();i++){  
       int mpp[100005]={0};
       mpp[nums[i]]++;
       int odd=0;
       int even=0;
       if(nums[i]%2==0){
        even++;
       }
       else{
        odd++;
       }
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[j]]++;
                 if(nums[j]%2==0 and mpp[nums[j]]==1){
        even++;
       }
       else if(nums[j]%2!=0 and mpp[nums[j]]==1){
        odd++;
       }
       if(even==odd){
        if(ans<j-i+1){
            ans=j-i+1;
        }
       }
            }
        }
       return ans;
    }
};