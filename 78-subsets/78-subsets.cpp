class Solution {
public:
    
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int> list, int depth){
        if(depth == nums.size()){
            result.push_back(list);
            return;
        }
        
        backtrack(nums, list, depth+1); // empty set
        
        // add the new number
        list.push_back(nums[depth]);
        backtrack(nums, list, depth+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        backtrack(nums, v, 0);
        return result;
    }
};