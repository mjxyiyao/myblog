//Leetcode 51 N-queens
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        int dp[n];
        vector<string> temp(n, string (n, '.'));
        
        helper(res, temp, dp, 0, n);
        return res;
         
    }
private:
    void helper(vector<vector<string>> &res, vector<string> &temp, int dp[], int row, int n){
        if (row == n) {
            res.push_back(temp);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (valid(dp, row, col)){
                dp[row] = col;
                temp[row][col] = 'Q';
                helper(res, temp, dp, row+1, n);
                temp[row][col] = '.';
            }
        }
    }
    
    bool valid(int dp[], int row, int col){
        for (int i = 0; i < row; i++){
            if(dp[i]==col || abs(row-i)==abs(dp[i]-col)) {
                return false;
            }
        }
        return true;
    }
};
