class Solution {
public:
    string reverseWords(string s) {
        string res = "", curr = "";
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                curr.push_back(s[i]);
            } else {
                reverse(curr.begin(), curr.end());
                if (res.size() && curr.size()) res = res + ' ';
                if (curr.size()) res = res + curr;
                curr = "";
            }
        }
        reverse(curr.begin(), curr.end());
        if (res.size() && curr.size()) res = res + ' ';
        if (curr.size()) res = res + curr;

        return res;
    }
};