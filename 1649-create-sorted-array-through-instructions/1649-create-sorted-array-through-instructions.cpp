
class segment{
    public:
    vector<int>seg;
    segment(int m){
        seg.resize(4*m +1);
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
    int createSortedArray(vector<int>& instructions) {
        segment s(100002);
        long long ans =0;
        for(int i=0;i<instructions.size();i++){
          ans += min(s.query(0,0,100001,0,instructions[i]-1),s.query(0,0,100001,instructions[i]+1,100001));
          s.update(0,0,100001,instructions[i]);
        }
        return ans%1000000007;
    }
};