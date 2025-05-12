// Leetcode 134. Gas Station 
// Approach : if the sum of (gas[i]-cost[i]) < 0 then -1 else
//             we have to move anticlockwise we find from  right to left where we can start from that if maxm point

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int ans = n-1;
        int maxm = INT_MIN;
        int temp = 0;

        for(int i=n-1; i>=0; i--){
            temp = temp + gas[i] - cost[i];

            if(maxm <= temp){
                maxm = temp;
                ans = i;
            }
        }

        if(temp < 0){
            return -1;
        }

        return ans;
    }
};