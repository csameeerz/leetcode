class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long s = 1, e = 1e9, mid, minv = 1e9 + 2, mv;

        while (s <= e) {
            mid = s + (e - s) / 2;
            mv = m;
            long long count = 0, i = 0;
            while (i < n) {
                if (bloomDay[i] <= mid) {
                    count++;
                    if (count == k) {
                        mv--;
                        count = 0;
                    }
                }
                else {
                    count = 0;
                }
                i++;
            }
            if (mv <= 0) {
                minv = min(minv, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return minv == 1e9 + 2 ? -1 : minv;
    }
};