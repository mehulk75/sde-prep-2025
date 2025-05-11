/*
LeetCode: 56 - Merge Intervals
Category: Arrays, Sorting
Difficulty: Medium

Problem:
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals.

Approach:
- Sort intervals by starting time.
- Track the current interval. If overlapping with next, merge.
- Else, push current to result and update.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] > intervals[i-1][1]){
                ans.push_back({intervals[i-1]});
            }
            else{
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
            }
        }
        int n = intervals.size();
        ans.push_back(intervals[n-1]);

        return ans;
    }
};