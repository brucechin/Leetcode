class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int MAX = 1,tmp_max = 1,size = nums.size();
        for(int i=1; i<size; i++){

            if(nums[i] > nums[i-1]){
                tmp_max++;
            }else{
                MAX = max(MAX,tmp_max);
                tmp_max = 1;
            }
        }
        MAX = max(MAX,tmp_max);
        return MAX;
    }
};
