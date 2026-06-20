class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target){
            return 0;
        }
        return target%gcd(x,y) == 0;
    }
};