class Solution {
public:

    vector<int> findIndex(vector<int>& nums, int l, int h, int target) {
        int mid;

        while (l <= h) {
            mid = l + (h - l) / 2;
            if (target< nums[mid]) {
                h = mid - 1;
            } else if (target> nums[mid]) {
                l = mid + 1;
            } else {
                vector<int> start = findIndex(nums, l, mid - 1, target);
                vector<int> end = findIndex(nums, mid + 1,  h, target);
                if (start[0] == -1 && end[0] == -1) return {mid, mid};
                else  if (start[0] == -1 && end[0] != -1) return {mid, end[1]};
                else  if (start[0] != -1 && end[0] != -1) return {start[0], end[1]};
                else return {start[0], mid};
            }
        }

        return {-1, -1};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return findIndex(nums, 0, nums.size() - 1, target);
    }
};