class Solution {
public:
    int maximumSwap(int num) {
        int u=num;
        vector<int>a;
        while(num!=0){
            a.push_back(num%10);
            num/=10;
        }
        for(int i=a.size()-1;i>0;i--){
            int o=a[i];
            int p=i;
               for(int j=i-1;j>=0;j--){
                 if(a[j]>=o and a[j]>a[i]){
                    o=a[j];
                    p=j;
                 }
               }
               if(p!=i){
                int num1=0;
                for(int l=a.size()-1;l>=0;l--){
                    if(p!=l and l!=i){
                        num1=num1*10 + a[l];
                    }
                    else if(p==l){
                        num1=num1*10 +  a[i];
                    }
                    else{
                        num1=num1*10   + a[p];
                    }
                }
                return num1;
               }
        }
        return u;
    }
};