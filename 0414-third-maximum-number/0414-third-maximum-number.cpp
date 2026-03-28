class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        
        int *max1 = &nums[0];
        int *max2 = nullptr; 
        int *max3 = nullptr;
        
        for(int i=1;i<nums.size();i++){
            
            // Check if value already seen (distinct values required!)
            if ((max1 && nums[i] == *max1) || (max2 && nums[i] == *max2) || (max3 && nums[i] == *max3)) {
                continue;
            }
            
            if(nums[i]> *max1){
                max3 = max2;
                max2 = max1;
                max1 = &nums[i];
                continue;
            }
            if(max2 == nullptr || nums[i] > *max2){
                max3 = max2;
                max2 = &nums[i];
                continue;
            }
            if(max3 == nullptr || nums[i]> *max3){
                max3 = &nums[i];
            }
        }
        
        return (max3 == nullptr) ? *max1 : *max3;
        
    }
};