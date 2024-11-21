class Solution {
public:
    
    void solve(vector<vector<int>>& image, int sr, int sc, int oldColor, int color, int rows, int cols) {
       
        if (sr < 0 || sc < 0 || sr >= rows || sc >= cols || image[sr][sc] != oldColor) {
            return;
        }
        
       
        image[sr][sc] = color;
        
    
        solve(image, sr + 1, sc, oldColor, color, rows, cols);
        solve(image, sr - 1, sc, oldColor, color, rows, cols);
        solve(image, sr, sc + 1, oldColor, color, rows, cols);
        solve(image, sr, sc - 1, oldColor, color, rows, cols);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int oldColor = image[sr][sc];
        
       
        if (oldColor == color) return image;
      
        solve(image, sr, sc, oldColor, color, rows, cols);
        return image;
    }
};
