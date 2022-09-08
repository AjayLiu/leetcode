class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int prevBest = nums[0];
        int best = nums[0];
        
        // prevBest = -2
        // [-2, 1]
        for(int i = 1; i < nums.size(); i++){
            prevBest = std::max(nums[i], prevBest + nums[i]);
            best = std::max(best, prevBest);
        }
        
        return best;
    }
};