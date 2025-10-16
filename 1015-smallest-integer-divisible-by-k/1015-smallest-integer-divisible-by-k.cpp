class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0){
            return -1;
        }
        int u=k;
        int cnt=0;
       while(u!=0){
        u=u/10;
        cnt++;
       }
       int num=0;
       for(int i=0;i<cnt;i++){
        num=num*10 + 1;
       }
       int ans=cnt;
       if(num<k){
        num=num*10+1;
        ans++;
       }
       while(1){
        if(num%k==0){
            return ans;
        }
        else{
            num=num%k;
            num=num*10 + 1;
            ans++;
        }
       }
        return 1;
    }
};