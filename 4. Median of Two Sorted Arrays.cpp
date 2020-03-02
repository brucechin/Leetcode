/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2)
            return findMedianSortedArrays(nums2, nums1); // Make sure A2 is the shorter one.

        int lo = 0, hi = N2 * 2;
        while (lo <= hi)
        {
            int mid2 = (lo + hi) / 2;  // Try Cut 2
            int mid1 = N1 + N2 - mid2; // Calculate Cut 1 accordingly

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2]; // Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 + 1; // A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1)
                hi = mid2 - 1; // A2's lower half too big; need to move C2 left.
            else
                return (max(L1, L2) + min(R1, R2)) / 2; // Otherwise, that's the right cut.
        }
        return -1;
    }
};

//本题可以generalize成在两个sorted array种find kth的问题
double findKth(int a[], int m, int b[], int n, int k) {
    if (m > n)  return findKth(b, n, a, m, k);
    if (m == 0) return b[k - 1];
    if (k == 1) return min(a[0], b[0]);
     
    int pa = min(k/2, m);
    int pb = k - pa;
    if (a[pa-1] < b[pb-1])  return findKth(a+pa, m-pa, b, n, k-pa);
    else if (a[pa-1] > b[pb-1])  return findKth(a, m, b+pb, n-pb, k-pb);
    else    return a[pa-1];
}
 
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mid = (nums1Size + nums2Size) >> 1;
    if ((nums1Size + nums2Size) & 0x01) {
        return findKth(nums1, nums1Size, nums2, nums2Size, mid+1);
    }
    else {
        return (findKth(nums1, nums1Size, nums2, nums2Size, mid)
                + findKth(nums1, nums1Size, nums2, nums2Size, mid + 1)) / 2.0;
    }
}