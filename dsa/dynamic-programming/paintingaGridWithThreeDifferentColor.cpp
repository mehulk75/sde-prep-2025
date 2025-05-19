// Leetcode: 1931. Painting a Grid With Three Different Color

class Solution {
    public:
        int MOD = 1e9+7;
        int dp[1001][80];
        void generateStates(int l, int m, vector<string>& states, string temp, char prev){
    
            if(l == m){
                states.push_back(temp);
                return;
            }
    
            for(char ch : {'R', 'G', 'B'}){
                if(prev != ch){
                    generateStates(l+1, m, states, temp + ch, ch);
                }
            }
        }
        int solve(int columns, int prev, int l, unordered_map<int, vector<int>>& mp){
    
            if(columns == 0){
                return 1;
            }
    
            if(prev != -1 && dp[columns][prev] != -1){
                return dp[columns][prev];
            }
    
            int ans = 0;
    
            if( prev == -1){
                for(int i=0; i<l; i++){
                    ans = (ans + solve(columns-1, i, l, mp)) % MOD;
                }
            }
            else{
                for(int i : mp[prev]){
                    ans = (ans + solve(columns-1, i, l, mp)) % MOD;
                }
            }
    
            if(prev != -1){
                dp[columns][prev] = ans;
            }
            return ans;
        }
        int colorTheGrid(int m, int n) {
    
            vector<string> states;
            generateStates(0, m, states, "", 'X');
    
            int l = states.size();
            unordered_map<int, vector<int>> mp;
    
            for(int i = 0; i < l; i++) {
                for(int j = i + 1; j < l; j++) {
                    bool isDifferent = true;
                    for(int k = 0; k < m; k++) {
                        if(states[i][k] == states[j][k]) {
                            isDifferent = false;
                            break;
                        }
                    }
                    if(isDifferent){
                        mp[i].push_back(j);
                        mp[j].push_back(i);
                    }
                }
            }
    
            memset(dp, -1, sizeof(dp));
            return solve(n, -1, l, mp);
        }
    };