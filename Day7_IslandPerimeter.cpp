class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i+=1) {
            for(int j=0;j<grid[i].size();j+=1) {
                if(grid[i][j]) {
                    count+=1;
                    if(i!=0 && grid[i-1][j]==1) repeat+=1;
                    if(j!=0 && grid[i][j-1]==1) repeat+=1;
                    }
                }
            }
        return count*4-repeat*2;
        }
};
