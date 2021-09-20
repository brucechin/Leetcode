/*

 copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000



It take 2 ops to double, 3 ops to triple, ...
if n % 2 == 0, then f(n) = f(n/2) + 2
if n % 3 == 0, then f(n) = f(n/3) + 3
2 * 2 = 2 + 2; 2 * 3 > 2 + 3; 4 * 4 > 4 + 4; so it is always better to divide whenever possible.
now it became a problem for finding all possible factors;

*/

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};