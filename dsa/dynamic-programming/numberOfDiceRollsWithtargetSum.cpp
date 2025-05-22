// Leetcode: 1155. Number of Dice Rolls with Target Sum

// Recursion + Memo
class Solution {
    public:
        int dp[31][1001];
        int MOD = 1e9+7;
        int solve(int n, int k, int target){
            if(n==0){
                if(target == 0){
                    return 1;
                }
    
                return 0;
            }
    
            if(dp[n][target] != -1){
                return dp[n][target];
            }
    
            int ans = 0;
            for(int i=1; i<=k; i++){
                if(i > target){
                    break;
                }
                ans = (ans + solve(n-1, k, target-i)) % MOD;
            }
    
            return dp[n][target] = ans;
        }
        int numRollsToTarget(int n, int k, int target) {
            // Recursion + Memoization
            
            memset(dp, -1, sizeof(dp));
    
            return solve(n, k, target);
        }
    };


// Tabulation
class Solution {
    public:
        int numRollsToTarget(int n, int k, int target) {
            // Tabulation
            const int MOD = 1e9+7;
    
            vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
            dp[0][0] = 1;
    
            for(int i=1; i<=n; i++){
                for(int j=1; j<=target; j++){
                    for(int f=1; f<=k; f++){
                        if(j - f >= 0){
                            dp[i][j] = (dp[i][j] + dp[i-1][j - f]) % MOD;
                        }
                    }
                }
            }
    
            return dp[n][target];
    
        }
    };