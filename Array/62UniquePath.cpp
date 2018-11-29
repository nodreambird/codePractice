/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/* note:
   1. since a robot can only move down or right, for any point p[i,j], it could only come from
      - top: p[i-1,j]
      - left: p[i,j-1]
     therefore p[i,j] = p[i-1,j] + p[i,j-1];
     
     This methd takes O(n^2) times, and space O(m * n)
*/
     int uniquePaths(int m, int n) {
         vector<vector<int>>Path(m,vector<int>(n,1));
         // notice here we initialize i,j to 1. this is because for [0,j] [i,0] we have already init to 1.
         // this avoids the edge case where [0,j] [i,0] only has one way to that point.(no left or no up)
         for (int i = 1; i < n; i++)
            for (int j = 1; j<n; j++)
               path[i][j] = p[i-1][j] + p[i][j-1];

         return path[m-1][n-1];

     }
/*
   2. optimize the previous code:
      - for each point, we only care about its up and left point, there is no need to keep track of all matrix,
        but only the left column and current column. Therefore we could use vector cur and pre for each.
*/
        int uniquePaths(int m, int n) {
           // do this to ensure min space O(min(m,n));
           if (m > n) return uniquePaths(n,m);
           // since m is smaller, the vector size could be smaller.
           vector<int> cur (m,1);
           vector<int> pre (m,1);
           
            // we are tracking column, therefore n loop outside of m loop:
            // keep track each column value, and its left column value for calculation.
            // pre[i] is the left value, same row, previous column
            // cur[i-1] is the up value, same column.
            //
           for ( j = 1; j < n; j++){
              for (i = 1; i < m; i++){
                  cur[i] = cur[i-1] + pre[i]
              }
              // remember to put current column to pre
              // every time we move to a new column, current col becomes pre col.
              // although we do a swap, but the main purpose is to put cur col values to pre
              // cur vector is always being updated 
              pre.swap(cur);
           }
           // in the end cur column is swaped to pre, therefore return pre.
           return pre[m-1];
        }
 /*
   3. furthur optimize
      - method 2 we copied cur col values to pre to keep track left col value.
        in fact we do not need to do this because cur still has this value before it is changed.
*/
      int uniquePaths(int m, int n){
         if ( m > n) return uniquePaths(n, m);

         vector<int> cur (m,1);
         for (j = 1; j < n; j ++)
            for (i = 1; i < m; i++)
               cur[i] += cur[i-1];

         return cur[m-1];
       }
