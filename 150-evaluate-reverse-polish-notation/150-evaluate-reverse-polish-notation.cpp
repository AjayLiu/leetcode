class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> stk;
        for(std::string token : tokens){
            char c = token.back();
            if(std::isdigit(c)){
                stk.push(token);
            } else {
                int rightOperand = std::stoi(stk.top());
                stk.pop();
                int leftOperand = std::stoi(stk.top());
                stk.pop();
                
                switch(c){
                    case '+':
                        stk.push(std::to_string(leftOperand + rightOperand));
                        break;
                    case '-':
                        stk.push(std::to_string(leftOperand - rightOperand));
                        break;
                    case '*':
                        stk.push(std::to_string(leftOperand * rightOperand));
                        break;
                    case '/':
                        stk.push(std::to_string(leftOperand / rightOperand));
                        break;
                }
            }
        }
        
        return std::stoi(stk.top());
    }
};