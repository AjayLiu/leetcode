class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp; // complement -> index
        for(int i = 0; i < nums.size(); i++){
            int &num = nums[i];
            auto itr = comp.find(target - num);
            if(itr != comp.end()){
                return {i, itr->second};
            }
            
            comp[num] = i;
        }
        return {};
    }
};