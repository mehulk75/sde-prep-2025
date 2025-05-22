//Leetcode: 62: Unique Paths

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Combinatorics
            // we have (m-1) down moves (D) and (n-1) right moves (R) and we have to arrange them only;
            // ans = (m-1 + n-1)!/ (m-1)!*(n-1)!
            // N = (m-1 + n -1) and K = (m-1) then ans = N!/K!*(N-K)!
            // ans = N*(N-1)*(N-2)*....*(N-K+1)/1*2*3*...K
    
            long long ans = 1;
    
            for(int i=1; i<=m-1; i++){
                ans = ans * (n-1 + i)/i;
            }
    
            return ans;
        }
    };