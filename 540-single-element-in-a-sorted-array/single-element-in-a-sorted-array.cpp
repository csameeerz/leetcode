class Solution {
public:

    int findIndex(vector<int>& nums, int l, int h, int n) {
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) return nums[mid];
            else {
                int left, right;
                left = findIndex(nums, l, mid - 1, n);
                right = findIndex(nums, mid + 1, h, n);
                return left == -1 ? right : left;
            }
        }

        return -1;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int mid, n = nums.size(), l = 1, h = nums.size() - 2;

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        return findIndex(nums, l, h, n);
    }
};