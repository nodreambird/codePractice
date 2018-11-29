/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

/* note:
   use BFS: for each island, check its surrounding to see if there are any '1'. Mark all the surrounding '1' to '0'
            they are all considered as 1 island. for each surrounding '1', check its surrounding again and
            mark them to '0' if possible. This is done by pushing all '1' surrounding island into a queue for process.
            note that it is possible the island pushed in the Queue multiple times by checking other islands,
            to save memory, you could mark it to '0' before push it into queue.
    time: O(n*m);            
*/
class Solution {
public:
    vector<pair<int,int>> direction = {{1,0},{0,1},{0,-1},{-1,0}};
    
    bool isValidLoc(vector<vector<char>>& grid, pair<int,int> loc){
        if (loc.first < 0 || loc.first >= grid.size() || loc.second < 0 || loc.second >= grid[0].size()) return false;
        
        if (grid[loc.first][loc.second] == '0') return false;
        return true;
    }
    void bfsIsland(vector<vector<char>>& grid, pair<int,int> loc){
        queue<pair<int,int>> locQ;
        locQ.push(loc);
       // grid[loc.first][loc.second] = '0';
        while(!locQ.empty()){
            pair<int,int> newLoc = locQ.front();
            locQ.pop();
            // do not mark the loc to '0' here since there could be duplicate island 
            //grid[newLoc.first][newLoc.second] = '0';
            for (auto dir:direction){
                pair<int,int> anotherLoc = make_pair(newLoc.first+dir.first, newLoc.second+dir.second);
                if(isValidLoc(grid,anotherLoc)){
                    // mark the island to '0' before push into the queue, so that it only gets pushed once.
                    grid[anotherLoc.first][anotherLoc.second] = '0';
                    locQ.push(anotherLoc);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == '1'){
                    pair<int,int> loc = make_pair(i,j);
                    bfsIsland(grid, loc);
                    count++;
                }
            }
        }
        return count;
    }
};

/*
DFS:
*/
class Solution {

public:
    
    void dfsIslands(vector<vector<char>>& grid, int i,int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ) return;
        if (grid[i][j] == '1'){
            grid[i][j] = '0';

            dfsIslands(grid, i+1,j);
            dfsIslands(grid, i-1,j);
            dfsIslands(grid, i,j+1);
            dfsIslands(grid, i,j-1);
        }        

    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == '1'){
                    //pair<int,int> loc = make_pair(i,j);
                    //bfsIsland(grid, loc);
                    dfsIslands(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
