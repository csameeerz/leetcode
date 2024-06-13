class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long n = weights.size();
        long long s = 1, e = 1e8, mid, minv = 1e8 + 2;

        while (s <= e) {
            mid = s + (e - s) / 2;
            long long sum = 0, i = 0, newdays = days;
            while (i < n) {
                if (sum + weights[i] <= mid) {
                    sum += weights[i];
                } else {
                    newdays--;
                    sum = weights[i];
                    if (weights[i] > mid) {
                        newdays = 0;
                        break;
                    }
                }
                i++;
            }
            if (newdays > 0) {
                minv = min(minv, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return minv;
    }
};