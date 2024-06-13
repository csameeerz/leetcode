class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid, n = nums.size(), l = 1, h = nums.size() - 2;

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        while (l <= h) {
            mid = l + (h - l) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
            else if (nums[mid - 1] < nums[mid]) l = mid + 1;
            else h = mid - 1;
        }

        return -1;
    }
};