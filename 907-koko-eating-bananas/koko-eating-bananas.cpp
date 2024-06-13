class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        long long n = piles.size();
        long long s = 1, e = 1e9, mid, minv = INT_MAX;

        while (s <= e) {
            mid = s + (e - s) / 2;
            long long count = 0;
            for (auto x : piles) {
                count += x % mid != 0 ? (x / mid) + 1 : (x / mid);
            }
            if (count <= h) {
                minv = min(minv, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return minv;
    }
};