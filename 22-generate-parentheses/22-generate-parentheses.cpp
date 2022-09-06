class Solution {
private:
    vector<string> ans;
    
public:
    void helper(string str, int openCount, int closeCount, const int &n){
        if(openCount == n && closeCount == n){
            ans.push_back(str);
            return;
        }
            
        if(openCount < n){
            helper(str+"(", openCount+1, closeCount, n);
        }
        if(openCount > closeCount){
            helper(str+")", openCount, closeCount+1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return ans;
    }
};