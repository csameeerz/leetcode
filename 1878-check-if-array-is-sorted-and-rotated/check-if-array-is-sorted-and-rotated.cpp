class Solution {
public:
    bool check(vector<int>& nums) {
        int index = -1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) return true;

        for (int j = index + 1; j < index + n; j++) {
            cout<<j % n;
            if (nums[j % n] < nums[(j - 1) % n]) {
                return false;
            }
        }

        return true;
    }
};