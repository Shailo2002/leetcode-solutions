class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> ans;

        for (int x : nums) {
            freq[x]++;
        }

        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto a, auto b) { return a.second > b.second; });

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
