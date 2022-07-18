class Solution {
public:
    int binSearch(vector<int>& nums, int target, bool findLeftMost){
        int left = 0, right = nums.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            int &num = nums[mid];
            if(num == target){
                ans = mid;
                if(findLeftMost){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if(num < target){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binSearch(nums, target, true), binSearch(nums, target, false)};
    }
};