class Solution {
public:
    double angleClock(int hour, int minutes) {
       hour=hour%12;
       hour=hour*30;
       double h=(double)hour;
       h+=(double)(minutes*0.5);
       minutes=minutes*6;
       double r;
       if(minutes>h){
        r=((double)(minutes)-h);
       }
       else{
        r=((double)h-(double)minutes);
       }
       return min(r,360-r);
    }
};