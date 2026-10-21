class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int, string>> v;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            v.push_back({i, temp});
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });

        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                ans.push_back({strs[v[i].first]});
            } else if (v[i].second == v[i - 1].second) {
                ans.back().push_back(strs[v[i].first]);
            } else {
                ans.push_back({strs[v[i].first]});
            }
        }
        return ans;
    }
};
