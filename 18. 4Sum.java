/*

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
    Arrays.sort(num);
    
    Map<Integer, List<int[]>> twoSumMap = new HashMap<>(); // for holding visited pair sums. All pairs with the same pair sum are grouped together
    Set<List<Integer>> res = new HashSet<>();  // for holding the results
    
    for (int i = 0; i < num.length; i++) {
    	// get rid of repeated pair sums
        if (i > 1 && num[i] == num[i - 2]) continue;
    	
        for (int j = i + 1; j < num.length; j++) {
            // get rid of repeated pair sums
            if (j > i + 2 && num[j] == num[j - 2]) continue;

            // for each pair sum, check if the pair sum that is needed to get the target has been visited.            	
            if (twoSumMap.containsKey(target - (num[i] + num[j]))) {   
                // if so, get all the pairs that contribute to this visited pair sum.
        	List<int[]> ls = twoSumMap.get(target - (num[i] + num[j]));
        		
        	for (int[] pair : ls) {
        	    // we have two pairs: one is indicated as (pair[0], pair[1]), the other is (i, j).
        	    // we first need to check if they are overlapping with each other.
        	    int m1 = Math.min(pair[0], i);  // m1 will always be the smallest index
                    int m2 = Math.min(pair[1], j);  // m2 will be one of the middle two indices
                    int m3 = Math.max(pair[0], i);  // m3 will be one of the middle two indices
                    int m4 = Math.max(pair[1], j);  // m4 will always be the largest index
                    
                    if (m1 == m3 || m1 == m4 || m2 == m3 || m2 == m4) continue;  // two pairs are overlapping, so just ignore this case
 		    
 		    res.add(Arrays.asList(num[m1], num[Math.min(m2, m3)], num[Math.max(m2, m3)], num[m4]));  // else record the result
        	}
            }
            
            // mark that we have visited current pair and add it to the corrsponding pair sum group.
            // here we've encoded the pair indices i and j into an integer array of length 2.
            twoSumMap.computeIfAbsent(num[i] + num[j], key -> new ArrayList<>()).add(new int[] {i, j});
        }
    }
    
    return new ArrayList<List<Integer>>(res);
}
}
