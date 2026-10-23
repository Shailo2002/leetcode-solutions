class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int num : st) {
            if (num == INT_MIN || !st.count(num - 1)) {
                int current = num;
                int length = 1;

                while (current != INT_MAX && st.count(current + 1)) {
                    current++;
                    length++;
                }

                ans = max(length, ans);
                length = 1;
            }
        }

        return ans;
    }
};