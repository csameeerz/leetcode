class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long n = nums.size();
        long long s = 1, e = 1e6, mid, minv = 1e6 + 2, minsum = -1;

        while (s <= e) {
            mid = s + (e - s) / 2;
            long long sum = 0;
            for (auto x : nums) {
                sum += (x % mid != 0) ? (x / mid) + 1 : (x / mid);
            }
            if (sum <= threshold) {
                if (sum > minsum) {
                    minsum = sum;
                    minv = mid;
                } else if (sum == minsum) {
                    minv = min(minv, mid);
                }
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return minv;
    }
};