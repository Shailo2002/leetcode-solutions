class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Count frequencies
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Create frequency buckets
        vector<vector<int>> bucket(n + 1);

        for (auto p : freq) {
            bucket[p.second].push_back(p.first);
        }

        // Step 3: Collect top K elements
        vector<int> ans;

        for (int i = n; i >= 1; i--) {
            for (int x : bucket[i]) {
                ans.push_back(x);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};