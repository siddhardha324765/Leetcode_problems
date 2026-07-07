class Solution {
public:
    long long sumAndMultiply(int n) {
        string x = "0";
        long long sum =0 ;
        while(n!=0){
            sum += (n%10);
            if(n%10!=0){
                x += ((n%10)+'0');
            }
            n=n/10;
        }
        reverse(x.begin(),x.end());
        if(x.size()==1){
            return 0;
        }
        x.pop_back();
        long long n1 = stoll(x);
        return n1*sum;
    }
};