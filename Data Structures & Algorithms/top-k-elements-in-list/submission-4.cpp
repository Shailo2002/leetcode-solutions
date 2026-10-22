class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<vector<int>> bucket(n+1);
        for (auto p : freq) {
            bucket[p.second].push_back(p.first);
        }

        for(int i=bucket.size()-1; i>=0; i--){
            for(int j=0; j<bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                if(ans.size() >= k){
                    return ans;
                }
            }
        }

        return ans;
    }
};