class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        for(char c : s){
            if(c==']'){
                string sub = "";
                while(stk.top() != "["){
                    string tmp = stk.top();
                    reverse(tmp.begin(), tmp.end());
                    sub+=tmp;
                    stk.pop();
                }
                stk.pop();
                reverse(sub.begin(), sub.end());
                
                string repS = "";
                
                while(!stk.empty() && isdigit(stk.top()[0])){
                    repS = repS.insert(0, stk.top());
                    stk.pop();
                }
                int repeat = stoi(repS);
                
                string subMult = "";
                while(repeat--){
                    subMult+=sub;
                }
                stk.push(subMult);
                //cout<<subMult<<endl;
            } else {
                string tmp(1,c);
                stk.push(tmp);
            }
        }
        string ans ="";
        while(!stk.empty()){
            ans=ans.insert(0, stk.top());
            stk.pop();   
        }
        return ans;
    }
};