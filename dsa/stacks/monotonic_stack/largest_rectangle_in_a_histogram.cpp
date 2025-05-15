// Leetcode: 84. Largest Rectangle in Histogram

class Solution {
public:
    vector<int> getNSR(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n, n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> getNSL(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);

        int maxArea = 0;

        for(int i=0; i<n; i++){
            int height = heights[i];
            int width = NSR[i] - NSL[i] - 1;

            maxArea = max(maxArea, height*width);
        }

        return maxArea;
    }
};