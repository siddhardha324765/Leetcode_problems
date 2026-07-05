# EASIEST 4DP SOLUTION IN C++ | EASY INTUITION FOR BEGINNERS | OPTIMIZIED

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
For every character in target, we can choose its matching occurrence either from word1 or word2. The only restrictions are:

Chosen indices inside word1 must be strictly increasing.
Chosen indices inside word2 must be strictly increasing.
At least one character must come from each string.

Since the lengths are at most 100, we can use memoized DFS. We keep track of the current position in target, the last chosen index from each word, and a state indicating whether characters have been taken from word1, word2, or both.

To avoid scanning the strings repeatedly, we preprocess the positions of every character in both strings.
# Approach
<!-- Describe your approach to solving the problem. -->
Preprocess word1 and word2 by storing all positions of every character ('a' to 'z').
Define a memoized DFS with state:
pos → current position in target.
pos1 → last chosen position in word1.
pos2 → last chosen position in word2.
pick → usage state:
0 = none used yet
1 = only word1 used
2 = only word2 used
3 = both words have been used
For the current target character:
Try every valid occurrence in word1 after pos1.
Try every valid occurrence in word2 after pos2.
Update the usage state accordingly.
When the entire target is formed, count the solution only if both strings have contributed (pick == 3).
Memoize every state to avoid recomputation.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(T × N² × (N₁ + N₂)) in the worst case, where T is the target length and N₁, N₂ are the lengths of the two words. Since all lengths are at most 100, this easily fits within the limits.
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(T × N₁ × N₂ × 4) for the DP table, i.e. approximately 101 × 101 × 101 × 4 states.
# Code
```cpp []
class Solution {
public:

    // pos = 0 to target.size() , pos1 = 0 to word1.size() , pos2 = 0 to word2.size() ,
     // picking  = none,both,word1,word2
    long long dp[101][101][101][4];
     long long mod = 1000000007;
    long long dfs(vector<vector<int>>&c1,vector<vector<int>>&c2,string & target,int        pos,int pos1,int pos2,int pick){
       if(pos == target.size()){
           return pick == 3 ? 1 : 0;
       } 
        if(dp[pos][pos1][pos2][pick] != -1){
            return dp[pos][pos1][pos2][pick];
        }
        long long ans =0;
        int ind = target[pos]-'a';
        vector<int> & a = c1[ind];
        for(int i=0;i<a.size();i++){
            if(a[i]>pos1){
                if(pick == 0 || pick ==1){
                ans = (ans+dfs(c1,c2,target,pos+1,a[i],pos2,1))%mod;
                }
                else if(pick ==2 || pick ==3){
                    ans = (ans+dfs(c1,c2,target,pos+1,a[i],pos2,3))%mod;
                }
            }
        }
        vector<int> & a1 = c2[ind];
        for(int i=0;i<a1.size();i++){
            if(a1[i]>pos2){
                if(pick ==0 || pick==2){
                    ans = (ans+dfs(c1,c2,target,pos+1,pos1,a1[i],2))%mod;
                }
                else if(pick==1 || pick==3){
                    ans = (ans+dfs(c1,c2,target,pos+1,pos1,a1[i],3))%mod;
                }
            }
        }
        return dp[pos][pos1][pos2][pick] = ans%1000000007;
    }
    
    int interleaveCharacters(string word1, string word2, string target) {
        vector<vector<int>>c1(26);
        vector<vector<int>>c2(26);
        for(int i=0;i<word1.size();i++){
            c1[word1[i]-'a'].push_back(i+1);
        }
        for(int i=0;i<word2.size();i++){
            c2[word2[i]-'a'].push_back(i+1);
        }
        memset(dp,-1,sizeof(dp));
       return  dfs(c1,c2,target,0,0,0,0)%1000000007;
    }
};
```