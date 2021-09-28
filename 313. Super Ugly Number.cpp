/*

A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 

Constraints:

1 <= n <= 106
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.

*/


/*

It is actually like how we merge k sorted list:

ugly number                       k sorted list
    1                            2     7    13   19     1 * [2,7,13,19]
    |                            |     |    |    |
    2                            4     14   26   38     2 * [2,7,13,19]
    |                            |     |    |    |
    4                            8     28   52   76     4 * [2,7,13,19]
    |                            |     |    |    |              
    7                            14    49   91   133    7 * [2,7,13,19]
    |                            |     |    |    |
    8                            16    56   ...   ...   8 * [2,7,13,19]
    |                            |     |    |     |
    .                            .     .     .    .
    .                            .     .     .    .
    .                            .     .     .    .
We can see that each prime number in primes[] form a sorted list, and now our job is to merge them and find the nth minimum.

Here we don't have the next pointer for each node to trace the next potential candidate. But as we can see in the graph, we can make use of the ugly number we have produced so far!

*/


//每一个丑陋数是之前的某个丑陋数再乘上primes里的某个prime得到的。
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1), idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); ++j) {
                if (dp[i] == dp[idx[j]] * primes[j]) {//may have duplicates.
                    ++idx[j]; //update the index
                }
            }
        }
        return dp.back();
    }
};


//this one uses min heap to reduce time complexity to O(nlogk)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 0);
        auto cmp = [&res, &primes](auto p1, auto p2) {
            return (long long)res[p1.first] * primes[p1.second] > (long long)res[p2.first] * primes[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < primes.size(); ++i) {
            pq.push({0, i});
        }
        
        res[0] = 1;
        int i = 1;
        while (i < n) {
            auto top = pq.top();
            pq.pop();
            
            int p = primes[top.second], idx = top.first;
            int num = res[idx] * p;
            
            //remove duplicate
            if (res[i-1] != num) {
                res[i] = num;
                i++;
            }
            
            pq.push({idx+1, top.second});
            
            
        }
        
        return res[n-1];
    }
};