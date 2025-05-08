// # Minimum Window Substring

// **LeetCode:** [76](https://leetcode.com/problems/minimum-window-substring/)  
// **Category:** Strings, Sliding Window  
// **Difficulty:** Hard

// ## 🧠 Problem Statement:
// Given two strings `s` and `t`, return the minimum window in `s` which will contain all the characters in `t`.  
// If there is no such window in `s` that covers all characters in `t`, return the empty string `""`.

// ---

// ## ✅ Approach (Sliding Window + Hash Map):

// 1. Create a frequency map of characters in `t`.
// 2. Use two pointers `i` and `j` to maintain a sliding window on `s`.
// 3. Decrease the count of characters in the map as you expand the window (`j` pointer).
// 4. When all required characters are found (`countRequired == 0`), try shrinking the window from the left (`i` pointer) while still keeping all required characters.
// 5. Track the smallest valid window and return its substring.

// ---

// ## 🧮 Time & Space Complexity:
// - **Time Complexity:** O(n), where n = length of `s`
// - **Space Complexity:** O(1), because the character set is constant (ASCII size map)

// ---

// ## 💡 Key Insights:
// - You must maintain the **exact count** of characters from `t` in the current window.
// - The condition `mp[s[i]] == 0` helps detect when you're about to remove a crucial character.
// - `min_i` and `min_j` track the best window found so far.

// ---

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;

        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }

        int countRequired = t.length();

        int min_i = -1;
        int min_j = 100001;

        int i=0;
        int j=0;

        while(j<s.length()){

            if(mp.find(s[j]) != mp.end() && mp[s[j]] > 0){
                countRequired--;
            }
            mp[s[j]]--;

            while(countRequired == 0){
                if(j-i+1 < min_j-min_i+1){
                    min_i = i;
                    min_j = j;
                }

                if(mp.find(s[i]) != mp.end() && mp[s[i]] == 0){
                    countRequired++;
                }
                mp[s[i]]++;
                i++;
            }

            j++;
        }

        if(min_j == 100001 && min_i == -1){
            return "";
        }

        return s.substr(min_i, min_j-min_i+1);
    }
};