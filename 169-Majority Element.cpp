class Solution {
public:
    int majorityElement(vector<int>& num) {
        int major=num[0], count = 1,size=num.size();
        for(int i=1; i<size;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;

    }
};
