class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int at){
        visited[at] = true;
        for(int i : rooms[at]){
            if(!visited[i])
                dfs(rooms, visited, i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        
        for(bool b : visited){
            if(!b)
                return false;
        }
        
        return true;
    }
};