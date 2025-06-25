class Solution {
public:
    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0; //total count rakhta hai un sab pairs ka (i, j) jinke product: nums1[i] * nums2[j] <= mid

        int n = nums2.size();

        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == 0) {
                if (mid >= 0)
                    count += n;
            }
            else if (nums1[i] > 0) {
                // Binary search for rightmost j where nums1[i] * nums2[j] <= mid
                int l = 0, r = n - 1, m = -1;
                while (l <= r) {
                    int midIndex = l + (r - l) / 2;
                    if ((long long)nums1[i] * nums2[midIndex] <= mid) {
                        m = midIndex;
                        l = midIndex + 1;
                    } else {
                        r = midIndex - 1;
                    }
                }
                count += (m + 1);
            } else {
                // nums1[i] < 0
                // Binary search for leftmost j where nums1[i] * nums2[j] <= mid
                int l = 0, r = n - 1, m = n;
                while (l <= r) {
                    int midIndex = l + (r - l) / 2;
                    if ((long long)nums1[i] * nums2[midIndex] <= mid) {
                        m = midIndex;
                        r = midIndex - 1;
                    } else {
                        l = midIndex + 1;
                    }
                }
                count += (n - m);
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long cnt = countLessEqual(nums1, nums2, mid);

            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
/*
nums1 = [-2, 0, 1]
nums2 = [-3, 4]
mid = 0
Aapko yeh dekhna hai ki kitne combinations hain jinka product <= 0 hai:
-2 * -3 = 6 ❌
-2 * 4 = -8 ✅
0 * -3 = 0 ✅
0 * 4 = 0 ✅
1 * -3 = -3 ✅
1 * 4 = 4 ❌
👉 Valid pairs (<= 0): (-2,4), (0,-3), (0,4), (1,-3)
👉 count = 4


*/