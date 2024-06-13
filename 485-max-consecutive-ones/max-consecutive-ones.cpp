class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxv = 0, currv = 0, i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == 1) {
                currv++;
            } else {
                maxv = max(maxv, currv);
                currv = 0;
            }
            i++;
        }
        maxv = max(maxv, currv);
        
        return maxv;
    }
};