class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> A;

        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                if (A[i].first + A[j].first == target) {
                    ans.push_back(min(A[i].second, A[j].second));
                    ans.push_back(max(A[i].second, A[j].second));
                    return ans;
                }
                if (A[i].first + A[j].first >= target) {
                    break;
                }
            }
        }
        return ans;
    }
};
