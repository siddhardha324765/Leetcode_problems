int findGCD(int* nums, int numsSize) {
    int po=nums[0];
    int ho=nums[0];
    int lo;
    for(int i=1;i<numsSize;i++){
if(nums[i]>po){po=nums[i];}
 if(nums[i]<ho){ho=nums[i];}
    }
    for(int k=ho;k>=0;k--){
        if(ho%k==0 && po%k==0){lo=k;break;}
    }
    return lo;
}