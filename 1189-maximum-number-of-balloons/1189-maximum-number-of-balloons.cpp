class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt=0;
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        for(int i=0;i<text.size();i++){
            if(text[i]=='b'){cnt++;}
            if(text[i]=='a'){cnt1++;}
            if(text[i]=='l'){cnt2++;}
            if(text[i]=='o'){cnt3++;}
            if(text[i]=='n'){cnt4++;}
        }
        cnt2=cnt2/2;
        cnt3=cnt3/2;
        vector<int> arr;
        arr.push_back(cnt);
        arr.push_back(cnt1);
        arr.push_back(cnt2);
        arr.push_back(cnt3);
        arr.push_back(cnt4);
        int min=9999;
        for(int i=0;i<5;i++){
            if(arr[i]<min){
                min=arr[i];
            }
        }
        return min;
    }
};