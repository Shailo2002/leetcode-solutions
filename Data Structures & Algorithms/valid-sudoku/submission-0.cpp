class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;

        for (int i = 0; i < 9; i++) {
            int temp_arr[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int temp_num = board[i][j] - '0';
                if (temp_arr[temp_num] == 1) {
                    return false;
                } else {
                    temp_arr[temp_num]++;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            int temp_arr[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                int temp_num = board[j][i] - '0';

                if (temp_arr[temp_num] == 1) {
                    return false;
                } else {
                    temp_arr[temp_num]++;
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                cout << i << " " << j << endl;
                int temp_arr[10] = {0};

                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') {
                            continue;
                        }
                        int temp_num = board[k][l] - '0';

                        if (temp_arr[temp_num] == 1) {
                            return false;
                        } else {
                            temp_arr[temp_num]++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
