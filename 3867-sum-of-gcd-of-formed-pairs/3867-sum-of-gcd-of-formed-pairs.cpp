class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long t=0;
        vector<long long>a(nums.size());
        for(int i=0;i<nums.size();i++){
            t=max(t,(long long)nums[i]);
            a[i]=gcd(t,nums[i]);
        }
        sort(a.begin(),a.end());
        int left=0;
        int right=nums.size()-1;
        long long answer=0;
        while(left<right){
            answer+=gcd(a[left],a[right]);
            left++;
            right--;
        }
        return answer;
    }
};