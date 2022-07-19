class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            int checkLeft = mid - 1, checkRight = mid + 1;
            // cout<<mid<<endl;
            if(checkLeft >= 0 && checkRight < nums.size()){
                bool leftSmall = nums[checkLeft] < nums[mid];
                bool rightSmall = nums[checkRight] < nums[mid];
                if(leftSmall && rightSmall){
                    return mid;
                } else if (nums[checkLeft] > nums[mid]){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if(checkLeft < 0){
                    if(nums[mid] > nums[checkRight])
                        return mid;
                    else
                        left = mid + 1;
                } else {
                    if(nums[mid] > nums[checkLeft])
                        return mid;
                    else
                        right = mid;
                }
            }
        }
        return left;
    }
};