class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int s = 0, e = m, mid1, mid2, midSize = (m + n + 1) / 2, totalSize = m + n;

        while (s <= e) {
            mid1 = s + (e - s) / 2;
            mid2 = midSize - mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 != 0) l1 = nums1[mid1 - 1];
            if (mid2 != 0) l2 = nums2[mid2 - 1];
            if (mid1 != m) r1 = nums1[mid1];
            if (mid2 != n) r2 = nums2[mid2];

            if (l1 > r2) {
                e = mid1 - 1;
            } else if (l2 > r1) {
                s = mid1 + 1;
            } else {
                return (totalSize % 2 == 0) ? (double) ((double) (max(l1, l2) + (double) min(r1, r2)) / 2) : (double) max(l1, l2);
            }
        }

        return -1;
    }
};