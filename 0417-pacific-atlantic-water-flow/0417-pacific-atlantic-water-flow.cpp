class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
         int i, int j) {
    int rows = heights.size(), cols = heights[0].size();
    visited[i][j] = true;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols 
            && !visited[ni][nj] 
            && heights[ni][nj] >= heights[i][j]) {
            dfs(heights, visited, ni, nj);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size(), cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
    
    for (int i = 0; i < rows; i++) {
        dfs(heights, pacific, i, 0);        // left border
        dfs(heights, atlantic, i, cols-1);  // right border
    }
    for (int j = 0; j < cols; j++) {
        dfs(heights, pacific, 0, j);        // top border
        dfs(heights, atlantic, rows-1, j);  // bottom border
    }
    
    vector<vector<int>> result;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (pacific[i][j] && atlantic[i][j])
                result.push_back({i, j});
    return result;
}
};