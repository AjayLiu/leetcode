class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        // find smallest num index
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int smallIndex = left;
        left = 0; 
        right = nums.size()-1;
        
        // search left or right
        if(target > nums[right]){
            right = smallIndex;
        } else {
            left = smallIndex;
        }
        
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if(nums[left] == target)
            return left;
        
        return -1;
    }
};