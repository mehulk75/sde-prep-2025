/*
LeetCode: 680 - Valid Palindrome II
Category: Strings, Two Pointers
Difficulty: Easy-Medium

Problem:
Given a string s, return true if the string can be a palindrome after deleting at most one character.

Approach:
- Use two pointers from both ends.
- On mismatch, try skipping either left or right character and check if remaining substring is a palindrome.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(string s){
        int i=0; 
        int j=s.length()-1;

        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        int count = 1;

        while(i < j){
            if(s[i] != s[j]){ 
                return check(s.substr(i, j-i)) || check(s.substr(i+1, j-i));
            }
            i++;
            j--;
            
        }

        return true;
    }
};