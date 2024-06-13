class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorv = 0;
        for (auto x: nums) {
            xorv = xorv ^ x;
        }

        return xorv;
    }
};