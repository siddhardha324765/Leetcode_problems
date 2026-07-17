class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
     sort(start.begin(),start.end());
     long long ans = 0;
     long long  l=0;
     long long r = start[start.size()-1]+d;
     while(l<=r){
        long long mid = (l+r)/2;
        bool flag = true;
        long long last = start[0]+mid;
        for(int i=1;i<start.size();i++){
            long long x = start[i] + d;
            if(last>=(long long)start[i] and last<=x){
                last+=mid;
            }
            else if(last<=x){
                last=(long long)start[i]+mid;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            ans = mid;
            //cout<<ans<<" ";
            l = mid+1;
        }
        else{
            r = mid-1;
        }
     }
     return  ans;
    }
};