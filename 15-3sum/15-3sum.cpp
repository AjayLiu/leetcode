class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target = -1 * nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[left] + nums[right];
                // cout<<nums[i]<<"+"<<nums[left]<<"+"<<nums[right]<<endl;
                if(sum == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    int oldLeft = left;
                    while(left < right && nums[left] == nums[oldLeft]){
                        left++;
                    }
                    int oldRight = right;
                    while(left < right && nums[right] == nums[oldRight]){
                        right--;
                    }
                } else{
                    if(sum < target)
                        left++;
                    else
                        right--;
                }
            }
            
            int oldI = i;
            while(i+1 < nums.size() && nums[i+1] == nums[oldI]){
                i++;
            }
        }
        return ans;
    }
};