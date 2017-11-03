//一个vector转set,一个set记录重叠的结果，因为重复的数字只用记录一次
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> tmp,re;
        vector<int> result;
        int size = nums2.size(),s = nums1.size();
        for(int i = 0; i < size; i++){
            tmp.insert(nums2[i]);
        }
        for(int j =0; j < s; j++){
            int b =nums1[j];
            if(tmp.find(b) != tmp.end())
                re.insert(b);
        }
        set<int>::iterator it = re.begin();
        for(; it != re.end(); it++){
            result.push_back(*it);
        }
        return result;
    }
};
