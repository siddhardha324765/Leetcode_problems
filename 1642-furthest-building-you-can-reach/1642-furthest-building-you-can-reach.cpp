class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        int i=0;
        while(i!=n-1){
               if(i+1<n and heights[i+1]<=heights[i]){
                i++;
               }
               else{
                int dif = heights[i+1] - heights[i];
                if(bricks>=dif){
                    i++;
                    pq.push(dif);
                    bricks -= dif;
                }
                else if(ladders!=0){
                     if(!pq.empty() and pq.top()>dif){
                        bricks += pq.top();
                        bricks -=dif;
                        pq.pop();
                        pq.push(dif);
                     }
                     
                     ladders--;
                     i++;
                }
                else{
                    return i;
                }
               }
        }
        return i;
    }
};