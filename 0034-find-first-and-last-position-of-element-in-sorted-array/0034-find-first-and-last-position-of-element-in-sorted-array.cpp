class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size()-1,low=0;
        int lans=-1,uans=-1;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid] >= target)
            {
                if(nums[mid] == target)
                    lans=mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        if(lans == -1)
            return {-1,-1};
        high = nums.size()-1;
        low=lans;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid] <= target)
            {
                if(nums[mid] == target)
                    uans=mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
         
        return {lans,uans};
    }
};