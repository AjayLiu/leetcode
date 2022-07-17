class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int s : stones){
            q.push(s);
        }
        
        while(q.size() > 1){
            int x = q.top();
            q.pop();
            
            int y = q.top();
            q.pop();
            q.push(abs(y-x));
        }
        
        return q.top();
    }
};