
class segment{
    public:
     vector<int>seg;
     segment(int n){
        seg.resize(4*n  +1);
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
        seg[ind] = seg[ind*2  +1] + seg[ind*2 +2];
     }
     int query(int ind,int s,int e,int ql,int qr){
        if(s>qr || e<ql){
            return 0;
        }
        if(ql<=s and e<=qr){
            return seg[ind];
        }
        int mid = (s+e)/2;
        return query(ind*2 +1,s,mid,ql,qr) + query(ind*2 +2,mid+1,e,ql,qr);
     }
};
class Solution {
public:


    int reversePairs(vector<int>& nums) {
        vector<long long> vals;
        for (int x : nums) {
            vals.push_back(x);
            vals.push_back(2LL*x);
        }
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        int m =vals.size();
        segment seg(m);
        long long ans = 0;

        for(int i = nums.size()-1; i>= 0;i--){
        long long cur = nums[i];
            int pos = lower_bound(vals.begin(),vals.end(),cur)-vals.begin();
            if(pos>0){
              ans += seg.query(0,0,m-1,0,pos-1);
            }
            int pos1 =lower_bound(vals.begin(),vals.end(),2LL*cur)-vals.begin();
          //  cout<<pos1<<" ";
            seg.update(0,0,m-1,pos1);
        }

        return ans;
    }
};