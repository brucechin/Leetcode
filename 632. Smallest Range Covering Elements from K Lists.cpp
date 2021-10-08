/*

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
Example 3:

Input: nums = [[10,10],[11,11]]
Output: [10,11]
Example 4:

Input: nums = [[10],[11]]
Output: [10,11]
Example 5:

Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.


*/
/*
Firstly we merge k groups to one group, each number recoard it's group, eg:

[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]

after merged we got：
[(0, 1), (4, 0), (5, 2), (9, 1), (10, 0), (12, 1), (15, 0), (18, 2), (20, 1), (22, 2), (24, 0), (26, 0), (30, 2)]

and see only group, it's
[1, 0, 2, 1, 0, 1, 0, 2, 1, 2, 0, 0, 2]

we can slide window by group when current groups satifies condition and recoard min range.

[1 0 2] 2 1 0 1 0 2 1 2 0 0 2    [0, 5]
1 [0 2 1] 1 0 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0] 0 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0 1] 1 0 2 1 2 0 0 2    [0, 5]
1 0 [2 1 0 1 0] 0 2 1 2 0 0 2    [0, 5]
1 0 2 1 0 [1 0 2] 2 1 2 0 0 2    [0, 5]
1 0 2 1 0 1 [0 2 1] 1 2 0 0 2    [0, 5]
1 0 2 1 0 1 [0 2 1 2] 2 0 0 2    [0, 5]
1 0 2 1 0 1 0 2 [1 2 0] 0 0 2    [20, 24]
1 0 2 1 0 1 0 2 [1 2 0 0] 0 2    [20, 24]
1 0 2 1 0 1 0 2 [1 2 0 0 2] 2    [20, 24]
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); ++j) {
            if (! count[ordered[j].second]++) ++k;
            if (k == nums.size()) { 
                while (count[ordered[i].second] > 1) --count[ordered[i++].second]; // minialize range
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};
