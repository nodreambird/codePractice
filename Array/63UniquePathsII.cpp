/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // if starting point is obstacle, no path       
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<int> cur(m,0);
        cur[0] = 1;
        for (int j = 0; j< n; j++)
            for (int i = 0; i < m; i ++){
                if (obstacleGrid[i][j] == 1){
                    cur[i] = 0;
                
                }else if (i> 0){
                   
                    cur[i] += cur[i-1];
                }
            }

        return cur[m-1];
    }
};

/*
note:
   similar idea with no obstacles. but need to consider the cases with edges.
   - to get m and n, obstacleGrid.size returns the rows, and first elem.size returns n.
   - if current point is an obstacle, mark it 0, means no way going to this step.
   - since most point is reached by left+up, if any of it is 0, that path is blocked, so add 0 does not add more
     unique path.
   - edge case: when the obstacles are at the [0,j] or [i,0] place
     if at [0,0] there is obstacle, there is no way we can go to finish.
     at [i,0] those points can only take its up value (cur[i-1]);
     at [0,j] those points can only take its left value (cur[i]);
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> cur (m,1);
        for (int j = 0; j< n; j++)
            for (int i = 0; i < m; i ++){
                if (obstacleGrid[i][j] == 1){
                    cur[i] = 0;
                }else if (j == 0 && i == 0){
                    cur[i] = 1;
                }else if(j == 0){
                    cur[i] = cur[i-1];
                }else if (i == 0){
                    cur[i] = cur[i];
                }else {
                    cur[i] += cur[i-1];
                }
            }

        return cur[m-1];
    }
};
