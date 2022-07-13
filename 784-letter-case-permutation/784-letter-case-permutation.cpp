class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans = {""};
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            vector<string> temp;
            for(string ansstr : ans){
                if(isalpha(c)){
                    temp.push_back(ansstr + (char)tolower(c));
                    temp.push_back(ansstr + (char)toupper(c));
                }  else {
                    temp.push_back(ansstr + c);
                }
            }
            ans = temp;
        }
        return ans;
    }
};