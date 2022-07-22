class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &graph, vector<int> soFar, int at){
        soFar.push_back(at);
        if(at == graph.size()-1){
            ans.push_back(soFar);
        }
        for(int i = 0; i < graph[at].size(); i++){
            dfs(ans, graph, soFar, graph[at][i]);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(ans, graph, {}, 0);
        return ans;
    }
};