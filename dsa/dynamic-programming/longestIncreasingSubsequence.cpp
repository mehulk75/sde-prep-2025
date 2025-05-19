// Leetcode: 1143. Longest Increasing Subsequence

class Solution {
    public:
        int n1;
        int n2;
        int dp[1000][1000];
        int solve(int i, int j, string& text1, string& text2){
            if(i == n1 || j == n2){
                return 0;
            }
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
    
            if(text1[i] == text2[j]){
                return dp[i][j] = 1 + solve(i+1, j+1, text1, text2);
            }
    
            int skip1 = solve(i+1, j, text1, text2);
            int skip2 = solve(i, j+1, text1, text2);
    
            return dp[i][j] = max(skip1, skip2);
        }
        int longestCommonSubsequence(string text1, string text2) {
            n1 = text1.size();
            n2 = text2.size();
            memset(dp, -1, sizeof(dp));
            return solve(0, 0, text1, text2);
        }
    };