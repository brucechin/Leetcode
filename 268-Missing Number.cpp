class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size(),result = 0;
        for(int i=0; i<size ;i++){
            result += nums[i];
        }
        result = size * (size + 1) / 2 - result;
        return result;
    }
};
