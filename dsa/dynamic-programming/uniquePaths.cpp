// Leetcode: 62. Unique Paths

// Top-Down
class Solution {
    public:
        vector<vector<int>> directions{ {0, 1}, {1, 0}};
        int dp[101][101];
        int dfs(int m, int n, int i, int j){
            if(i==m-1 && j==n-1){
                return 1;
            }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
    
            int total = 0;
    
            for( auto & dir: directions){
                int x = i + dir[0];
                int y = j + dir[1];
    
                if(x<m && y<n){
                    total += dfs(m, n, x, y);
                }
            }
            return dp[i][j] = total;
        }
        int uniquePaths(int m, int n) {
            memset(dp, -1, sizeof(dp));
            return dfs(m, n, 0, 0);
        }
    };


// Bottoms Up
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Bottom's Up
            vector<vector<int>> dp(m, vector<int>(n, 1));
    
            for(int i=1; i<m; i++){
                for(int j=1; j<n; j++){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
    
            return dp[m-1][n-1];
        }
    };