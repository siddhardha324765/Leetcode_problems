class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int size = s.size();
        vector<int>ans(size);
        for(int i=0;i<s.size();i++){
            int j=i;
            int x=startPos[0];
            int y=startPos[1];
            int a=0;
            while(j<s.size()){
               if(s[j]=='U'){
                if(x-1>=0){a++;
                    x--;
                    j++;
                }
                else{
                    break;
                }
               }
               else if(s[j]=='D'){
                if(x+1<n){a++;
                  x++;
                  j++;
                }
                else{
                    break;
                }
               }
               else if(s[j]=='L'){
                if(y-1>=0){a++;
                    y--;
                    j++;
                }
                else{
                    break;
                }
               }
               else{
                if(y+1<n){a++;
                    y++;
                    j++;
                }
                else{
                    break;
                }
               }
            }
              ans[i]=a;
        }
        return ans;
    }
};