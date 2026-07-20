class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int total_zero = 0,total_one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                total_zero++;
            }
            else{
                total_one++;
            }
        }
        vector<bool>ans(strs.size());
        for(int i=0;i<strs.size();i++){
            int in_zero=0;
            int in_one=0;
            int in_que=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    in_zero++;
                }
                else if(strs[i][j]=='1'){
                    in_one++;
                }
                else{
                    in_que++;
                }
            }
            if(in_zero>total_zero || in_one>total_one){
                continue;
            }
            bool  flag = true;
            int req_zero = total_zero - in_zero;
            int req_one = total_one - in_one;
            int j = s.size();
            int last_one = s.size();
            while(j>0){
              j--;
              if(last_one <= j and s[j]=='1'){
                continue;
              }
              if(last_one>j and s[j]==strs[i][j]){
                continue;
              }
              if(s[j]=='1' and (strs[i][j]=='0' || (strs[i][j]=='?' and req_one==0))){
                flag = 0;
                break;
              }
              else if(s[j]=='1' and req_one!=0){
                req_one--;
                continue;
              }
              int j1 = j;
              while(j1>=0 and s[j1]=='0'){
                j1--;
              }
             
              int req_zero1=j-j1;
              if(j1==-1){
                req_zero1=j+1;
              }
               j1+=1;
              int u = req_zero1;
              int j2=j;
            //  cout<<u<<" ";
              while(j2>=0 and req_zero1!=0){
                if(last_one<=j2){
                    j2--;
                }
                else  if(strs[i][j2]=='?'){
                    if(req_one!=0){
                        req_one--;
                    }
                    else{
                        req_zero--;
                        req_zero1--;
                    }
                    j2--;
                }
                else if(strs[i][j2]=='1'){
                    j2--;
                }
                else{
                    j2--;
                    req_zero1--;
                }
                
              }
              //cout<<j2<<" "<<req_zero1<<endl;
               //cout<<last_one<<" "<<j2<<" " <<req_zero1<<endl;
             // cout<<last_one<<" ";
              if(req_zero1!=0){
                flag = 0;
                break;
              }
              last_one = j2+1;
              j=j-u +1;
            }
            if(flag){
                ans[i]=1;
            }
        }
        return ans;
    }
};