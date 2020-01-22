/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

*/


class Solution {
public:
     string getPermutation(int n, int k) {
        vector<int> nums(n, 0);
        vector<long long> factorial(n + 1, 1);
        string pmt;
        
        // fill the number array and factorial for nth term
        for(int i = 1; i <= n; i++) {
            nums[i-1] = i;
            factorial[i] = i * factorial[i - 1];
        }
        
        // since the numbers are from 1.... n and it is 0-based indexed,
        // we make k also zero based
        k = k - 1;
        
        for(int i = 1; i <= n; i++) {
            // find the index in which the permutation we
            // are looking for lies
            int idx = k / factorial[n - i];
            pmt += to_string(nums[idx]);
            // now in next iteration, we need to look in the pmt
            // of remaining numbers without the starting sequence nums[idx]
            nums.erase(nums.begin() + idx);
            // update k, so as to account for not considering the previous permutations
            // idx * factorial[n - i]: this many pmt were removed from consideration
            k = k - (idx * factorial[n - i]);
        }
        return pmt;
    }
};