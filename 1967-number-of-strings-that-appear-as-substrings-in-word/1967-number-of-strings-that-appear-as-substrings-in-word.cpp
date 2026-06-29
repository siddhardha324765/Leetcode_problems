class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(int i=0;i<patterns.size();i++){
            if(patterns[i].size()>word.size()){
                continue;
            }
            else{
              
                int n=patterns[i].size();
                for(int p=0;p<=word.size()-n;p++){
                     string si="";
                for(int o=p;o<p+n;o++){
                    si+=word[o];
                }
                if(si==patterns[i]){
                    cnt++;
                    break;
                }}
            }
        }
        return cnt;
    }
};