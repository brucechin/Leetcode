/*

We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].


*/

/*

可以先排序再找，或者先计数再找

*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;
        map<int,int> count;
        for(int num:nums){
            if(count.find(num) == count.end()){
                count[num] = 1;
            }else{
                count[num]++;
            }
        }
        map<int,int>::iterator it = count.begin();
        for(;it != count.end(); it++){
            int tmp = it->first;
            if(count.find(tmp + 1) != count.end()){
                result = max(result,count[tmp] + count[tmp+1]);
            }
        }
        return result;
    }
};
