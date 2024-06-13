class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), currv = 0, maxv = INT_MIN;

        for (int i = 0; i < n; i++) {
            currv += nums[i];
            if (currv > maxv) {
                maxv = currv;
            }
            if (currv < 0) {
                currv = 0;
            }
        }

        return maxv;
    }
};