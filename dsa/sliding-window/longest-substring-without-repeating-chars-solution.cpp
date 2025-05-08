// # Longest Substring Without Repeating Characters

// **LeetCode:** [3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
// **Category:** Strings, Sliding Window  
// **Difficulty:** Medium

// ## Approach:
// - Use sliding window with a hashmap to track last seen indices.
// - Adjust left pointer to ensure all characters are unique.

// ## Complexity:
// - Time: O(n)
// - Space: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i=0;
        int j=0;
        int n =s.length();

        int ans = 0;

        while(j<n){
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]]+1;
            }
            else{
                ans = max(ans, j-i+1);
            }

            mp[s[j]] = j;
            j++;
        }

        return ans;
    }
};