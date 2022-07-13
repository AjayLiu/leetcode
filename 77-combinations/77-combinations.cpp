class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void backtrack(queue<int> choices, const int &k){
        if(choices.empty()){
            return;
        }
        
        while(!choices.empty()){
            v.push_back(choices.front());
            choices.pop();
            if(v.size()==k){
                ans.push_back(v);
            } else {
                backtrack(choices, k);
            }
            v.pop_back();
        }
        
        
        
    }
    
    vector<vector<int>> combine(const int n, const int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        backtrack(q, k);
        return ans;
    }
};