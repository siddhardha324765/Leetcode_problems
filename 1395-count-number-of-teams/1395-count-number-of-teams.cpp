
class segment{
    public: 
    vector<int>seg;
    segment(vector<int>nums){
        int n=nums.size();
        seg.resize(4*(100001) +1);
        for(int i=0;i<nums.size();i++){
            update(0,0,100000,nums[i],1);
        }
    }
    void update(int ind,int s,int e,int val,bool flag){
        if(s==e){
            if(flag){
                seg[ind]++;
            }
            else{
                seg[ind]--;
            }
            return ;
        }
        int mid = (s+e)/2;
        if(val<=mid){
            update(ind*2 +1,s,mid,val,flag);
        }
        else{
            update(ind*2  +2,mid+1,e,val,flag);
        }
        seg[ind] = seg[ind*2  +1] + seg[ind*2 +2];
    }
     
    int query(int ind,int s,int e,int ql,int qr){
      //  push(ind,s,e,0);
      if(ql>e || qr<s){
          return 0;
      }
      if(ql<=s and e<=qr){
        // cout<<s<<" ";
          return seg[ind] ; 
      }
         int mid = (s+e)/2;
          
         int l  = query(ind*2 +1,s,mid,ql,qr);
         int r =  query(ind*2 +2,mid+1,e,ql,qr);
         return l+r;
    }
};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        segment s(rating);
        segment s1({});
        int ans  =0;
        for(int i=0;i<rating.size();i++){
           s.update(0,0,100000,rating[i],0);
          int a1 = s.query(0,0,100000,0,rating[i]-1);
          int a2 = s.query(0,0,100000,rating[i]+1,100000);
          int b1 = s1.query(0,0,100000,rating[i]+1,100000);
          int b2 = s1.query(0,0,100000,0,rating[i]-1);
          ans += (a1*b1);
          ans += (a2*b2);

           s1.update(0,0,100000,rating[i],1);
        }
        return ans;
    }
};