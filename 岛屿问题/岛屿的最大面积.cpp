class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0; 
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                res = max(res, area(grid, i, j));
            }
        }
        return res;
    }
    int area(vector<vector<int>>& grid, int i, int j){
        if(!isArea(grid, i, j)) return 0;
        if(grid[i][j] != 1) return 0;
        grid[i][j] == 2;
        return 1 + area(grid, i-1, j) + area(grid, i+1,j) + area(grid, i, j+1) + area(grid, i, j-1);
    }
    bool isArea(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        return 0<=i && i<m && j <n && 0<=j ? 1 : 0;
    }
};