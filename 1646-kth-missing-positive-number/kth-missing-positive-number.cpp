class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        long long n = arr.size();
        long long s = 0, e = n - 1, mid;

        while (s <= e) {
            mid = s + (e - s) / 2;
            if (arr[mid] - (mid + 1) >= k) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return s + k;
    }
};