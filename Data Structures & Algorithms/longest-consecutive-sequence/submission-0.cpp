class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int num : st) {

            if (!st.count(num-1)) {

                int current = num;
                int length = 1;

                // 2. Count the consecutive elements
                while (st.count(current+1)) {

                    current ++;
                    length++;

                }

                ans = max(length, ans);
                length =1;
            }
        }

        return ans;
    }
};