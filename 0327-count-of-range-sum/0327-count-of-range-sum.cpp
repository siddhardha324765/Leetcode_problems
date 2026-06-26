
class segment{
    public:
    vector<int>seg;
    segment(int m){
        seg.resize(m*4 +1);
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
       vector<long long>pre(nums.size()+1);
       for(int i=0;i<nums.size();i++){
        pre[i+1] = pre[i] + nums[i];
       }
       vector<long long>con;
      for(int i=0;i<pre.size();i++){
        con.push_back(pre[i]);
      }
      sort(con.begin(),con.end());
      con.erase(unique(con.begin(),con.end()),con.end());
      int m =con.size();
      segment s(m);
      int ans = 0;
      for(int i=0;i<pre.size();i++){
        int r = lower_bound(con.begin(),con.end(),pre[i]-upper) - con.begin();
        int l= upper_bound(con.begin(),con.end(),pre[i]-lower ) - con.begin()-1;
        if(r<=l){
        ans += s.query(0,0,m-1,r,l);
        }
        int ind = lower_bound(con.begin(),con.end(),pre[i]) - con.begin();
        s.update(0,0,m-1,ind);
      }
      return ans;
    }
};