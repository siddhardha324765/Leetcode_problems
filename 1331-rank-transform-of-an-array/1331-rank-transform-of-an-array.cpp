class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>a = arr;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        for(int i=0;i<arr.size();i++){
            int ind = lower_bound(a.begin(),a.end(),arr[i]) - a.begin();
            ind++;
            arr[i] = ind;
        }
        return arr;
    }
};