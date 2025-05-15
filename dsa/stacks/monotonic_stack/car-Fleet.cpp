// Leetcode: 853. Car Fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++){
            vec.push_back({position[i], speed[i]});
        }

        sort(vec.begin(), vec.end());

        stack<pair<int, double>> st;

        for(int i=n-1; i>=0; i--){
            double time = (double)(target - vec[i].first) / vec[i].second;
            if(st.empty() || st.top().second < time){
                st.push({vec[i].second, time});
                cout<<time<<" ";
                cout<<vec[i].second<<endl;
            }
        }

        return st.size();


    }
};