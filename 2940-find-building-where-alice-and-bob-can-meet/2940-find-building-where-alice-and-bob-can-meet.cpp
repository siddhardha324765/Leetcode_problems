
class segment{
    public:
    vector<int>seg;
    segment(vector<int>nums){
        seg.resize(4*nums.size() +1);
        build(0,0,nums.size()-1,nums);
    }
    void build(int ind,int l,int r,vector<int>&nums){
        if(l==r){
            seg[ind] = nums[l];
            return ;
        }
        int mid = (l+r)/2;
        build(ind*2 +1,l,mid,nums);
        build(ind*2 +2,mid+1,r,nums);
        seg[ind] = max(seg[ind*2 +1],seg[ind*2 +2]);
    }
    int query(int ind,int l,int r,int ql,int qr,int val){
        if(seg[ind]<val || ql>qr){
            return INT_MAX;
        }
        if(l==r){
            return l;
        }
        int mid = (l+r)/2;
        int ans =INT_MAX;
        if(ql<=mid){
            ans = min(ans,query(ind*2 +1,l,mid,ql,qr,val));
        }
        if(ans!=INT_MAX){
            return ans;
        }
        ans = min(ans,query(ind*2 +2,mid+1,r,ql,qr,val));
        return ans;
    }
};


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        segment seg(heights);
        int n = queries.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a>b){
                swap(a,b);
            }
            if(heights[a]<heights[b] || a==b){
                ans[i] = b;
            }
            else{
                int v = seg.query(0,0,heights.size()-1,b+1,heights.size()-1,heights[a]+1);
                if(v!= INT_MAX){
                      ans[i]=v;
                }
            }
        }
        return ans;
    }
};