class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int targetColor, int newColor){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[i].size() || image[i][j] != targetColor || image[i][j] == newColor)
            return;
        image[i][j] = newColor;
        
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for(auto [x, y] : dirs){
            dfs(image, i+x, j+y, targetColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};