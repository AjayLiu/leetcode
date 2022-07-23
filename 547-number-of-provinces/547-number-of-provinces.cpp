class Solution {
public:
    bool dfs(vector<vector<int>> &isConnected, vector<bool> &visited,int at){
        if(visited[at])
            return false;
        
        visited[at] = true;
        
        for(int i = 0; i < isConnected[at].size(); i++){
            if(isConnected[at][i] == 1)
                dfs(isConnected, visited, i);
        }
        
        return true;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); i++){
            if(dfs(isConnected, visited, i))
                ans++;
        }
        
        return ans;
        
    }
};