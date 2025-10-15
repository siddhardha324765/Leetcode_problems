class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0){
            return target-1;
        }
        int ans=0;
        while(target>1){ans++;
            if(target%2==0 and maxDoubles>0){
                target/=2;
                maxDoubles--;
            }
            else{
                target--;
            }
        }
        return ans;
    }
};