/*Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

 

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
 

Note:

1 <= A.length <= 12
0 <= A[i] <= 1e9
*/

class Solution
{
public:
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int>> cand;
    int res = 0;
    int numSquarefulPerms(vector<int> &A)
    {
        for (int &a : A)
            count[a]++;
        //把整个数组两两之间如果可以形成perfect square的连线，然后dfs
        for (auto &i : count)
        {
            for (auto &j : count)
            {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y)
                    cand[x].insert(y);
            }
        }
        for (auto e : count)
            dfs(e.first, A.size() - 1);
        return res;
    }

    void dfs(int x, int left)
    {
        count[x]--;
        if (!left)
            res++;
        for (int y : cand[x])
            if (count[y] > 0)
                dfs(y, left - 1);
        count[x]++;
    }
};