/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

*/


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), INT_MAX);
        res[0] = 0;
        int size = nums.size();
        for(int i = 0; i < size;){      
            int can_reach = min(i + nums[i], size - 1);
            int k = i + 1;
            
            while (k<size-1 && k+nums[k] <= i+nums[i]) {
				k++;//pass some points that in current range
			}
			int nxt_i = k;
            
            while(k <= can_reach){
                res[k] = min(res[i] + 1, res[k]);
                k++;
            }
            
            i = nxt_i;
            
        }
        return res[size-1];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        
        int cur = 0;
        int reach = 0;
        int dist = 1;
        while(cur+nums[cur]<n-1) {
            dist++;
            int max_reach=0, index=-1;
            for(int i=reach+1; i<=cur+nums[cur]; i++) {
                if(i+nums[i]>max_reach)
                    max_reach = i+nums[i], index = i;
            }
            reach = cur+nums[cur];
            cur = index;
        }
        return dist;
    }
};