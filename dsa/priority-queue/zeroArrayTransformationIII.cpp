// Leetcode: 3362. Zero Array Transformation III
// Link: https://leetcode.com/problems/zero-array-transformation-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
            sort(queries.begin(), queries.end());
    
            int n = nums.size();
            vector<int> diff(n, 0);
    
            priority_queue<int> pq;
    
            int j = 0;
            int usedCount = 0;
    
            for(int i=0; i<n; i++){
    
                if(i>0){
                    diff[i] += diff[i-1];
                }
    
                nums[i] += diff[i];
                cout<<nums[i]<<endl;
    
                if(nums[i] <= 0){
                    continue;
                }
    
                while (j < queries.size() && queries[j][0] <= i) {
                    if (queries[j][1] >= i) {
                        pq.push(queries[j][1]);
                    }
                    j++;
                }
    
                while( nums[i] > 0 && !pq.empty()){
                    int r = pq.top();
                    pq.pop();
                    if(r < i){
                        break;
                    }
                    nums[i]--;
                    diff[i] += -1;
                    if(r != n-1){
                        diff[r+1] += 1;
                    }
    
                    usedCount++;
                }
    
                if(nums[i] > 0){
                    return -1;
                }
            }
    
            cout<<usedCount<<endl;
            return queries.size() - usedCount;
        }
    };