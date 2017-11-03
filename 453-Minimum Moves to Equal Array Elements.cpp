//n-1个加相当于只减一个，达到相同用多少步
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX,size= nums.size(),moves=0;
        for(int i=0; i<size; i++){
            min = min < nums[i] ? min : nums[i];
        }
        for(int j=0; j<size; j++){
            moves += nums[j] - min;
        }
        return moves;
    }
};
