class Solution {
public:
    int search(vector<int>& nums, int target) {
        int upper = nums.size();
        int lower = 0;
        if(nums[0]==target)
            return 0;
            
        while(upper-lower > 1){
            int index = lower + (upper-lower) / 2;
            int thisNum = nums[index];
            if(thisNum == target){
                return index;
            }
            if(thisNum > target){
                upper = index;
            } else {
                lower = index;
            }
        }
        return -1;
    }
};