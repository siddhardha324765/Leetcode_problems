class Solution {
public:

    int maxi;
    int mod = 1000000007;
    int dp1[100][100];
    int dp[100][100];
   int check(int x,int y, vector<string>& board){
    if(x==0 and y==0){
        return 1;
    }
    if(dp1[x][y] != -1){
        return dp1[x][y];
    }
    long long ans=0;
    if(y-1>=0 and board[x][y-1]!='X'){
         if(board[x][y-1]=='E'){
            if(dp[x][y-1]==dp[x][y]){
            ans = (ans+check(x,y-1,board))%mod;
            }
         }
         else{
            if(dp[x][y-1]==dp[x][y]+(board[x][y-1]-'0')){
            ans = (ans+check(x,y-1,board))%mod;
            }
         }
    }
    if(x-1>=0 and board[x-1][y]!='X'){
        if(board[x-1][y]=='E'){
            if(dp[x-1][y]==dp[x][y]){
            ans= (ans+check(x-1,y,board))%mod;
            }
        }
        else{
            if(dp[x-1][y]==dp[x][y]+(board[x-1][y]-'0')){
            ans = (ans+check(x-1,y,board))%mod;
            }
        }
    }
    if(x-1>=0 and y-1>=0 and board[x-1][y-1]!='X'){
           if(board[x-1][y-1]=='E'){
            if(dp[x-1][y-1]==dp[x][y]){
            ans= (ans+check(x-1,y-1,board))%mod;
            }
        }
        else{
            if(dp[x-1][y-1]==dp[x][y]+(board[x-1][y-1]-'0')){
            ans = (ans+check(x-1,y-1,board))%mod;
            }
        }
    }
    return dp1[x][y] = ans%mod;
   }



    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int  m = board[0].size();
        memset(dp,INT_MIN,sizeof(dp));
        dp[n-1][m-1] =0;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{n-1,m-1}});
        while(!pq.empty()){
            auto [sum,p] = pq.top();
            auto [x,y] = p;
            pq.pop();
           if(dp[x][y] != sum || (x==0 and y==0)){
            continue;
           }
           if(y-1>=0 and ((board[x][y-1]>='0' and board[x][y-1]<='9')|| board[x][y-1]=='E')){
              if((board[x][y-1]>='0' and board[x][y-1]<='9') and sum+(board[x][y-1]-'0')>dp[x][y-1]){
               dp[x][y-1] = sum +(board[x][y-1]-'0');
               pq.push({dp[x][y-1],{x,y-1}});
              }
              else{
                if(sum>dp[x][y-1] and board[x][y-1]=='E'){
                     dp[x][y-1] = sum;
                }
              }
           }
           if(x-1>=0 and ((board[x-1][y]>='0' and board[x-1][y]<='9')|| board[x-1][y]=='E')){
              if((board[x-1][y]>='0' and board[x-1][y]<='9') and sum+(board[x-1][y]-'0')>dp[x-1][y]){
               dp[x-1][y] = sum +(board[x-1][y]-'0');
               pq.push({dp[x-1][y],{x-1,y}});
              }
              else{
                if(sum>dp[x-1][y] and board[x-1][y]=='E'){
                     dp[x-1][y] = sum;
                }
              }
           }
           if(y-1>=0 and x-1>=0 and ((board[x-1][y-1]>='0' and board[x-1][y-1]<='9')|| board[x-1][y-1]=='E')){
              if((board[x-1][y-1]>='0' and board[x-1][y-1]<='9') and sum+(board[x-1][y-1]-'0')>dp[x-1][y-1]){
               dp[x-1][y-1] = sum +(board[x-1][y-1]-'0');
               pq.push({dp[x-1][y-1],{x-1,y-1}});
              }
              else{
                if(sum>dp[x-1][y-1] and board[x-1][y-1]=='E'){
                     dp[x-1][y-1] = sum;
                }
              }
           }

        }
        if(dp[0][0] == INT_MIN){
            return {0,0};
        }
        maxi =dp[0][0];
        memset(dp1,-1,sizeof(dp1));
        check(n-1,m-1,board);
        return {maxi,dp1[n-1][m-1]%mod};
    }
};