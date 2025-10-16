class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%value>=0){
            mpp[nums[i]%value]++;}
            else{
                mpp[(nums[i]%value)+value]++;
            }
        }
        for(auto i:mpp){
           if(i.second!=1){
            int u=i.second - 1;
            mpp[i.first + value]+=u;
           }
        }
       int i=0;
       while(1){
        if(mpp[i]==0){
            return i;
        }
        i++;
       }
        return 0;
    }
};