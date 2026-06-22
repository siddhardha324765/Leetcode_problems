class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        int ans = 0; 
        map<pair<double,double>,set<pair<int,int>>>mpp;
        //   y - y1 = (y-y1)/(x-x1) * (x-x1);
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                   double m = (double)(points[j][1] - points[i][1]) / 
                              (double)(points[j][0] - points[i][0]);
                   double c =  (double)points[i][1] - m*(double)points[i][0];
                   if((points[j][0] - points[i][0]) == 0){
                    c = (double)points[i][0];
                   }
                 //  cout<<m<<" "<<c<<endl;
                  mpp[{m,c}].insert({points[i][0],points[i][1]});   
                   mpp[{m,c}].insert({points[j][0],points[j][1]});       
            }
        }
      for(auto i: mpp){
        ans = max(ans,(int)i.second.size());
      }
      return ans;
    }
};