class segment{
    public:
    vector<int>seg;
    segment(int n){
        seg.resize(4*n +1);
    }
    void update(int ind,int s,int e,int val,int v){
        if(s==e){
            seg[ind]=max(seg[ind],v);
            return ;
        }
        int mid = (s+e)/2;
        if(val<=mid){
            update(ind*2 +1 ,s,mid,val,v);
        }
        else{
            update(ind*2 +2,mid+1,e,val,v);
        }
        seg[ind] = max(seg[ind*2 +1],seg[ind*2 +2]);
    }
    int query(int ind,int s,int e,int val){
        if(s>val){
            return 0;
        }
        if(e<=val){
            return seg[ind];
        }
        int mid = (s+e)/2;
        return max(query(ind*2 +1,s,mid,val),query(ind*2 +2,mid+1,e,val));
    }
};


class Solution {
public:

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> a(obstacles);
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        segment s(a.size());
        vector<int>ans(obstacles.size());
        for(int i=0;i<ans.size();i++){
            int val = obstacles[i];
            int v = lower_bound(a.begin(),a.end(),val) - a.begin();
           // cout<<v<<" ";
            int dis = s.query(0,0,a.size()-1,v);
            ans[i] = 1 + dis;
            s.update(0,0,a.size()-1,v,dis+1);
        }
        return ans;
    }
};