/*

*/

/*Note:
  for clock-wise rotation, reverse the matrix, and swap the symmetry:
     1 2 3    7 8 9    7 4 1
     4 5 6 => 4 5 6 => 8 5 2 
     7 8 9    1 2 3    9 6 3 
*/
class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for (int i = 0; i< matrix.size();i++){
            for (int j = i+1; j < matrix[i].size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};
/* for counter-clock-wise rotation, reverse each row (reverse left rigth), then swap the symmetry.
   1 2 3     3 2 1     3 6 9
   4 5 6  => 6 5 4  => 2 5 8
   7 8 9     9 8 7     1 4 7
*/
class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void counterRotate(vector<vector<int>>& matrix) {
        for (auto& vi : matrix){
           reverse(vi.begin(),vi.end());
        }
        for (int i = 0; i< matrix.size();i++){
            for (int j = i+1; j < matrix[i].size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};
