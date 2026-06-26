
class segment{
    public:
     vector<long long>seg;
     segment(int n){
        seg.resize(4*n +1);
     }
     void update(int ind,int s,int e,int val){
        if(s==e){
            seg[ind]++;
            return ;
        }
        int mid = (s+e)/2;
        if(val<=mid){
            update(ind*2 +1,s,mid,val);
        }
        else{
            update(ind*2 +2,mid+1,e,val);
        }
        seg[ind] = seg[ind*2 +1] + seg[ind*2 +2];
     }
     long long query(int ind,int s,int e,int ql,int qr){
        if(ql>e || qr<s){
            return 0;
        }
        if(ql<=s and qr>=e){
            return seg[ind];
        }
        int mid = (s+e)/2;
        return query(ind*2 +1,s,mid,ql,qr) + query(ind*2 +2,mid+1,e,ql,qr);
     }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int>pre(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
            pre[i+1] = pre[i] + (nums[i]==target);
            }
            else{
                pre[i+1] = pre[i] -1;
            }
        }
        vector<int>com = pre;
        sort(com.begin(),com.end());
        com.erase(unique(com.begin(),com.end()),com.end());
        segment s(com.size());
        long long ans=0;
        for(int i=0;i<pre.size();i++){
            int ind = lower_bound(com.begin(),com.end(),pre[i]) - com.begin();
            ans += s.query(0,0,com.size()-1,0,ind-1);
            s.update(0,0,com.size()-1,ind);
        }
        return ans;
    }
};