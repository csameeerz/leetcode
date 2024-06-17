class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), i;
        string res = "";

        for (i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                break;
            }
        }

        if (i == -1) return res;
        else {
            for (int j = 0; j <= i; j++) {
                res.push_back(num[j]);
            }
        }

        return res;
    }
};