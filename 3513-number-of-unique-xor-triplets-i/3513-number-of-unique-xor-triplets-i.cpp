class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int bit=0;
        int n = nums.size();
        while(n!=0){
            bit++;
            n=n/2;
        }
        int ans=0;
        bit--;
        while(bit>=0){
            ans += pow(2,bit);
            bit--;
        }
        return ans+1;
    }
};