/*

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000

*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, n = A.size(), M = 1e9 + 7;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            int cur = (i == n) ? 0 : A[i];
            while (!st.empty() && cur < A[st.top()]) {
                int idx = st.top(); st.pop();
                int left = idx - (st.empty() ? -1 : st.top());
                int right = i - idx;
                res = (res + A[idx] * left * right) % M;
            }
            st.push(i);
        }
        return res;
    }
};