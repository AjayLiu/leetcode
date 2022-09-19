class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        int maxReachIndex = 0;
        while(index < nums.size() && index <= maxReachIndex){
            int jumpAmount = nums[index];
            if(index + jumpAmount > maxReachIndex){
                maxReachIndex = index + jumpAmount;
            }
            
            if(maxReachIndex >= nums.size()-1)
                return true;
            
            index++;
        }
        return false;
    }
};