class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans = 1;
        if(mpp.count(1)){
             if(mpp[1]%2==0){
                ans =max(ans,mpp[1]-1);
             }
             else{
                ans =max(ans,mpp[1]);
             }
        }
        for(auto i:mpp){
            if(i.first==1){
                continue;
            }
                int cnt=0;
                long long h = i.first;
                while(mpp.count(h) and mpp[h]>1){
                    cnt+=2;
                    h*=h;
                    if(h>=100000){
                        break;
                    }
                }
                if(mpp.count(h)){
                    cnt++;
                }
                else{
                    cnt--;
                }
                ans =max(ans,cnt);
        }
        return ans;
    }
};