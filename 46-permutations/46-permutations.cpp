class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void backtrack(vector<int> choices){
        if(choices.empty()){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < choices.size(); i++){
            int toAdd = choices[i];
            v.push_back(toAdd);
            choices.erase(choices.begin()+i);
            backtrack(choices);
            v.pop_back();
            choices.insert(choices.begin()+i, toAdd);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
            
    }
};