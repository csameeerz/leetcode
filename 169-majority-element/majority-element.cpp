class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int c = 1, maxv = nums[0], maxc = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                c++;
            } else {
                if (c > maxc) {
                    maxv = nums[i - 1];
                    maxc = c;
                }
                c = 1;
            }
            
        }
        if (c > maxc) {
            maxv = nums[n - 1];
            maxc = c;
        }

        return maxv;
    }
};