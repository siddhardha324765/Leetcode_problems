class Solution {
public:
    int maxDiff(int num) {
      vector<int>a;
      while(num!=0){
        a.push_back(num%10);
        num/=10;
      }
      int p=9;
      for(int i=a.size()-1;i>=0;i--){
        if(p>a[i]){
            p=a[i];
            break;
        }
      }
      int u=0;
      for(int i=a.size()-1;i>=0;i--){
        if(a[i]==p){
            u=u*10 + 9;
        }
        else{
            u=u*10 + a[i];
        }
      }
      int u1=0;
      if(a[a.size()-1]==1){
         int p1=1;
      for(int i=a.size()-2;i>=0;i--){
        if(p1<a[i]){
            p1=a[i];
            break;
        }
      }
      if(p1==1){
        p1=987;
      }
      u1=a[a.size()-1];
      for(int i=a.size()-2;i>=0;i--){
        if(p1==a[i]){
            u1=u1*10;
        }
        else{
            u1=u1*10 + a[i];
        }
      } 
      }
      else{
        int p1=a[a.size()-1];
         for(int i=a.size()-1;i>=0;i--){
        if(p1==a[i]){
            u1=u1*10 + 1;
        }
        else{
            u1=u1*10 + a[i];
        }
      } 
      }
      return abs(u-u1);

    }
};