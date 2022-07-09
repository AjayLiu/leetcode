class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int targetColor, int newColor){
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != targetColor)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,targetColor,newColor);
        dfs(image,i+1,j,targetColor,newColor);
        dfs(image,i,j-1,targetColor,newColor);
        dfs(image,i,j+1,targetColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(newColor != oldColor){
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
};