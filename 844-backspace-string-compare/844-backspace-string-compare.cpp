class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk;
        for(char c : s){
            if(c == '#'){
                if(!stk.empty())
                    stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        stack<char> stk2;
        for(char c : t){
            if(c == '#'){
                if(!stk2.empty())
                    stk2.pop();
            } else {
                stk2.push(c);
            }
        }
        
        return stk == stk2;
    }
};