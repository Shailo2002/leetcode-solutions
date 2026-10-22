class Solution {
   public:
    string encode(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs.size(); i++) {
            result += to_string(strs[i].length()) + "#" + strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string before = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                int temp = stoi(before);
                string after = s.substr(i+1,temp);
                ans.push_back(after);
                i += temp;
                before="";
                after="";
            } else {
                before += s[i];
            }
        }
        return ans;
    }
};
