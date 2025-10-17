class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
       int fre[1048579]={0};
       int max=INT_MIN;
        for(int i=0;i<deliciousness.size();i++){
            fre[deliciousness[i]]++;
            if(deliciousness[i]>max){
                max=deliciousness[i];
            }
        }
        int ans=0;
        for(int i=0;i<=max;i++){
          if(fre[i]!=0)
            for(int j=0;j<22;j++){
                int h=pow(2,j);
                if(h-i==i){
                    int u=((long long)fre[i]*(long long)(fre[i]-1))/2   % 1000000007;
                    ans = (ans+u)%1000000007;
                }
                else if(h-i>i and h-i<=max and fre[h-i]!=0){
                   int u=((long long)fre[i]*(long long)fre[h-i])%1000000007;
                     ans = (ans+u)%1000000007;
                }
            }
            
        }
        return ans;
    }
};