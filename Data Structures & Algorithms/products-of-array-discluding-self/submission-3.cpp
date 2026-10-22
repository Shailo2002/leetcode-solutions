class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        vector<int> ans;
        int total_num = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                total_num *= nums[i];
            } else {
                zero++;
            }
            if(zero >= 2){
                break;
            }
        }
        if (zero >= 2) {
            return vector<int>(n, 0);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans.push_back(total_num);
            } else {
                if (zero == 1) {
                    ans.push_back(0);

                } else {
                    int temp = total_num / nums[i];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
