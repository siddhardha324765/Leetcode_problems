class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       vector<int> arr;
       int n=gain.size();
       arr.push_back(0);
       for(int i=0;i<n;i++){
             arr.push_back(arr[i]+gain[i]);
       } 
       int max=-111;
       for(int i=0;i<n+1;i++){
          if(arr[i]>max){
            max=arr[i];
          }
       }
       return max;
    }
};